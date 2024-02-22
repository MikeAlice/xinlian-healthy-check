package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDeleteDTO;
import cn.hutool.core.util.ObjectUtil;
import com.zeroone.star.project.dto.j3.typeLibrary.typeAddDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeUpdateDTO;
import com.zeroone.star.project.j3.typelib.TypeLibApis;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeAddVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeUpdateVO;
import com.zeroone.star.sysmanager.service.ITProTypeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.models.auth.In;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 系统配置Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:10
 **/
@RestController
@RequestMapping("/sysconfig-typeLib")
@Api("类型库")
public class TypeLibController implements TypeLibApis {
    @Resource
    ITProTypeService typeService;

    @Resource
    ITProTypeService itProTypeService;
    /**
     * 获取类型树
     * @param typeLibraryTreedto
     * @return
     */
    @GetMapping("get-TProTypeTree")
    @ApiOperation("获取类型树")
    @Override
    public JsonVO<List<TProTypeVO>> getAllProTypeByTree(typeLibraryTreeDTO typeLibraryTreedto) {
        List<TProTypeVO> allProTypeByTree = itProTypeService.getAllProTypeByTree(typeLibraryTreedto);
        return JsonVO.success(allProTypeByTree);
    }

    /**
     * 搜索类型列表
     * @param typeLibraryQuery
     * @return
     */
    @GetMapping("query-TProTypeList")
    @ApiOperation("搜索类型列表")
    @Override
    public JsonVO<List<TProTypeVO>> queryTProTypeListByPage(TypeLibraryQuery typeLibraryQuery) {
        List<TProTypeVO> tProTypeListByPage = itProTypeService.getTProTypeListByPage(typeLibraryQuery);
        return JsonVO.success(tProTypeListByPage);
    }

    @DeleteMapping("remove-typelib")
    @ApiOperation("删除类型")
    @Override
    public JsonVO<Integer> removeTypeLib(@RequestParam String[] ids) {
        JsonVO<Integer> vo = new JsonVO<>();
        Integer i = itProTypeService.removeType(ids);
        vo.setMessage("删除了"+i+"节点");
        vo.setData(i);
        return vo;
    }

    @Override
    @PostMapping("/addType")
    @ApiOperation("新增类型")
    public JsonVO<typeAddVO> addType(@RequestBody typeAddDTO typeadddto) {
        return JsonVO.success(typeService.addType(typeadddto));
    }

    @Override
    @PutMapping("/updateType")
    @ApiOperation("修改类型")
    public JsonVO<Object> updateType(@RequestBody typeUpdateDTO typeupdatedto) {
        typeUpdateVO typeUpdateVO = typeService.updateType(typeupdatedto);
        if(ObjectUtil.isNotNull(typeUpdateVO)){
            return JsonVO.success(typeUpdateVO);
        }
        else{
            return JsonVO.fail("修改失败");
        }
    }
}
