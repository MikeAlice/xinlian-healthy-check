#pragma once
#ifndef _TERM_SERVICE_
#define _TERM_SERVICE_
#include <list>
#include "domain/vo/term/TermVO.h"
#include "domain/query/term/TermQuery.h"
#include "domain/dto/term/TermListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class TermService
{
public:
	// ��ҳ��ѯ��������
	TermListPageDTO::Wrapper listAll(const TermQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const TermListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const TermListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_TERM_SERVICE_