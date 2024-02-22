#include "stdafx.h"
#include "AddNewItemsService.h"
#include "../../dao/addNewItems/AddNewItemsDAO.h"

uint64_t AddNewItemsService::saveData(const AddNewItemsDTO::Wrapper& dto)
{
	// 组装DO数据
	AddNewItemsDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id ,CheckProjectId, checkProjectId, CheckProjectName, checkProjectName)
		// 执行数据添加
	AddNewItemsDAO dao; 
	return dao.insert(data);
}