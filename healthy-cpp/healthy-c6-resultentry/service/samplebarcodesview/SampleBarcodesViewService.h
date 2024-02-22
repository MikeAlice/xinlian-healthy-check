#ifndef _SAMPLEBARCODESVIEW_SERVICE_
#define _SAMPLEBARCODESVIEW_SERVICE_
#include"domain/query/samplebarcodesview/SampleBarcodesViewQuery.h"
#include"domain/dto/samplebarcodesview/SampleBarcodesViewDTO.h"
/*
* 样本条码查看服务
*/
class SampleBarcodesViewServer
{
public:
	//样本条码查看
	oatpp::List<SampleBarcodesViewDTO::Wrapper> barcodesview(const SampleBarcodesViewQuery::Wrapper& qdto, const PayloadDTO& payload);
};

#endif // !_SAMPLEBARCODESVIEW_SERVICE_
