#include "stdafx.h"
#include "Controller.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/xiebao/DeleteTBPService.h"
#include "../../service/xiebao/UpdateTBPService.h"

Uint64JsonVO::Wrapper XiebaoController::execDelTBP(const DeleteTBPDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();
    // ����У��
    if (!dto->code)
    {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    DeleteTBPService service;
    // ִ������ɾ��
    uint64_t id = service.DeleteTBP(dto);
    if (id) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // ��Ӧ���
    return jvo;
}

Uint64JsonVO::Wrapper XiebaoController::execUpdateTBP(const UpdateTBPDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();
    // ����У��
    if (!dto->code)
    {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    UpdateTBPService service;
    // ִ�������޸�
    uint64_t id = service.updateTBP(dto);
    if (id) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // ��Ӧ���
    return jvo;
}
