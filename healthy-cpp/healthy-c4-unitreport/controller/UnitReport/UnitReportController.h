/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/01/14 18:40:43

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
#ifndef _UNITREPORT_H_
#define _UNITREPORT_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "domain/vo/UnitReportJsonVO.h"
#include "domain/dto/UnitReportDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitReportController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(UnitReportController)
public: // ����ӿ�
	ENDPOINT_INFO(queryUnitReport) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("UnitReport.get.summary"));
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitReportJsonVO);
	}

	// ����ӿڴ���
	ENDPOINT(API_M_GET, "/UnitReport/get-all", queryUnitReport) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnitReport());
	}
private: // ����ӿ�ִ�к���
	UnitReportJsonVO::Wrapper execQueryUnitReport();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_UNITREPORT_H_