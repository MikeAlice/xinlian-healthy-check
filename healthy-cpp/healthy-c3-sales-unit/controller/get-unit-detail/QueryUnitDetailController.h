#pragma once

#ifndef _QUERYUNITDETAILCONTROLLER_H_
#define _QUERYUNITDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/get-unit-detail/UnitDetailVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ��λ����    �����ˣ�duxlong
 */
class QueryUnitDetailController: public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QueryUnitDetailController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	ENDPOINT_INFO(queryUnitDetail) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("unit.get-detail.summary"), UnitDetailJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("unit.field.id"), "", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/unit/get-detail/{id}", queryUnitDetail, PATH(String, id), execQueryUnitDetail(id));


private: // 3.3 ����ӿ�ִ�к���
	UnitDetailJsonVO::Wrapper execQueryUnitDetail(const String& id);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_QUERYUNITDETAILCONTROLLER_H_
