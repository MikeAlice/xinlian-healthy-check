#pragma once

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/xiebao/DeleteTBPVO.h"
#include "domain/vo/xiebao/UpdateTBPVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class XiebaoController : public oatpp::web::server::api::ApiController
{
    // 定义控制器访问入口
    API_ACCESS_DECLARE(XiebaoController);
public:// 定义接口

    // 3.1 定义新增接口描述
    ENDPOINT_INFO(delTBP) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("delTBP"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 3.2 定义新增接口处理
    ENDPOINT(API_M_DEL, "/combo/del-TBP", delTBP, BODY_DTO(DeleteTBPDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execDelTBP(dto));
    }

    // 3.1 定义新增接口描述
    ENDPOINT_INFO(updateTBP) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("updateTBP"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 3.2 定义新增接口处理
    ENDPOINT(API_M_POST, "/combo/update-TBP", updateTBP, BODY_DTO(UpdateTBPDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execUpdateTBP(dto));
    }
private:// 定义接口执行函数
    //删除数据
    Uint64JsonVO::Wrapper execDelTBP(const DeleteTBPDTO::Wrapper& dto);
    //修改数据
    Uint64JsonVO::Wrapper execUpdateTBP(const UpdateTBPDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _CONTROLLER_H_