#pragma once
#pragma once
#ifndef _GETPD_SERVICE_
#define _GETPD_SERVICE_
#include <list>
#include "domain/vo/GetPD/GetPDVO.h"
#include "domain/query/GetPD/GetPDQuery.h"
#include "domain/dto/GetPD/GetPDDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GetPDService
{
public:
	// ��ҳ��ѯ��������
	GetPDPageDTO::Wrapper listAll(const GetPDQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_