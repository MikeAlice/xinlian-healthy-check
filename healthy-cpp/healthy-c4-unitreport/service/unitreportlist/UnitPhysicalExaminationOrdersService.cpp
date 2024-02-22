#include "stdafx.h"
#include "UnitPhysicalExaminationOrdersService.h"
#include "../../dao/unitreportlist/UnitPhysicalExaminationOrdersDAO.h"

UnitListPageDTO::Wrapper UnitPhysicalExaminationOrdersService::listAll(const UnitPhysicalExaminationOrdersQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnitListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	UnitPhysicalExaminationOrdersDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<UnitPhysicalExaminationOrdersDO> result = dao.selectWithPage(query);

	// ��DOת����DTO
	for (UnitPhysicalExaminationOrdersDO sub : result)
	{
		auto dto = UnitListDTO::createShared();
 		dto->name = sub.getName();
 		dto->code = sub.getCode();
 		dto->signingTime = sub.getSigningTime();
		if (sub.getEscalation() == 1)//1��ʾ�ݴ�δ��
		{
			dto->Escalation = ZH_WORDS_GETTER("unitreport.order.unreported");
		}
		else if(sub.getEscalation()==2)//2��ʾ�ύ�ѱ�
		{
			dto->Escalation = ZH_WORDS_GETTER("unitreport.order.reported");
		}

		if (sub.getDetectionType() == 0)//��ʾ��������
		{
			dto->detectionType = ZH_WORDS_GETTER("unitreport.order.groupInspection");
		}
		else if(sub.getDetectionType() == 1)//��ʾ�����Ǽ��
		{
			dto->detectionType = ZH_WORDS_GETTER("unitreport.order.sporadic");
		}
		
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, code, Code, signingTime, SigningTime, Escalation, Escalation, detectionType, DetectionType)
	    pages->addData(dto);
	}
	return pages;
}
