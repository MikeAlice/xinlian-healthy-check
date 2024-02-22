#pragma once
#ifndef _REFERENCEMODSERVICE_H_
#define _REFERENCEMODSERVICE_H_
#include <list>
#include "domain/vo/base/ReferenceModVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/base/ReferenceModDTO.h"

/**
 * �޸ķ���ʵ��
 */
class ReferenceModService
{
public:
	
	// ��������
	uint64_t saveData(const ReferenceModDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ReferenceModDTO::Wrapper& dto);
	
};

#endif // !_REFERENCEMODSERVICE_H_