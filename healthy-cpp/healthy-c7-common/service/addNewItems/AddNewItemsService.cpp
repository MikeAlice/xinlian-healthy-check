#include "stdafx.h"
#include "AddNewItemsService.h"
#include "../../dao/addNewItems/AddNewItemsDAO.h"

uint64_t AddNewItemsService::saveData(const AddNewItemsDTO::Wrapper& dto)
{
	// ��װDO����
	AddNewItemsDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id ,CheckProjectId, checkProjectId, CheckProjectName, checkProjectName)
		// ִ���������
	AddNewItemsDAO dao; 
	return dao.insert(data);
}