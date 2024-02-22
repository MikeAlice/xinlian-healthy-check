#include "stdafx.h"
#include "ReviewService.h"
#include "uselib/pdf/ReviewPdf.h"
#include "uselib/fastdfs/ReviewFastDfs.h"

// ��ҳ��ѯ��������
ReviewListPageDTO::Wrapper ReviewService::listAll(const ReviewQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReviewListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ReviewDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ReviewDO> result = dao.selectWithPage(query);
	
	// ��DOת����DTO
	for (ReviewDO sub : result)
	{
		auto dto = ReviewListDTO::createShared();
		// dto->name = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, PersonName, checkProjectName, CheckProjectName, reviewExplain, ReviewExplain, reviewTime, ReviewTime, createTime, CreateTime, state, State, hazardFactorCode, HazardFactorCode)
		pages->addData(dto);
	}
	return pages;
}
// Pdfʹ��
ReviewListDTO::Wrapper ReviewService::listByName(const ReviewQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReviewListDTO::createShared();
	ReviewDAO dao;
	ReviewPdf pdf;
	ReviewFastDfs FastDfs;
	list<ReviewDO> result = dao.selectByName(query->personName);
	// ��DOת����DTO
	for (ReviewDO sub : result)
	{
		auto dto = ReviewListDTO::createShared();
		pdf.reviewText(sub);
		//pdf.reviewTpl(sub);
		dto->downloadUrl = FastDfs.ReviewDfsWithConf("ReviewReport.pdf");
		pages = dto;
	}
	return pages;
}
// �޸�����  ������벻��ͬʱ�޸Ķ�����е�����
bool ReviewService::updateData(const ReviewListDTO::Wrapper& dto)
{
	// ��װDO����
	ReviewDO data;
	//person_name  hazard_factor_code���ڸñ��޷��޸� swagger����ʾ���������ֶΣ�����ֱ������
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CheckProjectId, checkProjectId, CheckProjectName, checkProjectName, ReviewExplain, reviewExplain, ReviewTime, reviewTime, CreateTime, createTime, State, state, Id, id)
	// ִ�������޸�
	ReviewDAO dao;
	return dao.update(data) == 1;
}
// ͨ��IDɾ������
bool ReviewService::removeData(string id)
{
	ReviewDAO dao;
	return dao.deleteById(id) == 1;
}