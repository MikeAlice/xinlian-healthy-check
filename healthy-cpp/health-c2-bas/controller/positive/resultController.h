#ifndef _RESULTCONTROLLER_H_
#define _RESULTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/positive/resultListVO.h"
#include "../../domain/query/positive/resultListQuery.h"
#include "../../domain/dto/positive/resultListDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class resultController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(resultController);
public: // ����ӿ�

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryResultList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("positive.result.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(resultListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("positive.result.field.id"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "condition", ZH_WORDS_GETTER("positive.result.field.condition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "genderAppropriate", ZH_WORDS_GETTER("positive.result.field.genderAppropriate"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positiveId", ZH_WORDS_GETTER("positive.result.field.positiveId"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "judgmentCondition", ZH_WORDS_GETTER("positive.result.field.judgmentCondition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "excludePositive", ZH_WORDS_GETTER("positive.result.field.excludePositive"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("positive.result.field.type"), "xxx", false);
		
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/positive/query-resultList", queryResultList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(resQuery, resultListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryResult(resQuery,authObject->getPayload()));
	}

	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeSample) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("positive.remove.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("positive.remove.field.id"), 1, true);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/positive/{id}", removeSample, PATH(UInt64, id), execRemoveResult(id));


private: // ����ӿ�ִ�к���
	resultListJsonVO::Wrapper execQueryResult(const resultListQuery::Wrapper& id, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execRemoveResult(const UInt64& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESULTCONTROLLER_H_