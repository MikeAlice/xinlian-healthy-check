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
    // ����������������
    API_ACCESS_DECLARE(XiebaoController);
public:// ����ӿ�

    // 3.1 ���������ӿ�����
    ENDPOINT_INFO(delTBP) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("delTBP"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 3.2 ���������ӿڴ���
    ENDPOINT(API_M_DEL, "/combo/del-TBP", delTBP, BODY_DTO(DeleteTBPDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execDelTBP(dto));
    }

    // 3.1 ���������ӿ�����
    ENDPOINT_INFO(updateTBP) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("updateTBP"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 3.2 ���������ӿڴ���
    ENDPOINT(API_M_POST, "/combo/update-TBP", updateTBP, BODY_DTO(UpdateTBPDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execUpdateTBP(dto));
    }
private:// ����ӿ�ִ�к���
    //ɾ������
    Uint64JsonVO::Wrapper execDelTBP(const DeleteTBPDTO::Wrapper& dto);
    //�޸�����
    Uint64JsonVO::Wrapper execUpdateTBP(const UpdateTBPDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _CONTROLLER_H_