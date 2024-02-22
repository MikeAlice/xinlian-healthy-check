#pragma once

#ifndef _COMBOCONTROLLER_H_
#define _COMBOCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/combo/AddPackVO.h"
#include "domain/vo/combo/DelPackVO.h"
#include "domain/vo/combo/UpdatePackVO.h"
#include "../../service/combo/addPack/AddPackService.h"
#include "../../service/combo/delPack/DelPackService.h"
#include "../../service/combo/updatePack/UpdatePackService.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ComboController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ComboController);
public:// 定义接口

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addPack) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("combo.addPack"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/combo/add-pack", addPack, BODY_DTO(AddPackDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddPack(dto));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(delPack) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("combo.delPack"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_DEL, "/combo/del-pack", delPack, BODY_DTO(DelPackDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execDelPack(dto));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(updatePack) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("combo.updatePack"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/combo/update-pack", updatePack, BODY_DTO(UpdatePackDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execUpdatePack(dto));
	}
private:// 定义接口执行函数
	//新增数据
	Uint64JsonVO::Wrapper execAddPack(const AddPackDTO::Wrapper& dto);
	//删除数据
	Uint64JsonVO::Wrapper execDelPack(const DelPackDTO::Wrapper& dto);
	//修改数据
	Uint64JsonVO::Wrapper execUpdatePack(const UpdatePackDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _COMBOCONTROLLER_H_