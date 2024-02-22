#include "stdafx.h"
#include "PersonalReviewService.h"
#include "../../dao/personalReview/PersonalReviewDAO.h"


bool PersonalReviewService::updateData(const PersonalReviewDTO::Wrapper& dto) {
	// 组装DO数据
	PersonalReviewDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, UpdateId, updateId)
		// 执行数据修改
		PersonalReviewDAO dao;
	return dao.update(data) == 1;

}


 
