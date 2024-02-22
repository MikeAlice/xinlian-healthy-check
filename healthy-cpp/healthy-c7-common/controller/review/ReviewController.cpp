#include "stdafx.h"
#include "ReviewController.h"
#include "../../service/review/ReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

ReviewListPageJsonVO::Wrapper ReviewController::execQueryReview(const ReviewQuery::Wrapper& query)
{
	// 定义一个Service
	ReviewService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReviewListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//PDF
ReviewJsonVO::Wrapper ReviewController::execQueryPdf(const ReviewQuery::Wrapper& query)
{
	// 定义一个Service
	ReviewService service;
	// 查询数据
	auto result = service.listByName(query);
	auto jvo = ReviewJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 修改数据
StringJsonVO::Wrapper ReviewController::execModifyReview(const ReviewListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ReviewService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}
// 删除数据
StringJsonVO::Wrapper ReviewController::execRemoveReview(const String& id)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ReviewService service;
	// 执行数据删除
	if (service.removeData(id.getValue(""))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}