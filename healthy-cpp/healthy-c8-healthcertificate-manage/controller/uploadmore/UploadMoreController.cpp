#include "UploadMoreController.h"
#include "service/uploadmore/UploadMoreService.h"

StringJsonVO::Wrapper UploadMoreController::execUploadHealthCertificates(const List<UploadMoreDTO::Wrapper>& dtoArray)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	auto& dtos = *dtoArray.get();
	//����dtoArray
	for (auto i = dtos.begin(); i != dtos.end(); i++)
	{
		UploadMoreDTO::Wrapper dto = *i;
		// ����У��
		if (!dto->personId)
		{
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		UploadMoreService service;
		UploadMoreDTO::Wrapper  returndto = service.UploadHealthcertificate(dto->personId);
		if (returndto->personId != "null")
			jvo->success(dto->personId);
		else
			jvo->fail(dto->personId);
	}
	return jvo;
}