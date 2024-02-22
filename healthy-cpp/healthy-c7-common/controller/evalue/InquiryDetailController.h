#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/01/19

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _INQUIRYDETAIL_CONTROLLER_
#define _INQUIRYDETAIL_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "../healthy-c7-common/domain/query/evalue/InquiryDetailQuery.h"
#include "../healthy-c7-common/domain/dto/evalue/InquiryDetailDTO.h"
#include "../healthy-c7-common/domain/vo/evalue/InquiryDetailVO.h"
#include "../../../arch-demo/controller/file/FileController.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����������ʾ�����ӿڵ�ʹ��
 */
class InquiryDetailController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(InquiryDetailController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryInquiryDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("InquiryDetail.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InquiryDetailPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("inquiry.field.Id"), 1, false);
		// �������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workYear", ZH_WORDS_GETTER("inquiry.field.workYear"), 1, false);
		// �����¶�
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workMonth", ZH_WORDS_GETTER("inquiry.field.workMonth"), 1, false);
		// ���״��
		API_DEF_ADD_QUERY_PARAMS(String, "isMarry", ZH_WORDS_GETTER("inquiry.field.isMarry"), "marry", false);
		//��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "exposureWorkYear", ZH_WORDS_GETTER("inquiry.field.exposureWorkYear"), 1, false);
		//��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "exposureWorkMonth", ZH_WORDS_GETTER("inquiry.field.exposureWorkMonth"), 1, false);

		//�Ǳ���

		//�Ļ��̶�
		API_DEF_ADD_QUERY_PARAMS(String, "education", ZH_WORDS_GETTER("inquiry.field.education"), "university", false);
		//��ͥ��ַ
		API_DEF_ADD_QUERY_PARAMS(String, "familyAddress", ZH_WORDS_GETTER("inquiry.field.familyAddress"), "guangzhou", false);
		//��������
		API_DEF_ADD_QUERY_PARAMS(String, "workTypeText", ZH_WORDS_GETTER("inquiry.field.workTypeText"), "student", false);
		//������������
		API_DEF_ADD_QUERY_PARAMS(String, "workName", ZH_WORDS_GETTER("inquiry.field.workName"), "student", false);
		//��������
		API_DEF_ADD_QUERY_PARAMS(String, "department", ZH_WORDS_GETTER("inquiry.field.department"), "studydepartment", false);


	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/evalue/-inquiry-detail", queryInquiryDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, InquiryDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryInquiryDetail(userQuery, authObject->getPayload()));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("InquiryDetail.put.summary"), modifyInquiryDetail, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/evalue/inquiry-detail", modifyInquiryDetail, BODY_DTO(InquiryDetailDTO::Wrapper, dto), execModifyInquiryDetail(dto));

	// 3.1 ����Pdf�ӿ�����
	ENDPOINT_INFO(queryPdf) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("InquiryDetail.pdf.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InquiryDetailJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("inquiry.field.id"), "0", false);
	}
	// 3.2 ����Pdf�ӿڴ���
	ENDPOINT(API_M_GET, "/evalue/pdf-InquiryDetail", queryPdf, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(pdfQuery, InquiryDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPdf(pdfQuery));
	}

private:
	InquiryDetailPageJsonVO::Wrapper execQueryInquiryDetail(const InquiryDetailQuery::Wrapper& query, const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execModifyInquiryDetail(const InquiryDetailDTO::Wrapper& dto);

	InquiryDetailJsonVO::Wrapper execQueryPdf(const InquiryDetailQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif  _INQUIRYDETAIL_CONTROLLER_