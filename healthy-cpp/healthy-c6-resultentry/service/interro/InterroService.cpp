#include"InterroService.h"
#include"stdafx.h"
#include"../../dao/interro/InterroDAO.h"

uint64_t InterroService::saveData(const InterroDTO::Wrapper& dto) {
	//组装DO数据
	InterroDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, 
		Type, type,
		Project, project, 
		Code, code,
		Degree, degree,
		Coursetime, coursetime, 
		Personid, personid,
		Createid, createid,
		Createname, createname
		);
	//执行数据添加
	InterroDAO dao;
	return dao.insert(data);
}
