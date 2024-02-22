
#pragma once
#ifndef _CHECKLIST_SERVICE_
#define _CHECKLIST_SERVICE_
#include <list>
#include "domain/vo/Exalanding/CheckListVO.h"
#include "domain/query/Exalanding/CheckListQuery.h"
#include "domain/dto/Exalanding/CheckListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CheckListService
{
public:
	// ��ҳ��ѯ��������
	CheckListPageDTO::Wrapper listAll(const CheckListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const CheckListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const CheckListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_CHECKLIST_SERVICE_


