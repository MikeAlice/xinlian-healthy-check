#pragma once
#ifndef _TERM_DAO_
#define _TERM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/term/TermListDO.h"
#include "../../domain/query/term/TermQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class TermListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TermQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<TermListDO> selectWithPage(const TermQuery::Wrapper& query);
	// ͨ������ID��ѯ����
	list<TermListDO> selectByOfficeId(const string& officeId);
	// ��������
	uint64_t insert(const TermListDO& iObj);
	// �޸�����
	int update(const TermListDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_TERM_DAO_