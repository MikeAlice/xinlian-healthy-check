#include "PrintConfirmController.h"
#include "stdafx.h"
#include "../../service/printconfirm/PrintConfirmService.h"
StringJsonVO::Wrapper PrintConfirmController::execModifyPrintConfirm(const List<String>& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	auto& id = *dto.get();

	for (auto i = id.begin(); i != id.end(); i++)
	{
		String orderid = *i;
		// ����У��
		if (!orderid)
		{
			jvo->init(String("wrong"), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		PrintConfirmService service;

		// ִ�������޸�
		if (service.updateData(orderid)) {
			jvo->success(orderid);
		}
		else
		{
			jvo->fail(orderid);

		}
	}
	// ��Ӧ���
	return jvo;
}
