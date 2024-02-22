#include "stdafx.h"
#include "Controller.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/xiebao/DeleteTBPService.h"
#include "../../service/xiebao/UpdateTBPService.h"

Uint64JsonVO::Wrapper XiebaoController::execDelTBP(const DeleteTBPDTO::Wrapper& dto)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();
    // 参数校验
    if (!dto->code)
    {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // 定义一个Service
    DeleteTBPService service;
    // 执行数据删除
    uint64_t id = service.DeleteTBP(dto);
    if (id) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // 响应结果
    return jvo;
}

Uint64JsonVO::Wrapper XiebaoController::execUpdateTBP(const UpdateTBPDTO::Wrapper& dto)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();
    // 参数校验
    if (!dto->code)
    {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // 定义一个Service
    UpdateTBPService service;
    // 执行数据修改
    uint64_t id = service.updateTBP(dto);
    if (id) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // 响应结果
    return jvo;
}
