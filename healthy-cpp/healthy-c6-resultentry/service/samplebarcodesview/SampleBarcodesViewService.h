#ifndef _SAMPLEBARCODESVIEW_SERVICE_
#define _SAMPLEBARCODESVIEW_SERVICE_
#include"domain/query/samplebarcodesview/SampleBarcodesViewQuery.h"
#include"domain/dto/samplebarcodesview/SampleBarcodesViewDTO.h"
/*
* ��������鿴����
*/
class SampleBarcodesViewServer
{
public:
	//��������鿴
	oatpp::List<SampleBarcodesViewDTO::Wrapper> barcodesview(const SampleBarcodesViewQuery::Wrapper& qdto, const PayloadDTO& payload);
};

#endif // !_SAMPLEBARCODESVIEW_SERVICE_
