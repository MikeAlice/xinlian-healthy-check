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

#include "stdafx.h"
#include "InquiryDetailController.h"
#include "domain/dto/evalue/InquiryDetailDTO.h"
#include "../../service/evalue/InquiryDetailService.h"

// 这个结构体代表了查询细节的 JSON 响应的包装器。
// 它作为 execQueryInquiryDetail 函数的返回类型。
//查询数据
InquiryDetailPageJsonVO::Wrapper InquiryDetailController::execQueryInquiryDetail(const InquiryDetailQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	InquiryDetailService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InquiryDetailPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//修改数据
Uint64JsonVO::Wrapper InquiryDetailController::execModifyInquiryDetail(const InquiryDetailDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	InquiryDetailService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

//PDF
InquiryDetailJsonVO::Wrapper InquiryDetailController::execQueryPdf(const InquiryDetailQuery::Wrapper& query)
{
	// 定义一个Service
	InquiryDetailService service;
	// 查询数据
	auto result = service.listById(query);
	auto jvo = InquiryDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}