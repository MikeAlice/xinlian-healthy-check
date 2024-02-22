#pragma once
#ifndef _RULESLIST_SERVICE_
#define _RULESLIST_SERVICE_
#include <list>
#include "domain/vo/rules/RulesListVO.h"
#include "domain/query/rules/RulesListQuery.h"
//#include "domain/query/rules/RulesListPageQuery.h"
#include "domain/dto/rules/RulesListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RulesListService
{
public:
	// ��ҳ��ѯ��������
	RulesListPageDTO::Wrapper listAll(const RulesListQuery::Wrapper& query);

	// �޸�����
	bool updateData(const RulesListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	
};

#endif // !_RULESLIST_SERVICE_

