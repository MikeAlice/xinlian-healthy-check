#include "PrintMoreController.h"
#include "../../service/printmore/PrintMoreService.h"
#include "stdafx.h"
ResultJsonVO::Wrapper PrintMoreController::execDownloadPrintMore(const List<PrintMoreDTO::Wrapper>& dto)
{
	// ���巵�����ݶ���

	auto jvo = ResultJsonVO::createShared();
	PrintMoreService service;

	auto res = ResultDTO::createShared();
	// ����У��
	bool succ = true;

	// �ǿ�У��
	for (auto iter = dto->begin(); iter != dto->end(); iter++) {
		if ((*iter)->id)
		{
			String str = service.downloadPrintMore((*iter)->id);
			res->addData(str);
		}
		else {
			String str = "";
			res->addData(str);
		}
	}

	//��Ӧ���
	if (succ) jvo->success(res);
	else jvo->fail(res);

	return jvo;
}