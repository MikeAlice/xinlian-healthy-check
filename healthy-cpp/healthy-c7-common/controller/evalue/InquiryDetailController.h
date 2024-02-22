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


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，演示基础接口的使用
 */
class InquiryDetailController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InquiryDetailController);
	// 3 定义接口
public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryInquiryDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("InquiryDetail.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InquiryDetailPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("inquiry.field.Id"), 1, false);
		// 工龄年段
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workYear", ZH_WORDS_GETTER("inquiry.field.workYear"), 1, false);
		// 工龄月段
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workMonth", ZH_WORDS_GETTER("inquiry.field.workMonth"), 1, false);
		// 结婚状况
		API_DEF_ADD_QUERY_PARAMS(String, "isMarry", ZH_WORDS_GETTER("inquiry.field.isMarry"), "marry", false);
		//按需年龄
		API_DEF_ADD_QUERY_PARAMS(UInt64, "exposureWorkYear", ZH_WORDS_GETTER("inquiry.field.exposureWorkYear"), 1, false);
		//按需月龄
		API_DEF_ADD_QUERY_PARAMS(UInt64, "exposureWorkMonth", ZH_WORDS_GETTER("inquiry.field.exposureWorkMonth"), 1, false);

		//非必须

		//文化程度
		API_DEF_ADD_QUERY_PARAMS(String, "education", ZH_WORDS_GETTER("inquiry.field.education"), "university", false);
		//家庭地址
		API_DEF_ADD_QUERY_PARAMS(String, "familyAddress", ZH_WORDS_GETTER("inquiry.field.familyAddress"), "guangzhou", false);
		//工种名称
		API_DEF_ADD_QUERY_PARAMS(String, "workTypeText", ZH_WORDS_GETTER("inquiry.field.workTypeText"), "student", false);
		//工种其他名称
		API_DEF_ADD_QUERY_PARAMS(String, "workName", ZH_WORDS_GETTER("inquiry.field.workName"), "student", false);
		//所属部门
		API_DEF_ADD_QUERY_PARAMS(String, "department", ZH_WORDS_GETTER("inquiry.field.department"), "studydepartment", false);


	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/evalue/-inquiry-detail", queryInquiryDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, InquiryDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInquiryDetail(userQuery, authObject->getPayload()));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("InquiryDetail.put.summary"), modifyInquiryDetail, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/evalue/inquiry-detail", modifyInquiryDetail, BODY_DTO(InquiryDetailDTO::Wrapper, dto), execModifyInquiryDetail(dto));

	// 3.1 定义Pdf接口描述
	ENDPOINT_INFO(queryPdf) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("InquiryDetail.pdf.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InquiryDetailJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("inquiry.field.id"), "0", false);
	}
	// 3.2 定义Pdf接口处理
	ENDPOINT(API_M_GET, "/evalue/pdf-InquiryDetail", queryPdf, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(pdfQuery, InquiryDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPdf(pdfQuery));
	}

private:
	InquiryDetailPageJsonVO::Wrapper execQueryInquiryDetail(const InquiryDetailQuery::Wrapper& query, const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execModifyInquiryDetail(const InquiryDetailDTO::Wrapper& dto);

	InquiryDetailJsonVO::Wrapper execQueryPdf(const InquiryDetailQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif  _INQUIRYDETAIL_CONTROLLER_