package com.zeroone.star.term.service;

import com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.term.entity.TProType;

import java.util.List;

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） 服务类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
public interface ITProTypeService extends IService<TProType> {

    /*
     * @description: 获取类型树
     * @author: Laputa
     * @date: 2024/1/30 18:18
     * @param:  * @param typeCode
     * @return: java.util.List<com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO>
     **/
    List<OccupationalHazardTreeDTO> listOccupationalHazardTree(String typeCode);

    /*
     * @description: 根据父节点递归的构建树
     * @author: Laputa
     * @date: 2024/1/30 18:19
     * @param:  * @param parentId
     * @param data
     * @return: java.util.List<com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO>
     **/
    List<OccupationalHazardTreeDTO> getTree(String parentId, List<OccupationalHazardTreeDTO> data);
}
