#include "stdafx.h"
#include "PastMedicalHistoryService.h"
#include "../../dao/unknownmodulepastmedicalhistory/PastMedicalHistoryDAO.h"
#include "../../domain/do/unknownmodulepastmedicalhistory/PastMedicalHistoryDO.h"
#include "../../../nacos-register/Macros.h"
#include "../../../arch-demo/Macros.h"
// #include "../../dao/GroupPerson/GroupPersonDAO.h" 待定

PastMedicalHistoryPageDTO::Wrapper PastMedicalHistoryService::listAll(const PastMedicalHistoryQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PastMedicalHistoryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PastMedicalHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PastMedicalHistoryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PastMedicalHistoryDO sub : result)
	{
		auto dto = PastMedicalHistoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_id, Person_id, abortion, Abortion, premature, Premature, death, Death, abnormal_fetus, Abnormal_fetus, menstrual_history, Menstrual_history, menstrual_info, Menstrual_info, allergies, Allergies, allergies_info, Allergies_info, past_medical_history, Past_medical_history, past_medical_history_other_info, Past_medical_history_other_info)
			pages->addData(dto);
	}
	return pages;
}
