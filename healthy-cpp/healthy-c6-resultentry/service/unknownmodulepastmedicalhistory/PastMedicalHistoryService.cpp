#include "stdafx.h"
#include "PastMedicalHistoryService.h"
#include "../../dao/unknownmodulepastmedicalhistory/PastMedicalHistoryDAO.h"
#include "../../domain/do/unknownmodulepastmedicalhistory/PastMedicalHistoryDO.h"
#include "../../../nacos-register/Macros.h"
#include "../../../arch-demo/Macros.h"
// #include "../../dao/GroupPerson/GroupPersonDAO.h" ����

PastMedicalHistoryPageDTO::Wrapper PastMedicalHistoryService::listAll(const PastMedicalHistoryQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PastMedicalHistoryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PastMedicalHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PastMedicalHistoryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PastMedicalHistoryDO sub : result)
	{
		auto dto = PastMedicalHistoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_id, Person_id, abortion, Abortion, premature, Premature, death, Death, abnormal_fetus, Abnormal_fetus, menstrual_history, Menstrual_history, menstrual_info, Menstrual_info, allergies, Allergies, allergies_info, Allergies_info, past_medical_history, Past_medical_history, past_medical_history_other_info, Past_medical_history_other_info)
			pages->addData(dto);
	}
	return pages;
}
