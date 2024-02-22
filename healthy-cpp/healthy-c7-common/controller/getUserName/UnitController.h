#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _UnitController_H_
#define _UnitController_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/getUserName/UnitQuery.h"
#include "domain/dto/getUserName/UnitListDTO.h"
#include "domain/vo/getUserName/UnitVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class UnitController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(UnitController);
public://����ӿ�
	// 3.1 �����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryUnit) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getUserName.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		//�Ƿ�ͨ�����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "ispass", ZH_WORDS_GETTER("getUserName.field.ispass"),2,true);
		// ����״̬  ������Ա�ڸ�����Ա��Ϣ���в�ѯ
		API_DEF_ADD_QUERY_PARAMS(UInt32, "isRecheck", ZH_WORDS_GETTER("getUserName.field.isRecheck"),1,true);
		//��ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("getUserName.field.startDate"), "2020-10-12", false);
		//����ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("getUserName.field.endDate"), "2023-10-12", false);
		//����
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("getUserName.field.personName"), "����", false);
		//�����
		API_DEF_ADD_QUERY_PARAMS(String, "testNum", ZH_WORDS_GETTER("getUserName.field.testNum"), "x12345", false);
		//��λ����
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("getUserName.field.dept"), "xxx���޹�˾", false);

		//�Ա�
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("getUserName.field.sex"), "��", false);
		//����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("getUserName.field.age"), 18, false);
		//������� physicalType
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("getUserName.field.physicalType"), "ְҵ���", false);
		//�Ƿ��������(0-��1-��)
		API_DEF_ADD_QUERY_PARAMS(UInt32, "sporadicPhysical", ZH_WORDS_GETTER("getUserName.field.sporadicPhysical"), 1, false);
	}

	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/getUserName/query-unit", queryUnit, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, UnitQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	
	};

private://����ӿ�ִ�к���
	UnitListPageJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 