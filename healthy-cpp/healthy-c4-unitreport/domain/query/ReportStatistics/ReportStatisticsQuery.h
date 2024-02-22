#pragma once

#ifndef _REPORTSTATISTICSQUERY_H_
#define _REPORTSTATISTICSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

/*
* ͳ�Ʊ�����ʵ��
*/
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class ReportStatisticsQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ReportStatisticsQuery, PageQuery);
	//�������
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	////ͳ�Ʊ���������������ʾ1��"�����Ա���ܱ�" 2��"������Ա���ܱ�" 3��"���������ܱ�"
	//API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("unitreport.summaryTable.type"));
};

#include OATPP_CODEGEN_END(DTO)

#endif

