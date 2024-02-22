#include "stdafx.h"
#include "ReviewService.h"
#include "uselib/pdf/ReviewPdf.h"
#include "uselib/fastdfs/ReviewFastDfs.h"

// 分页查询所有数据
ReviewListPageDTO::Wrapper ReviewService::listAll(const ReviewQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReviewListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ReviewDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ReviewDO> result = dao.selectWithPage(query);
	
	// 将DO转换成DTO
	for (ReviewDO sub : result)
	{
		auto dto = ReviewListDTO::createShared();
		// dto->name = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, PersonName, checkProjectName, CheckProjectName, reviewExplain, ReviewExplain, reviewTime, ReviewTime, createTime, CreateTime, state, State, hazardFactorCode, HazardFactorCode)
		pages->addData(dto);
	}
	return pages;
}
// Pdf使用
ReviewListDTO::Wrapper ReviewService::listByName(const ReviewQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReviewListDTO::createShared();
	ReviewDAO dao;
	ReviewPdf pdf;
	ReviewFastDfs FastDfs;
	list<ReviewDO> result = dao.selectByName(query->personName);
	// 将DO转换成DTO
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
// 修改数据  下面代码不能同时修改多个表中的数据
bool ReviewService::updateData(const ReviewListDTO::Wrapper& dto)
{
	// 组装DO数据
	ReviewDO data;
	//person_name  hazard_factor_code不在该表，无法修改 swagger上显示的这两个字段，可以直接无视
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CheckProjectId, checkProjectId, CheckProjectName, checkProjectName, ReviewExplain, reviewExplain, ReviewTime, reviewTime, CreateTime, createTime, State, state, Id, id)
	// 执行数据修改
	ReviewDAO dao;
	return dao.update(data) == 1;
}
// 通过ID删除数据
bool ReviewService::removeData(string id)
{
	ReviewDAO dao;
	return dao.deleteById(id) == 1;
}