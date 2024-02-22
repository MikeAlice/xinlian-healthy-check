#pragma once
#ifndef _PICCONTROLLER_H_
#define _PICCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/Pic/PicVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class PicController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(PicController);
public:
	// ����һ���ļ��ϴ��ӿ����ڴ����ı��༭��
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.editor-upload-image.summary"), uploadImage, PicImageVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/Pic/Pic-upload-image", uploadImage, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadPicImage(request));
private: // ����ӿ�ִ�к���
	// ִ��EditorͼƬ�ϴ�����
	PicImageVO::Wrapper execUploadPicImage(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_