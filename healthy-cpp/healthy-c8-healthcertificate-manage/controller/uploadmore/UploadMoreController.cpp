#include "UploadMoreController.h"
#include "service/uploadmore/UploadMoreService.h"

StringJsonVO::Wrapper UploadMoreController::execUploadHealthCertificates(const List<UploadMoreDTO::Wrapper>& dtoArray)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	auto& dtos = *dtoArray.get();
	//遍历dtoArray
	for (auto i = dtos.begin(); i != dtos.end(); i++)
	{
		UploadMoreDTO::Wrapper dto = *i;
		// 参数校验
		if (!dto->personId)
		{
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		UploadMoreService service;
		UploadMoreDTO::Wrapper  returndto = service.UploadHealthcertificate(dto->personId);
		if (returndto->personId != "null")
			jvo->success(dto->personId);
		else
			jvo->fail(dto->personId);
	}
	return jvo;
}