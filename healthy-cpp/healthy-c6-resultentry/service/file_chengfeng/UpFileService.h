#pragma once
#ifndef _UP_FILE_SERVICE_
#define _UP_FILE_SERVICE_
#include <list>
#include "domain/dto/file_chengfeng/UpFileDTO.h"

/**
 * �޸Ĺ��ܵķ���ʵ��
 */
class UpFileService
{
public:
		
	// �޸�����
	bool updateData(const UpFileDTO::Wrapper& dto,const string download, const PayloadDTO& payload);
	

};

#endif // !_UP_FILE_SERVICE_
