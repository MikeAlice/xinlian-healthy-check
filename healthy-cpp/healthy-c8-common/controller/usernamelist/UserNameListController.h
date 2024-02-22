#pragma once
#ifndef _UserNameListController_
#define _UserNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/usernamelist/UserNameListDTO.h"
#include "domain/vo/usernamelist/UserNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class UserNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UserNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryUserNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("usernamelist.query-usernamelist.summary"), UserNameListJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-usernamelist", queryUserNameList, execQueryUserNameList(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	UserNameListJsonVO::Wrapper execQueryUserNameList(const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif