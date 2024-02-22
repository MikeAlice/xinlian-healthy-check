#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/Exalanding/FileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class FileController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FileController);
public:
	// ����һ�����ļ��ϴ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("exalanding.file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "Exalanding/uploadimage", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

private: // ����ӿ�ִ�к���
	// ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_