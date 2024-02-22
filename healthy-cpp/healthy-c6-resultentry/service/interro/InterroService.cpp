#include"InterroService.h"
#include"stdafx.h"
#include"../../dao/interro/InterroDAO.h"

uint64_t InterroService::saveData(const InterroDTO::Wrapper& dto) {
	//��װDO����
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
	//ִ���������
	InterroDAO dao;
	return dao.insert(data);
}
