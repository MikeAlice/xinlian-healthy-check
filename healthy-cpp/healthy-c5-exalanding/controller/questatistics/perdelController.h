#ifndef _PERDEL_CONTROLLER_H_
#define _PERDEL_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class perdelController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(perdelController);
public:	// 定义接口

	// 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("questatistics.remove.summary"), removePersonList, Uint64JsonVO::Wrapper);
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/questatistics/remove-personList", removePersonList, BODY_STRING(String, id), execRemovePerson(id));

private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execRemovePerson(const string& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PERDEL_CONTROLLER_H_
