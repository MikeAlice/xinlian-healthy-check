#pragma once
#ifndef _BASEINFO_H_
#define _BASEINFO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class BaseInfoQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(BaseInfoQuery, PageQuery);
	// ǩ��ʱ��
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("contract.field.signingTime"));
	// ί�е�λ
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("contract.field.groupUnitName"));
	//�Ƿ����
	API_DTO_FIELD_DEFAULT(UInt32, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
