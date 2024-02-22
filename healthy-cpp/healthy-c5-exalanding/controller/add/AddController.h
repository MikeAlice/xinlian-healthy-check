#pragma once
#ifndef _ADDCONTROLLER_H_
#define _ADDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/add/AddVo.h"
#include "../../domain/query/add/AddUnit.h"
#include "../../domain/dto/add/AddUnitDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class AddController :public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(AddController);
	//����ӿ�
public:
	/*
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryAdd) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AddPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("use.field.type"), 12334, false);
		//���֤��
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("use.field.id"), 2345, false);
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "u_name", ZH_WORDS_GETTER("use.field.u_name"), "2345", false);
		//�Ա�
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("use.field.sex"), "2345", false);
		//����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("use.field.age"), 1, false);
		//��ϵ�绰
		API_DEF_ADD_QUERY_PARAMS(UInt32, "linkPhone", ZH_WORDS_GETTER("use.field.linkPhone"), 1, false);
		//��λ����
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("use.field.name"), "2345", false);
		//����״̬
		API_DEF_ADD_QUERY_PARAMS(String, "marriage", ZH_WORDS_GETTER("use.field.marriage"), "2345", false);
		//��������
		API_DEF_ADD_QUERY_PARAMS(String, "g_name", ZH_WORDS_GETTER("use.field.g_name"), "2345", false);
	}

	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/add/query-add", queryAdd, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME){
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, AddUnit, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAdd(uq));
	}
	*/

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addUnit) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/updata-unit", addUnit, BODY_DTO(AddUnitDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddUnit(dto));
	}

	//����ӿ�ִ�к���
private:
	AddPageJsonVO::Wrapper execQueryAdd(const AddUnit::Wrapper& query);

	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddUnit(const AddUnitDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController)

#endif