package com.zeroone.star.project.j3.typelib;

import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDeleteDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeAddDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeUpdateDTO;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeAddVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeUpdateVO;

import java.util.List;

/**
 * @description:类型库api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface TypeLibApis {
    /**
     * 获取类型树
     * @param typeLibraryTreedto
     * @return
     */
    JsonVO<List<TProTypeVO>> getAllProTypeByTree(typeLibraryTreeDTO typeLibraryTreedto);

    /**
     * 搜索类型列表
     * @param typeLibraryQuery
     * @return
     */
    JsonVO<List<TProTypeVO>> queryTProTypeListByPage(TypeLibraryQuery typeLibraryQuery);


    /**
     * @Author car
     * @Description //TODO 批量删除类型库
     * @Date 17:45 2024/1/31
     * @Param [java.lang.String[]]
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.Integer>
     **/
    JsonVO<Integer> removeTypeLib(String[] ids);
    /**
    * @Description: 新增类型
    * @Param:
    * @return:
    * @Author: usagi
    * @Date: 2024/1/21
    * @Time:16:38
    */
    JsonVO<typeAddVO> addType(typeAddDTO typeadddto);
    /**
    * @Description:
    * @Param: [typeupdatevo]
    * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.j3.typeLibrary.typeUpdateVO>
    * @Author: usagi
    * @Date: 2024/1/21
    * @Time:17:18
    * @Date: 2024/1/22
    * @Time:15:14
    */
    JsonVO<Object> updateType(typeUpdateDTO typeupdatedto);
}
