#ifndef _SAMPLEBARCODESVIEW_DO_
#define _SAMPLEBARCODESVIEW_DO_
#include "../DoInclude.h"

/*
* �����������ݿ�ʵ����
*/
class SampleBarcodesViewDO
{
	//����������
	CC_SYNTHESIZE(string, barcode, Barcode);
	//�����
	CC_SYNTHESIZE(string, test_num, Test_num);
	//�����Ա����
	CC_SYNTHESIZE(string, person_name, Person_name);
	//�����Ա����
	CC_SYNTHESIZE(int, age, Age);
	//�����Ա�Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	//������Ŀ����
	CC_SYNTHESIZE(string, group_item_name, Group_item_name);
public:
	SampleBarcodesViewDO() {
		barcode = "";
		test_num = "";
		person_name = "";
		age = 0;
		sex = "";
		group_item_name = "";

	}
};




#endif // !_SAMPLEBARCODESVIEW_DO_
