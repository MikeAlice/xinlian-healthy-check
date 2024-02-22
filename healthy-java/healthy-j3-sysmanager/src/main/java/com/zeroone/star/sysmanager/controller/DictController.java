package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictory.DictDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.j3.dictory.DictApis;
import com.zeroone.star.project.query.j3.Dict.DictQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.Dict;
import com.zeroone.star.sysmanager.service.DictService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * ClassName: DictController
 * Package: com.zeroone.star.sysmanager.controller
 * Charset: UTF-8
 * <p>
 * Description:
 *
 * @Author Anemon_ZY
 * @Create 2024/1/16 20:50
 * @Version 0.1
 */
@RestController
@RequestMapping("/sysconfig-dict")
@Api("数据字典")
public class DictController implements DictApis {
    @Autowired
    DictService dictService;

    @GetMapping(value = "/getAllDict")
    @ApiOperation(value = "获取字典列表")
    public JsonVO<List<DictDTO>> getAll() {

        List<DictDTO> list = dictService.findAllOrderBySortOrder();
        if (list == null) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(list);
    }

    @PostMapping(value = "/addDict")
    @ApiOperation(value = "新增字典")
    public JsonVO<Boolean> add(com.zeroone.star.project.dto.j3.dictory.DictDTO dict) {

        if (dict == null || dict.getType() == null ||
                dictService.findByType(dict.getType()) != null) {
            return JsonVO.fail(Boolean.FALSE);
        }
        dictService.save(dict);
        return JsonVO.success(Boolean.TRUE);
    }


    @PutMapping(value = "/updatedict")
    @ApiOperation(value = "修改字典")
    public JsonVO<Boolean> update(com.zeroone.star.project.dto.j3.dictory.DictDTO dict) {
        if (dictService.findByType(dict.getType()) != null) {
            return JsonVO.fail(Boolean.FALSE);
        }
        dictService.updateById(dict);
        return JsonVO.success(Boolean.TRUE);

    }
    @DeleteMapping(value = "/deletedict")
    @ApiOperation(value = "删除字典")
    public JsonVO<Boolean> delete(@RequestParam List<String> ids) {
        dictService.removeByIds(ids);
        return JsonVO.success(Boolean.TRUE);
    }
}
