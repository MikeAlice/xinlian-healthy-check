package com.zeroone.star.TemplateManagement.mapper;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.TemplateManagement.entity.TTemplate;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author TripleG
 * @since 2024-01-15
 */
@Mapper
public interface TemplateMMapper extends BaseMapper<TTemplate> {

    @Select("SELECT DISTINCT name from t_portfolio_project")
    List<String> selectName();

    // @Param("ew") Wrapper参数是必须，因为${ew.customSqlSegment} 底层其实就是where 条件，
    // 所以为了保证Wrapper不为空，service层代码中的Wrapper至少需要有一个条件：1 = 1
    @Select("SELECT t.id, t.report_type, t.type, p.`name`, t.`status`, t.content_name, t.create_time FROM t_template t " +
            "LEFT JOIN t_portfolio_project p ON t.base_project_id = p.id " + "${ew.customSqlSegment}")
    Page<TTemplate> selectTemplateList(IPage<TTemplate> page, @Param("ew")Wrapper<TTemplate> wrapper);
}
