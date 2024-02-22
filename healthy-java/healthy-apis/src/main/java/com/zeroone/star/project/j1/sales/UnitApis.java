package com.zeroone.star.project.j1.sales;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.dto.UnitListDTO;
import com.zeroone.star.project.j1.query.UnitQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：单位管理接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface UnitApis {

    /**
     * 单位列表查询接口
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<UnitListDTO>> queryUnitList(UnitQuery query);
}
