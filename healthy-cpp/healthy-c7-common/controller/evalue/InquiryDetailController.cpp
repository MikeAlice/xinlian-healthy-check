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

// ����ṹ������˲�ѯϸ�ڵ� JSON ��Ӧ�İ�װ����
// ����Ϊ execQueryInquiryDetail �����ķ������͡�
//��ѯ����
InquiryDetailPageJsonVO::Wrapper InquiryDetailController::execQueryInquiryDetail(const InquiryDetailQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	InquiryDetailService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InquiryDetailPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//�޸�����
Uint64JsonVO::Wrapper InquiryDetailController::execModifyInquiryDetail(const InquiryDetailDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	InquiryDetailService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

//PDF
InquiryDetailJsonVO::Wrapper InquiryDetailController::execQueryPdf(const InquiryDetailQuery::Wrapper& query)
{
	// ����һ��Service
	InquiryDetailService service;
	// ��ѯ����
	auto result = service.listById(query);
	auto jvo = InquiryDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}