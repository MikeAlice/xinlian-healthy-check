package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDeleteDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeAddDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeUpdateDTO;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeAddVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeUpdateVO;
import com.zeroone.star.sysmanager.entity.ProType;

import java.util.List;

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITProTypeService extends IService<ProType> {

    List<TProTypeVO> getAllProTypeByTree(typeLibraryTreeDTO typeLibraryTreedto);

    List<TProTypeVO> getTProTypeListByPage(TypeLibraryQuery typeLibraryQuery);

    typeAddVO addType(typeAddDTO typeadddto);

    typeUpdateVO updateType(typeUpdateDTO typeupdatevo);

    Integer removeType(String[] ids);
}
