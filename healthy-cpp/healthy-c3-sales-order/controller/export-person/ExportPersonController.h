#pragma once

#ifndef _ORDEROUTPUT_CONTROLLER_
#define _ORDEROUTPUT_CONTROLLER_
#include"../../domain/dto/export-person/ExportPersonDTO.h"
#include"../../domain/vo/export-person/ExportPersonVO.h"
#include"../../domain/query/export-person/ExportPersonQuery.h"
#include"domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExportPersonController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ExportPersonController);
public:
	ENDPOINT_INFO(exportPerson) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.export-person.summary"), Void);
		//����id
		API_DEF_ADD_QUERY_PARAMS(String, "orderId", ZH_WORDS_GETTER("person.field.order_id"), "", true);
		//�Ƿ�ͨ�����(0-δ�Ǽ�, 1-�Ǽ�, 2-�ڼ�, 3-�ܼ�, 4-�����)
		API_DEF_ADD_QUERY_PARAMS(Int32, "isPass", ZH_WORDS_GETTER("person.field.is_pass"),0,false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "sales/order/export-person", exportPerson, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(uq, ExportPersonQuery, params);
		return execExportPerson(uq);
	}
	
private:
	std::shared_ptr<OutgoingResponse> execExportPerson(const ExportPersonQuery::Wrapper& query);
	
};
#include OATPP_CODEGEN_END(ApiController)
#endif
