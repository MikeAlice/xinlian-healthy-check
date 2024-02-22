#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/01/14

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
#ifndef _QUERYCRITVALUECONTROLLER_H_
#define _QUERYCRITVALUECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/vo/database/CritValueVO.h"
#include "../../../domain/query/database/CritValuePageQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class QueryCritValueController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(QueryCritValueController);
public://����ӿ�
	// �����ҳ��ѯΣ��ֵ�ӿ�����
	ENDPOINT_INFO(queryCriticalValuePage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("criticalValue.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CritValuePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		
		//// id
		//API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("criticalValue.field.id"), "0686fd1a5e1fa7aead2997d9d3568198",false);
		//// base_project_id ��Ŀid
		//API_DEF_ADD_QUERY_PARAMS(String, "baseProjectId", ZH_WORDS_GETTER("criticalValue.field.baseProjectId"), "721ec226a004670dd85777190ef00cb6", false);
		
		//level �ȼ�
		API_DEF_ADD_QUERY_PARAMS(String, "level", ZH_WORDS_GETTER("criticalValue.field.level"), "A",true);
		//type ����
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("criticalValue.field.type"),"LT" ,true);
		//interval_value ����ֵ
		API_DEF_ADD_QUERY_PARAMS(String, "intervalValue", ZH_WORDS_GETTER("criticalValue.field.intervalValue"), "12",true);
		// allow_sex �ʺ��Ա�
		API_DEF_ADD_QUERY_PARAMS(String, "allowSex", ZH_WORDS_GETTER("criticalValue.field.allowSex"), "Ů",false);
		// min_age �������ֵ
		API_DEF_ADD_QUERY_PARAMS(Int64, "minAge", ZH_WORDS_GETTER("criticalValue.field.minAge"), 6,false);
		// max_age �������ֵ
		API_DEF_ADD_QUERY_PARAMS(Int64, "maxAge", ZH_WORDS_GETTER("criticalValue.field.maxAge"), 97,false);
		//// department_id ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "departmentId", ZH_WORDS_GETTER("criticalValue.filed.departmentId"),"40322777781112832" ,false);
		//// create_id ������
		//API_DEF_ADD_QUERY_PARAMS(String, "createId", ZH_WORDS_GETTER("criticalValue.field.createId"), "1567427468967677952",false);
		//// create_time ����ʱ��
		//API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("criticalValue.field.createTime"),"2024-01-10 16:32:43" ,false);
	}
	// �����ҳ��ѯΣ��ֵ�ӿڴ���
	ENDPOINT(API_M_GET, "/database", queryCriticalValuePage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(cvPageQuery,CritValuePageQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCritValue(cvPageQuery));
	}

private:
	// ����ӿ�ִ�к���
	CritValuePageJsonVO::Wrapper execQueryCritValue(const CritValuePageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_