#include "BaseProjectController.h"
#include "../../service/baseproject/AddBaseProject/AddBaseProjectService.h"
#include "../../service/baseproject/SelectBaseProject/SelectBaseProjectService.h"
#include "../../service/baseproject/SelectBaseProjectList/SelectBaseProjectListService.h"

Uint64JsonVO::Wrapper BaseProjectController::execAddBaseProject(const AddBaseProjectDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 定义一个Service
	AddBaseProjectService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (!id) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

SelectBaseProjectPageJsonVO::Wrapper BaseProjectController::execSelectBaseProject(const SelectBaseProjectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	SelectBaseProjectService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = SelectBaseProjectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

SelectBaseProjectListPageJsonVO::Wrapper BaseProjectController::execSelectBaseProjectList(const SelectBaseProjectListQuery::Wrapper& query, const PayloadDTO& payload)
{
	SelectBaseProjectListService service;
	auto result = service.listAll(query);
	auto jvo = SelectBaseProjectListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

