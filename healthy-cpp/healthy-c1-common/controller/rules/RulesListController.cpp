#include "stdafx.h"
#include "RulesListController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "service/rules/RulesListService.h"

/**
 * ע�⣺����Ĳ��ִ��뱾Ӧ�÷ŵ�service���У�Ϊ�˷�����ʾ��д��һ����
 */

RulesListPageJsonVO::Wrapper RulesListController::executeQueryAll(const RulesListQuery::Wrapper& query)
{
	// ����һ��Service
	RulesListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RulesListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper RulesListController::executeModifyRules(const RulesListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	// ����һ��Service
	RulesListService service;
	// ִ�������޸�
	// ִ����������
	bool id = service.updateData(dto);
	if (id) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// ��Ӧ���
	return jvo;
}
