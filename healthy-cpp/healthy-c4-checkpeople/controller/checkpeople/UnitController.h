#pragma once
#ifndef _UNITCONTROLLER_H_
#define _UNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/unitpeople/UnitPeopleVO.h"
#include "../../domain/query/unitpeople/UnitPeoPleQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitController : public oatpp::web::server::api::ApiController
{
	//1.����������������
	API_ACCESS_DECLARE(UnitController);

public:// ����ӿ� 
	//3.�����ѯ�ӿ�����
	ENDPOINT_INFO(queryUnit)
	{
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.query.summary"));
		//����Ĭ����Ȩ��������ѡ���壬��������ˣ������ENDPOINT��Ҫ����API_HANDLER_AUTH_PARAM��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPeoplePageJsonVO); //��Ӧ���Ƿ�ҳ��ѯ���ݵĸ�ʽ
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "idCard", ZH_WORDS_GETTER("unit.field.idCard"), "511321XXXXXXXXXXXX", true);
	}  

	//2.�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/query_people", queryUnit, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, UnitPeopleQuery, params);
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	}
private://����ӿ�ִ�к���
	//��ҳ��ѯ����
	UnitPeoplePageJsonVO::Wrapper execQueryUnit(const UnitPeopleQuery::Wrapper& query);
	
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_UNITCONTROLLER_H_