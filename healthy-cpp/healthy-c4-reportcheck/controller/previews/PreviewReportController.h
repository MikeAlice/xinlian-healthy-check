#pragma once
#ifndef _PREVIEWREPORTCONTROLLER_H_
#define _PREVIEWREPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/previews/PreviewReportQuery.h"
#include "domain/vo/previews/PreviewReportVO.h"
#include "domain/dto/previews/PreviewReportDTO.h"

// ����API������ʹ�õĺ�
#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* �ӿڵ�ʵ��
* ������ Z
*/
class PreviewReportController : public oatpp::web::server::api::ApiController
{
	// ������������ʽӿ�
	API_ACCESS_DECLARE(PreviewReportController);

public://����ӿ�
	// �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryPreviewReport) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("preview.get.summary"));	
		//����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HENDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(PreviewReportJsonVO);
		// ����������ѯ��������
		
		// ��Ա��id
		API_DEF_ADD_QUERY_PARAMS(String, "persionId", ZH_WORDS_GETTER("preview.field.persionid"), nullptr, true);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/previews/preview-report", queryPreviewReport, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//������ѯ����ΪQuery����ģ��,Ҳ���ǰѲ�ѯ������ֵ����
		API_HANDLER_QUERY_PARAM(prq, PreviewReportQuery, params);
		//����ִ�к�����Ӧ
		API_HANDLER_RESP_VO(execPreviewReport(prq));
	}
private://����ӿڵ�ִ�к���
	PreviewReportJsonVO::Wrapper execPreviewReport(const PreviewReportQuery::Wrapper& query);
};

// ȡ��API������ʹ�ú� 
#include OATPP_CODEGEN_END(ApiController)// <- End Codegen
#endif // !_PREVIEWREPORTCONTROLLER_H_
