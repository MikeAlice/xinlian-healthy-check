#pragma once
#ifndef _DETAILDTO_H_
#define _DETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 单位列表传输数据对象实体
 */
class DetailDTO : public oatpp::DTO
{
    DTO_INIT(DetailDTO, DTO);
    // 体检编号
    API_DTO_FIELD_DEFAULT(String, physicalExamNumber, ZH_WORDS_GETTER("detail.field.physicalExamNumber"));
    // 身份证号
    API_DTO_FIELD_DEFAULT(String, identityCardNumber, ZH_WORDS_GETTER("detail.field.identityCardNumber"));
    // 姓名
    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("detail.field.name"));
    // 性别
    API_DTO_FIELD_DEFAULT(String, gender, ZH_WORDS_GETTER("detail.field.gender"));
    // 年龄
    API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("detail.field.age"));
    // 电话号码
    API_DTO_FIELD_DEFAULT(String, phoneNumber, ZH_WORDS_GETTER("detail.field.phoneNumber"));
    // 单位名称
    API_DTO_FIELD_DEFAULT(String, organizationName, ZH_WORDS_GETTER("detail.field.organizationName"));
    // 登记时间
    API_DTO_FIELD_DEFAULT(String, registrationTime, ZH_WORDS_GETTER("detail.field.registrationTime"));
};

/**
 * 单位列表分页数据实体
 */
class DetailPageDTO : public PageDTO<DetailDTO::Wrapper> {
    DTO_INIT(DetailPageDTO, PageDTO<DetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETAILDTO_H_