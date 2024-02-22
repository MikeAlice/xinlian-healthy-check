package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.Dict.DictQuery;
import com.zeroone.star.sysmanager.entity.Dict;

import java.util.List;

/**
 * <p>
 * 字典 服务类
 * </p>
 *
 * @author Anemon
 * @since 2024-01-16
 */
public interface DictService extends IService<com.zeroone.star.project.dto.j3.dictory.DictDTO> {

    List<com.zeroone.star.project.dto.j3.dictory.DictDTO> findAllOrderBySortOrder();

    com.zeroone.star.project.dto.j3.dictory.DictDTO findByType(String type);
}
