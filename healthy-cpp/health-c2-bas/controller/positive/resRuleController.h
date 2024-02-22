#ifndef _RESRULECONTROLLER_H_
#define _RESRULECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/positive/resRuleListVO.h"
#include "../../domain/vo/positive/ruleListVO.h"
#include "../../domain/query/positive/resRuleListQuery.h"
#include "../../domain/query/positive/ruleListQuery.h"
#include "../../domain/dto/positive/resRuleListDTO.h"
#include "../../domain/dto/positive/ruleListDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class resRuleController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(resRuleController);
public: // ����ӿ�
	// �����ѯ��������б�ӿ�����
	ENDPOINT_INFO(queryResRuleList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("positive.resRules.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(resRuleListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("positive.resRules.field.id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "condition", ZH_WORDS_GETTER("positive.resRules.field.condition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "genderAppropriate", ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate"), "genderAppropriate", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positiveId", ZH_WORDS_GETTER("positive.resRules.field.positiveId"), "positiveId", false);
		API_DEF_ADD_QUERY_PARAMS(String, "judgmentCondition", ZH_WORDS_GETTER("positive.resRules.field.judgmentCondition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "excludePositive", ZH_WORDS_GETTER("positive.resRules.field.excludePositive"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("positive.resRules.field.type"), "xxx", false);
	}
	// �����ѯ��������б�ӿ�
	ENDPOINT(API_M_GET, "/positive/query-resRuleList", queryResRuleList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(resQuery, resRuleListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryResRule(resQuery));
	}
	// �����ѯ��������Ӧ�����Թ����б�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("positive.rules.query.summary"), queryRuleList, Uint64JsonVO::Wrapper);
	// ����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "positive/query-ruleList", queryRuleList, BODY_STRING(String, id), execQueryRule(id));

	// ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("positive.resRules.remove.summary"), removeResRuleList, Uint64JsonVO::Wrapper);
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "positive/remove-resRuleList", removeResRuleList, BODY_STRING(String, id), execRemoveResRule(id));

	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("positive.resRules.modify.summary"), modifyResRuleList, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "positive/modify-resRuleList", modifyResRuleList, BODY_DTO(rulePageDTO::Wrapper, dto), execModifyResRule(dto));
	
private: // ����ӿ�ִ�к���
	resRuleListJsonVO::Wrapper execQueryResRule(const resRuleListQuery::Wrapper& query); 
	resRuleListJsonVO::Wrapper execQueryRule(const String& id);
	Uint64JsonVO::Wrapper execRemoveResRule(const String& id);
	Uint64JsonVO::Wrapper execModifyResRule(const rulePageDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESRULECONTROLLER_H_