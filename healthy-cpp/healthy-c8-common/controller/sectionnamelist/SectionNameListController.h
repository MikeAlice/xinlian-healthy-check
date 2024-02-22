#pragma once
#ifndef _SectionNameListController_
#define _SectionNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/sectionnamelist/SectionNameListDTO.h"
#include "domain/vo/sectionnamelist/SectionNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class SectionNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SectionNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(querySectionNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sectionnamelist.query-sectionnamelist.summary"), SectionNameListJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-sectionnamelist", querySectionNameList, execQuerySectionNameList(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������2
	SectionNameListJsonVO::Wrapper execQuerySectionNameList(const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif