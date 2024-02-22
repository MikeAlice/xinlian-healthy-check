#include "BaseProjectController.h"
#include "../../service/baseproject/AddBaseProject/AddBaseProjectService.h"
#include "../../service/baseproject/SelectBaseProject/SelectBaseProjectService.h"
#include "../../service/baseproject/SelectBaseProjectList/SelectBaseProjectListService.h"

Uint64JsonVO::Wrapper BaseProjectController::execAddBaseProject(const AddBaseProjectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ����һ��Service
	AddBaseProjectService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (!id) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

SelectBaseProjectPageJsonVO::Wrapper BaseProjectController::execSelectBaseProject(const SelectBaseProjectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	SelectBaseProjectService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
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

