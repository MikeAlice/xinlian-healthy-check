#ifndef _SAMPLEBARCODESVIEW_DAO_
#define _SAMPLEBARCODESVIEW_DAO_
#include "BaseDAO.h"
#include"domain/do/samplebarcodesview/SampleBarcodesViewDO.h"
/*
* 查询样本条码操作实现
*/
class SampleBarcodesViewDAO : public BaseDAO
{
public:
	//查询样本条码
	list<SampleBarcodesViewDO> querySampleBarcodesView(const string& person_id,const string& group_item_id,const int& type);
};
#endif // !_SAMPLEBARCODESVIEW_DAO_
