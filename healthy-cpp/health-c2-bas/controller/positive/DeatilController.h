
#ifndef __DEATIL_CONTROLLER__
#define __DEATIL_CONTROLLER__

#include "domain/query/positive/DeatilQuery.h"
#include "domain/dto/positive/DeatilDTO.h"
#include "domain/vo/positive/DeatilVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���Խ������������ȡ���Խ����ϸ
 */
class DeatilController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//������������ʽӿ�
	API_ACCESS_DECLARE(DeatilController);
	//  ����ӿ�
public:

	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDeatil) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deatil.get.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DeatilJsonVO);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("deatil.field.id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("deatil.field.name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "namePinYin", ZH_WORDS_GETTER("deatil.field.namePinYin"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "degree", ZH_WORDS_GETTER("deatil.field.degree"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positive", ZH_WORDS_GETTER("deatil.field.positive"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "section_name", ZH_WORDS_GETTER("deatil.field.section_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "advise", ZH_WORDS_GETTER("deatil.field.advise"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "healthKnowledge", ZH_WORDS_GETTER("deatil.field.healthKnowledge"), "N", false);
	}
	//�������Խ����ϸ��ѯ�ӿ�
	ENDPOINT(API_M_GET, "/positive/query-deatil", queryDeatil, QUERIES(QueryParams,params),API_HANDLER_AUTH_PARAME){
		//������ѯ���� 
		API_HANDLER_QUERY_PARAM(dq, DeatilQuery, params);
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDeatil(dq));
	}
private:
	DeatilJsonVO::Wrapper execQueryDeatil(const DeatilQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // __DEATIL_CONTROLLER__
