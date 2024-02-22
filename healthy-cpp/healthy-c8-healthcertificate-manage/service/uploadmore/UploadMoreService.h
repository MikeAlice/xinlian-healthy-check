#pragma once
#ifndef _UPLOADMORE_SERVICE_
#define _UPLOADMORE_SERVICE_
#include "domain/dto/uploadmore/UploadMoreDTO.h"

/**
 * 健康证批量服务实现
 */
class UploadMoreService
{
public:
	// 通过人员id批量上传健康证
	UploadMoreDTO::Wrapper  UploadHealthcertificate(const string& personId);

};

#endif 

