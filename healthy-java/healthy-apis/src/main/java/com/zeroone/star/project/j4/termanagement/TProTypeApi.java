package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @Description: 类型库（如：职业危害因素，经济类型、行业类别等等） 的接口
 * @Author: Laputa
 * @CreateTime: 2024-01-30  04:15
 * @Version: 1.0
 */
public interface TProTypeApi {
    /*
     * @description: 获取职业危害因素树
     * @author: Laputa
     * @date:  2024-01-30  03:48
     * @param:
     * @return:
     **/

    JsonVO<List<OccupationalHazardTreeDTO>> queryOccupationalHazardTree() throws Exception;
}
