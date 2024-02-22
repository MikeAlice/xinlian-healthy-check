#pragma once

#ifndef _UP_FILE_CONTROLLER_
#define _UP_FILE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/dto/file_chengfeng/UpFileDTO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���������޸Ľӿ�
 */
class UpFileController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UpFileController);
	// 3 ����ӿ�
public:
	
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("file_chengfeng.upload.summary"), modifySample, StringJsonVO::Wrapper);
	
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/resultentry/filexxx/uploadxxx", modifySample, BODY_DTO(UpFileDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));


private:	
	// 3.3 �޸�����
	StringJsonVO::Wrapper execModifySample(const UpFileDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_UP_FILE_CONTROLLER_