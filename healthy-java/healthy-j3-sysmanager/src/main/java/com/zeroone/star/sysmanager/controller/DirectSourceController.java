package com.zeroone.star.sysmanager.controller;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.j3.dictory.DirectSourceApis;
import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.ModifyDictData;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.DictData;
import com.zeroone.star.sysmanager.service.ITDictDataService;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 字典数据controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:04
 **/
@RestController
@RequestMapping("/sysconfig-directSource")
@Api(tags = "字典数据")
public class DirectSourceController implements DirectSourceApis {

    @Resource
    ITDictDataService itDictDataService;
    @ApiOperation("新增字典数据")
    @PostMapping("/addDictData")
    @Override
    public JsonVO<Boolean> AddDictData(AddDictDataDTO addDictDataDTO) {
        JsonVO<Boolean> booleanJsonVO = itDictDataService.AddDictData(addDictDataDTO);
        return booleanJsonVO;
    }

    @ApiOperation("修改字典数据")
    @PutMapping ("/modifyDictData")
    @Override
    public JsonVO<Boolean> ModifyDictData(ModifyDictData modifyDictData) {
        JsonVO<Boolean> booleanJsonVO = itDictDataService.ModifyDictData(modifyDictData);
        return booleanJsonVO;
    }


    @ApiOperation("获取字典数据名称列表")
    @GetMapping("/queryDictDataTitle")
    @Override
    public JsonVO<List<String>> queryDictDataTitle() {
        List<String> data = itDictDataService.getDictDataTitle();
        return JsonVO.success(data);
    }
    @ApiOperation("获取字典数据列表")
    @GetMapping("/queryDictDataByCondition")
    @Override
    public JsonVO<PageDTO<DictDataDTO>> queryDictDataByCondition(DictDataQuery condition) {
        PageDTO<DictDataDTO> data = itDictDataService.ListPage(condition);
        return JsonVO.success(data);
    }

    @ApiOperation("删除字典数据")
    @DeleteMapping("/deleteByIds")
    @Override
    public JsonVO<Boolean> deleteByIds(@RequestParam String[] ids) {
        for (String id : ids) { //这些id是t_dict_data里面的id
            //根据数据id先查询数据库，看是否存在数据
            DictData dictData=itDictDataService.getById(id);
            if(dictData == null){   //数据为空，失败逻辑
                return JsonVO.fail(Boolean.FALSE);
            }
            //否则的话执行删除
            itDictDataService.removeById(id);
        }
        //删除成功
        return JsonVO.success(Boolean.TRUE);
    }

    @ApiOperation("获取工种名称列表")
    @GetMapping("/queryByWordType")
    @Override
    public JsonVO<PageDTO<WordTypeListDTO>> queryByWordType(WordTypeListQuery wordTypeListQuery) {
        return JsonVO.success(itDictDataService.listPage(wordTypeListQuery));
    }

}
