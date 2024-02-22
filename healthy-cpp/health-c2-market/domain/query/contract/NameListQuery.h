#pragma once
#ifndef _NAMELIST_H_
#define _NAMELIST_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class NameListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(NameListQuery, PageQuery);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("contract.field.type"));
	// �Ƿ����
	API_DTO_FIELD_DEFAULT(UInt32, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_