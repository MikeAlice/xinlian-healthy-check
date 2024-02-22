#pragma once
#ifndef _UpdateTBPDTO_H_
#define _UpdateTBPDTO_H_
#include"../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class UpdateTBPDTO : public oatpp::DTO
{
    DTO_INIT(UpdateTBPDTO, DTO);

    // 所属科室
    API_DTO_FIELD_DEFAULT(String, office_id, ZH_WORDS_GETTER("office_id"));
    // 项目代码
    API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("code"));
    // 项目名称
    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("name"));
    // 项目简称
    API_DTO_FIELD_DEFAULT(String, short_name, ZH_WORDS_GETTER("short_name"));
    // 排序
    API_DTO_FIELD_DEFAULT(Float64, order_num, ZH_WORDS_GETTER("order_num"));
    // 结果类型
    API_DTO_FIELD_DEFAULT(String, result_type, ZH_WORDS_GETTER("result_type"));
    // 项目单位
    API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("unit_name"));
    // 默认值
    API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("default_value"));
    // 进入小结
    API_DTO_FIELD_DEFAULT(String, in_conclution, ZH_WORDS_GETTER("in_conclution"));
    // 进入报告
    API_DTO_FIELD_DEFAULT(String, inreport, ZH_WORDS_GETTER("inreport"));
    // LIS关联码
    API_DTO_FIELD_DEFAULT(String, relation_code, ZH_WORDS_GETTER("relation_code"));
    // 计量单位
    API_DTO_FIELD_DEFAULT(String, _xx, ZH_WORDS_GETTER("_xx"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UpdateTBPDTO_H_
