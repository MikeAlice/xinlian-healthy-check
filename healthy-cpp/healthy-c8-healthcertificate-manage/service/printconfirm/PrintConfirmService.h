#pragma once
#include <list>
#include "domain/vo/printconfirm/PrintConfirmVO.h"
#include "domain/dto/printconfirm/PrintConfirmDTO.h"

/**
 * �Ӽ챨���б����ʵ��
 */
class PrintConfirmService
{
public:
	// ��������
	uint64_t saveData(const PrintConfirmDTO::Wrapper& dto);
	bool updateData(string order_id);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};
