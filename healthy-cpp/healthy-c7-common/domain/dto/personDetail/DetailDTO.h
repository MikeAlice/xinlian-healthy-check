#pragma once
#ifndef _DETAILDTO_H_
#define _DETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ�б������ݶ���ʵ��
 */
class DetailDTO : public oatpp::DTO
{
    DTO_INIT(DetailDTO, DTO);
    // �����
    API_DTO_FIELD_DEFAULT(String, physicalExamNumber, ZH_WORDS_GETTER("detail.field.physicalExamNumber"));
    // ���֤��
    API_DTO_FIELD_DEFAULT(String, identityCardNumber, ZH_WORDS_GETTER("detail.field.identityCardNumber"));
    // ����
    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("detail.field.name"));
    // �Ա�
    API_DTO_FIELD_DEFAULT(String, gender, ZH_WORDS_GETTER("detail.field.gender"));
    // ����
    API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("detail.field.age"));
    // �绰����
    API_DTO_FIELD_DEFAULT(String, phoneNumber, ZH_WORDS_GETTER("detail.field.phoneNumber"));
    // ��λ����
    API_DTO_FIELD_DEFAULT(String, organizationName, ZH_WORDS_GETTER("detail.field.organizationName"));
    // �Ǽ�ʱ��
    API_DTO_FIELD_DEFAULT(String, registrationTime, ZH_WORDS_GETTER("detail.field.registrationTime"));
};

/**
 * ��λ�б��ҳ����ʵ��
 */
class DetailPageDTO : public PageDTO<DetailDTO::Wrapper> {
    DTO_INIT(DetailPageDTO, PageDTO<DetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETAILDTO_H_