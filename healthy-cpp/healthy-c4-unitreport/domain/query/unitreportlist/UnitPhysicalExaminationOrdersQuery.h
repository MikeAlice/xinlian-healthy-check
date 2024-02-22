#pragma once

#ifndef _UNITPHYSICALEXAMINATIONORDERSQUERY_H_
#define _UNITPHYSICALEXAMINATIONORDERSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

/*
* ��쵥λ��ҳ���������б�����ʵ��
*/
#include OATPP_CODEGEN_BEGIN(DTO)

class UnitPhysicalExaminationOrdersQuery : public PageQuery
{
	//�����ʼ��
	DTO_INIT(UnitPhysicalExaminationOrdersQuery, PageQuery);
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unitreport.unit.name"));
	//���Ҷ���ǩ��ʱ��Ŀ�ʼʱ��
	API_DTO_FIELD_DEFAULT(String, beginTime, ZH_WORDS_GETTER("unitreport.order.signingTime"));
	//���Ҷ���ǩ��ʱ��Ľ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("unitreport.order.signingTime"));
};

#include OATPP_CODEGEN_END(DTO)

#endif

