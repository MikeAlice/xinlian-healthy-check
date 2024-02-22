#include "InfoListService.h"
#include "dao/Info-inspectionSave/InfoListDAO.h"

InfoListPageDTO::Wrapper InfoListService::listAll(const InfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = InfoListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	InfoListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<InfoListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (InfoListDO sub : result)
	{
		auto dto = InfoListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,id, Id, personId, PersonId, inspectionDoctor, InspectionDoctor, inspectionDate, InspectionDate
			, medicalAdvice, MedicalAdvice, handleOpinion, HandleOpinion);
			pages->addData(dto);

	}
	return pages;
}

uint64_t InfoListService::saveData(const InfoListDTO::Wrapper& dto)
{
	// 组装DO数据
	InfoListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, PersonId, personId, InspectionDoctor, inspectionDoctor, InspectionDate, inspectionDate
		, MedicalAdvice, medicalAdvice, HandleOpinion, handleOpinion)
		// 执行数据添加
		InfoListDAO dao;
	return dao.insert(data);
}

bool InfoListService::updateData(const InfoListDTO::Wrapper& dto)
{
	return false;
}

bool InfoListService::removeData(uint64_t id)
{
	return false;
}
