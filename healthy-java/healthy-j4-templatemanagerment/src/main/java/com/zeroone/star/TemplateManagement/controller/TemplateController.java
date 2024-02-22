package com.zeroone.star.TemplateManagement.controller;

import com.zeroone.star.TemplateManagement.service.templateService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j4.dto.TemplateDto;
import com.zeroone.star.project.j4.template.TemplateApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@Api(tags = "模板管理接口")
@RequestMapping("/template")
public class TemplateController implements TemplateApis {


    @Autowired
    private templateService templateService;

    @Autowired
    private FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @PostMapping("add-template")
    @ApiOperation("新增模板")
    @Override
    public JsonVO<ResultStatus> addTemplate(@RequestBody TemplateDto templateDto) {
        boolean save = templateService.save(templateDto);
        if (save)return new JsonVO<>(200, "ok", ResultStatus.SUCCESS);
        else  return JsonVO.fail(null);
    }

    @ApiOperation("获取模板详情")
    @GetMapping("query-term-detail/{templateId}")
    @Override
    public JsonVO<TemplateDto> queryTermDetail(@PathVariable("templateId") String templateId) throws Exception {
        return JsonVO.success(templateService.getPortfolioItemById(templateId));
    }
    @ApiOperation("删除模板")
    @PostMapping("delete")
    @Override
    public JsonVO<ResultStatus> deleteTemplate(@RequestBody List<String> terplateIds) {
        List<TemplateDto> templateDtos = templateService.listByIds(terplateIds);
        List<String> paths = templateDtos.stream().map(templateDto -> templateDto.getContent()).collect(Collectors.toList());
        paths.stream().forEach(path->
        {
            String group = path.substring(0,path.lastIndexOf("|"));
            String id = path.substring(path.lastIndexOf("|")+1);
            try {
                int res = dfs.deleteFile(FastDfsFileInfo.builder().group(group).storageId(id).build());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        });
        boolean result= templateService.removeByIds(terplateIds);
        if (result)return new JsonVO<>(200, "ok", ResultStatus.SUCCESS);
        else  return JsonVO.fail(null);

    }

    @Override
    @PostMapping("update")
    @ApiOperation("更新模板")
    public JsonVO<ResultStatus> updateTemplate(@RequestBody TemplateDto templateDto) {
        boolean result = templateService.updateById(templateDto);
        if (result)return new JsonVO<>(200, "ok", ResultStatus.SUCCESS);
        else  return JsonVO.fail(null);
    }

    @PostMapping("upload")
    @ApiOperation("上传模板文件")
    public JsonVO<String> uploadFile(MultipartFile file) throws Exception {
        // 获取上传文件的后缀名
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);

        FastDfsFileInfo f = dfs.uploadFile(file.getBytes(), suffix);

        if (f != null) {
            return JsonVO.success(f.getGroup() + "|" + f.getStorageId());
        } else {
            return JsonVO.fail(null);
        }
    }

    @GetMapping(value = "download")
    @ApiOperation(value = "下载")
    public ResponseEntity<byte[]> downloadImage(String templateId) throws Exception {
        TemplateDto templateDto = templateService.getById(templateId);
        String path = templateDto.getContent();
        String group = path.substring(0,path.lastIndexOf("|"));
        String storageid = path.substring(path.lastIndexOf("|")+1);
        // 下载文件
        byte[] fc = dfs.downloadFile(FastDfsFileInfo.builder().storageId(storageid).group(group).build());
        // 响应给前端
        HttpHeaders headers = new HttpHeaders();
        String filename = templateDto.getContentName();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_PDF);
        return new ResponseEntity<>(fc, headers, HttpStatus.CREATED);
    }

    @DeleteMapping("delete-file")
    @ApiOperation(value = "删除文件")
    public JsonVO<Integer> deleteFile(String group, String id) throws Exception {
        int res = dfs.deleteFile(FastDfsFileInfo.builder().group(group).storageId(id).build());
        if (res == 0) {
            return JsonVO.success(0);
        }
        return JsonVO.fail(res);
    }

}
