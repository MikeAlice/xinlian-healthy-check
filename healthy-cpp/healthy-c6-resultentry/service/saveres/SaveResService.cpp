#include "stdafx.h"
#include "SaveResService.h"

#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../Macros.h"
#include "../../../lib-mysql/include/TransactionManager.h"
#include "../../domain/dto/saveres/RPProCheckDTO.h"
#include "../../domain/do/saveres/RPProCheckDO.h"
#include "../../dao/saveres/RPProCheckDAO.h"
#include "../../domain/do/saveres/SaveResDO.h"
#include "../../dao/saveres/SaveResDAO.h"



uint64_t SaveResService::saveData(const SaveResDTO::Wrapper& dto, const string createId)
{
	SnowFlake sf(1, 1);
	uint64_t uint_id = sf.nextId();
	string id = to_string(uint_id);
	uint64_t tem_uint_id = uint_id;

	SaveResDO data;
	data.setCreateId(createId);
	SimpleDateTimeFormat createDate;
	data.setId(id);
	data.setCreateDate(createDate.format());
	data.setCheck_num(1);
	data.setDelFlag(0);
	data.setState(0);
	data.setIsFile("no");
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, OfficeId, officeId, OfficeName, officeName, \
		CheckDoc, checkDoc, CheckDate, checkDate, DelFlag, delFlag, \
		GroupItemId, groupItemId, GroupItemName, groupItemName, DiagnoseSum, diagnoseSum, \
		IsCheck, isCheck, DiagnoseTip, diagnoseTip)
	// 执行数据添加;;
		
	SaveResDAO d1, d2;
	// 定义事务
	TransactionManager tm(&d1, &d2);
	
	int row = d1.insert(data);
	data.setDepartResId(id);
	data.setOrderNum(1);
	for (int i = 0; i < dto->itemList->size(); i++)
	{
		auto &itemDto = dto->itemList[i];
		uint_id = sf.nextId();
		id = to_string(uint_id);
		data.setId(id);
		ZO_STAR_DOMAIN_DTO_TO_DO(data, itemDto, OrderGroupItemProjectId, orderGroupItemProjectId, \
			OrderGroupItemProjectName, orderGroupItemProjectName, \
			Result, result, UnitCode, unitCode, UnitName, unitName, CrisisDegree, crisisDegree, Positive, positive)
		row = row + d2.insertItem(data);
	}
	if (row == 1 + dto->itemList->size())
	{
		cout << "tm commit" << endl;
		tm.commit();
		return tem_uint_id;
	}
	else
	{
		cout << "tm rollback" << endl;
		tm.rollback();
		return 0;
	}

	 
}

bool SaveResService::updateData(const SaveResDTO::Wrapper& dto, const string createId)
{
	SaveResDO data;
	data.setCreateId(createId);
	SimpleDateTimeFormat updateDate;
	data.setUpdateDate(updateDate.format());


	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CheckDoc, checkDoc,DiagnoseSum, diagnoseSum, DiagnoseTip, diagnoseTip, UpdateId, updateId)
		// 执行数据修改
	SaveResDAO d1, d2;
	// 定义事务
	TransactionManager tm(&d1, &d2);

	int row = d1.update(data);
	
	for (int i = 0; i < dto->itemList->size(); i++)
	{
		auto& itemDto = dto->itemList[i];
		data.setId(itemDto->itemId);
		ZO_STAR_DOMAIN_DTO_TO_DO(data, itemDto, Result, result, Positive, positive)
		row = row + d2.updateItem(data);
	}
	if (row == 1 + dto->itemList->size())
	{
		cout << "tm commit" << endl;
		tm.commit();
	}
	else
	{
		cout << "tm rollback" << endl;
		tm.rollback();
	}

	return row == 1 + dto->itemList->size();

}

uint64_t SaveResService::saveRPProCheck(const RPProCheckDTO::Wrapper& dto)
{
	SnowFlake sf(1, 1);
	uint64_t uint_id = sf.nextId();
	string id = to_string(uint_id);

	RPProCheckDO data;
	data.setId(id);
	data.setState(1);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, OfficeId, officeId, \
		GroupItemId, groupItemId)
		// 执行数据添加;;
		RPProCheckDAO dao;
	if (dao.insert(data))
	{
		return uint_id;
	}
	else
		return 0;
	 
}

bool SaveResService::updateRPProCheck(const RPProCheckDTO::Wrapper& dto)
{
	RPProCheckDO data;
	// 设置为弃检
	data.setState(2);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, OfficeId, officeId, \
		GroupItemId, groupItemId)
		//执行数据修改
		RPProCheckDAO dao;
	return dao.update(data) == 1;
}


