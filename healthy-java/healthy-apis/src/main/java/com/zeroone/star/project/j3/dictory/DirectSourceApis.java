package com.zeroone.star.project.j3.dictory;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.ModifyDictData;
import java.util.List;

/**
 * @description: 字典数据api
 * @author: 坚强少年
 * @date: 2024/1/15 20:34
 **/
public interface DirectSourceApis {
    JsonVO<Boolean> ModifyDictData(ModifyDictData modifyDictData);
    /**
     * 通过id删除数据字典，支持批量删除
     * @auther chenxiaxin
     * @param ids
     * @return
     */
    JsonVO<Boolean> deleteByIds(String[] ids);

    /**
     * 通过前端传递过来的数据，查询符合条件的工种名称列表
     * @auther chenxiaxin
     * @param wordTypeListQuery
     * @return
     */
    JsonVO<PageDTO<WordTypeListDTO>> queryByWordType(WordTypeListQuery wordTypeListQuery);

    /**
     * 获取字典数据名称列表
     * @auther MSNzqs
     * @return
     */
    JsonVO<List<String>> queryDictDataTitle();

    /**
     * 根据条件及分页查询字典数据列表
     * @param condition
     * @return
     */
    JsonVO<PageDTO<DictDataDTO>> queryDictDataByCondition(DictDataQuery condition);

    JsonVO<Boolean> AddDictData(AddDictDataDTO addDictDataDTO);

}

