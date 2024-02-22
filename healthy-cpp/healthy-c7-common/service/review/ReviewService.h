#pragma once
#ifndef _REVIEW_SERVICE_
#define _REVIEW_SERVICE_
#include <list>
#include "domain/vo/review/ReviewVO.h"
#include "domain/query/review/ReviewQuery.h"
#include "domain/dto/review/ReviewListDTO.h"
#include "../../dao/review/ReviewDAO.h"
/**
 * �����ĸ����¼����ʵ��
 */
class ReviewService
{
public:
	// ��ҳ��ѯ��������
	ReviewListPageDTO::Wrapper listAll(const ReviewQuery::Wrapper& query);
	// Pdfʹ��
	ReviewListDTO::Wrapper listByName(const ReviewQuery::Wrapper& query);
	// �޸�����
	bool updateData(const ReviewListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);
};

#endif // !_REVIEW_SERVICE_