#ifndef _SAMPLEBARCODESVIEW_DAO_
#define _SAMPLEBARCODESVIEW_DAO_
#include "BaseDAO.h"
#include"domain/do/samplebarcodesview/SampleBarcodesViewDO.h"
/*
* ��ѯ�����������ʵ��
*/
class SampleBarcodesViewDAO : public BaseDAO
{
public:
	//��ѯ��������
	list<SampleBarcodesViewDO> querySampleBarcodesView(const string& person_id,const string& group_item_id,const int& type);
};
#endif // !_SAMPLEBARCODESVIEW_DAO_
