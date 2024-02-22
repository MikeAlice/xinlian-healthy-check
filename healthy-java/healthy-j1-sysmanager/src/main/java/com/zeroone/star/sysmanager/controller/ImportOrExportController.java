package com.zeroone.star.sysmanager.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j1.dto.sysmanager.DepartmentManagementDTO;
import com.zeroone.star.project.j1.sysmanager.ImportOrExportApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.entity.User;
import com.zeroone.star.sysmanager.mapper.TUserMapper;
import com.zeroone.star.sysmanager.service.ITUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-导入导出")
public class ImportOrExportController implements ImportOrExportApis {

    @Resource
    FastDfsClientComponent dfs;
    @Resource
    EasyExcelComponent excel;
    @Resource
    private ITUserService userService;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    List<User> datas = new ArrayList<>();
    @PostConstruct
    public void initData() {
        datas = userService.listAll();
    }

    /**
     * 导出全部数据
     * @return
     */
    @ApiOperation("导出全部数据")
    @GetMapping(value = "export-form-department")
    @Override
    public JsonVO<String> exportFormOfDepartment() throws Exception {
        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("用户信息", out, User.class, datas);
        // 上传到文件服务器
        FastDfsFileInfo xlsx = dfs.uploadFile(out.toByteArray(), "xlsx");
        out.close();
        if (xlsx != null) {
            return JsonVO.success(dfs.fetchUrl(xlsx, fileServerUrl, true));
        }
        return JsonVO.fail(null);
    }

    /**
     * 导入用户数据
     * @param file 用户数据文件
     * @return
     */
    @PostMapping("/import-user-data")
    @ApiOperation(value = "导入用户数据")
    @ResponseBody
    @Override
    public JsonVO<String> importUserData(MultipartFile file) throws Exception {
        // 获取上传文件的后缀名，判断是否是excel文件
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        if (!suffix.equals("xls") && !suffix.equals("xlsx") && !suffix.equals("csv")) {
            return JsonVO.fail("文件类型不是excel类型");
        }
        FastDfsFileInfo result = dfs.uploadFile(file.getBytes(), suffix);
        if (result == null) {
            return JsonVO.fail("文件上传失败");
        }
        dfs.fetchUrl(result, fileServerUrl, true);
        return JsonVO.success("导入成功");
    }
}
