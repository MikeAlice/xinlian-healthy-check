package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.ModifyDictData;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.query.j3.WordTypeListQuery;
import com.zeroone.star.sysmanager.entity.DictData;

import java.util.List;

/**
 * <p>
 * 字典数据 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITDictDataService extends IService<DictData> {
    JsonVO<Boolean> AddDictData(AddDictDataDTO addDictDataDTO);
    /**
     * 通过ID查询数据
     * @param id 唯一ID
     * @return 查询结果，如果没有查询到返回null
     */
    DictData getById(String id);

    /**
     * 通过id删除数据
     * @param id
     */
    void removeById(String id);

    /**
     * 分页查询所有数据
     * @param wordTypeListQuery 分页条件
     * @return
     */
    PageDTO<WordTypeListDTO> listPage(WordTypeListQuery wordTypeListQuery);

    /**
     * 获取字典数据名称
     * @return
     */
    List<String> getDictDataTitle();

    /**
     * 根据条件及分页获取字典数据列表
     * @param query
     * @return
     */
    PageDTO<DictDataDTO> ListPage(DictDataQuery query);

    JsonVO<Boolean> ModifyDictData(ModifyDictData modifyDictData);
}
