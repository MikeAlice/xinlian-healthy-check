#pragma once
#ifndef _SAVE_INFO_QUERY_H_
#define _SAVE_INFO_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class SaveInfoQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(SaveInfoQuery, PageQuery);
	// id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("exalanding.saveinfo.field.id"));
	// ���֤��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("exalanding.saveinfo.field.id_card"));
	//����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("exalanding.saveinfo.field.person_name"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("exalanding.saveinfo.field.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("exalanding.saveinfo.field.age"));
	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("exalanding.saveinfo.field.mobile"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, is_marry, ZH_WORDS_GETTER("exalanding.saveinfo.field.is_marry"));
	//�Ƿ�ͨ�����(1-�Ǽǣ�2-�ڼ�,3-�ܼ�,4-�����)
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("exalanding.saveinfo.field.is_pass"));
	//�������
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("exalanding.saveinfo.field.physical_type"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVE_INFO_QUERY_H_