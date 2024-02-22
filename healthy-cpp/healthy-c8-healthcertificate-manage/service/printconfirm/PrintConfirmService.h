#pragma once
#include <list>
#include "domain/vo/printconfirm/PrintConfirmVO.h"
#include "domain/dto/printconfirm/PrintConfirmDTO.h"

/**
 * 从检报告列表服务实现
 */
class PrintConfirmService
{
public:
	// 保存数据
	uint64_t saveData(const PrintConfirmDTO::Wrapper& dto);
	bool updateData(string order_id);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};
