#pragma once
#ifndef _REVIEW_DAO_
#define _REVIEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/review/ReviewDO.h"
#include "../../domain/query/review/ReviewQuery.h"

/**
 * �����¼�����ݿ����ʵ��
 */
class ReviewDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReviewQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ReviewDO> selectWithPage(const ReviewQuery::Wrapper& query);
	// pdfʹ�� ͨ��������ѯ����
	list<ReviewDO> selectByName(const string& name);
	// �޸�����
	int update(const ReviewDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_REVIEW_DAO_