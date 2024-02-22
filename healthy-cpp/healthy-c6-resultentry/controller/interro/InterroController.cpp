#include "InterroController.h"
#include "stdafx.h"
#include"../../service/interro/InterroService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper InterroController::execAddInterro(const InterroDTO::Wrapper& dto) {
	//���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��
	//�ǿ�У�� TODO
	// if (!dto->id) {
	// 	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	// 	return jvo;
	// }
	//��ЧֵУ�� TODO
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty()) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//����һ��Service
	InterroService service;
	//ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	} else {
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
