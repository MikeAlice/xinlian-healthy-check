#pragma once
#ifndef _UpdateTBPDTO_H_
#define _UpdateTBPDTO_H_
#include"../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class UpdateTBPDTO : public oatpp::DTO
{
    DTO_INIT(UpdateTBPDTO, DTO);

    // ��������
    API_DTO_FIELD_DEFAULT(String, office_id, ZH_WORDS_GETTER("office_id"));
    // ��Ŀ����
    API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("code"));
    // ��Ŀ����
    API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("name"));
    // ��Ŀ���
    API_DTO_FIELD_DEFAULT(String, short_name, ZH_WORDS_GETTER("short_name"));
    // ����
    API_DTO_FIELD_DEFAULT(Float64, order_num, ZH_WORDS_GETTER("order_num"));
    // �������
    API_DTO_FIELD_DEFAULT(String, result_type, ZH_WORDS_GETTER("result_type"));
    // ��Ŀ��λ
    API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("unit_name"));
    // Ĭ��ֵ
    API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("default_value"));
    // ����С��
    API_DTO_FIELD_DEFAULT(String, in_conclution, ZH_WORDS_GETTER("in_conclution"));
    // ���뱨��
    API_DTO_FIELD_DEFAULT(String, inreport, ZH_WORDS_GETTER("inreport"));
    // LIS������
    API_DTO_FIELD_DEFAULT(String, relation_code, ZH_WORDS_GETTER("relation_code"));
    // ������λ
    API_DTO_FIELD_DEFAULT(String, _xx, ZH_WORDS_GETTER("_xx"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UpdateTBPDTO_H_
