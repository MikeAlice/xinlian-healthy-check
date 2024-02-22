#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"domain/query/Exalanding/GroupOrderListQuery.h"
#include "domain/dto/Exalanding/GroupOrderListDTO.h"
#include "domain/do/Exalanding/GroupOrderListDO.h"
#include"domain/vo/Exalanding/GroupOrderVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GroupOrderListController : public oatpp::web::server::api::ApiController 
{
	// ����������������
	API_ACCESS_DECLARE(GroupOrderListController);
	// ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGroupOrder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("exalanding.get.summary"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupOrderListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("exalanding.field.sex"), "��", false);
		API_DEF_ADD_QUERY_PARAMS(String, "groupUnitName", ZH_WORDS_GETTER("exalanding.field.groupUnitName"), "xx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "groupName", ZH_WORDS_GETTER("exalanding.field.groupName"), "xx", false);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/exalanding", queryGroupOrder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(gq, GroupOrderListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGroupOrder(gq, authObject->getPayload()));
	}
private:
	// ��ҳ��ѯ����
	GroupOrderListPageJsonVO::Wrapper execQueryGroupOrder(const GroupOrderListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_