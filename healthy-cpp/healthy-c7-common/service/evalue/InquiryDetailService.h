#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _INQUIRYDETAIL_SERVICE_
#define _INQUIRYDETAIL_SERVICE_
#include <list>
#include "domain/vo/evalue/InquiryDetailVO.h"
#include "domain/query/evalue/InquiryDetailQuery.h"
#include "domain/dto/evalue/InquiryDetailDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class InquiryDetailService
{
public:
	// ��ҳ��ѯ��������
	InquiryDetailPageDTO::Wrapper listAll(const InquiryDetailQuery::Wrapper& query);

	// �޸�����
	bool updateData(const InquiryDetailDTO::Wrapper& dto);

	//����id���ɶ�Ӧ��pdf
	InquiryDetailDTO::Wrapper InquiryDetailService::listById(const InquiryDetailQuery::Wrapper& query);



};

#endif // !_INQUIRYDETAIL_SERVICE_

