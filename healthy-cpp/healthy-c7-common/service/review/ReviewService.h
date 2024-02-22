#pragma once
#ifndef _REVIEW_SERVICE_
#define _REVIEW_SERVICE_
#include <list>
#include "domain/vo/review/ReviewVO.h"
#include "domain/query/review/ReviewQuery.h"
#include "domain/dto/review/ReviewListDTO.h"
#include "../../dao/review/ReviewDAO.h"
/**
 * 基础的复查记录服务实现
 */
class ReviewService
{
public:
	// 分页查询所有数据
	ReviewListPageDTO::Wrapper listAll(const ReviewQuery::Wrapper& query);
	// Pdf使用
	ReviewListDTO::Wrapper listByName(const ReviewQuery::Wrapper& query);
	// 修改数据
	bool updateData(const ReviewListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(string id);
};

#endif // !_REVIEW_SERVICE_