#include "stdafx.h"
#include "../../dao/base/ReferenceDelDAO.h"
#include "ReferenceDelService.h"
#include "../../domain/do/base/ReferenceDelDO.h"
#include "../../domain/dto/base/ReferenceModDTO.h"
//uint64_t ReferenceDelService::saveData(const ReferenceDelDTO::Wrapper& dto)
//{
//	return 0;
//}

bool ReferenceDelService::removeData(const ReferenceDelDTO::Wrapper& dto)
{

	ReferenceDelDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id)

	ReferenceDelDAO dao;
	return dao.deleteById(data) == 1;
}

