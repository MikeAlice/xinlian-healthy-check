#pragma once
#ifndef _PlanProListController_
#define _PlanProListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/planprolist/PlanProListQuery.h"
#include "domain/dto/planprolist/PlanProListDTO.h"
#include "domain/vo/planprolist/PlanProListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PlanProListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PlanProListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryPlanProList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("planprolist.query-planprolist.summary"), PlanProListJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-planprolist", queryPlanProList, execQueryPlanProList(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	PlanProListJsonVO::Wrapper execQueryPlanProList(const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif