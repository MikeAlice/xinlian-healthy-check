package com.zeroone.star.project.j3.dictory;

import cn.hutool.core.lang.Dict;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j3.Dict.DictQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @description: 字典api
 * @author: 坚强少年
 * @date: 2024/1/15 20:34
 **/
public interface DictApis {
    /**
     * 字典查询
     * @return 查询的分页结果
     */
    JsonVO<List<com.zeroone.star.project.dto.j3.dictory.DictDTO>> getAll();

    /**
     * 字典添加
     * @param dict 待添加的新字典
     * @return
     */
    JsonVO<Boolean> add(com.zeroone.star.project.dto.j3.dictory.DictDTO dict);


    /**
     * 修改字典
     * @return
     */
    JsonVO<Boolean> update(com.zeroone.star.project.dto.j3.dictory.DictDTO dict);
    /**
     * 删除字典
     * @return
     */
    JsonVO<Boolean> delete(List<String> ids);
}
