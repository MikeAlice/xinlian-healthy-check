package com.zeroone.star.portfolioitems.mapper;

import com.zeroone.star.portfolioitems.entity.TDictData;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j4.vo.ProjectNameListVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 字典数据 Mapper 接口
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Mapper
public interface TDictDataMapper extends BaseMapper<TDictData> {

    @Select("SELECT tdd.id,tdd.description,tdd.title,tdd.`value`,td.type" +
            " FROM  t_dict_data  tdd INNER JOIN  `t_dict` td  on tdd. dict_id = td.id " +
            "where td.type = 'lis_type' and tdd.del_flag='0'")
    List<ProjectNameListVO> listPorjectName();
}
