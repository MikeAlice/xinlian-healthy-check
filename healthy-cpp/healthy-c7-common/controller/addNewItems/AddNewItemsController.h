#pragma once
#ifndef _ADDNEWITEMSCONTROLLER_H_
#define _ADDNEWITEMSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"
#include "domain/vo/addNewItems/AddNewItemsVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 新增复查记录控制器，基础接口的使用
 */
class AddNewItemsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddNewItemsController);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAddNewItems) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addNewItems.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/review/post-addNewItems", addAddNewItems, BODY_DTO(AddNewItemsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAddNewItems(dto));
	}

private: //定义接口执行函数
	// 3.3 新增数据
	Uint64JsonVO::Wrapper execAddAddNewItems(const AddNewItemsDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_ADDNEWITEMSCONTROLLER_H_