#include "stdafx.h"
#include "UpFileService.h"
#include "../../dao/file_chengfeng/UpFileDAO.h"


bool UpFileService::updateData(const UpFileDTO::Wrapper& dto,const string download, const PayloadDTO& payload)
{
	// ��װDO����
	UpFileDO data;
	 	//data.setId(dto->id.getValue(""));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Person_id, person_id)
	
		// ִ�������޸�
		UpFileDAO dao;
	return dao.update(data, download) == 1;
}


