#ifndef _SAMPLEBARCODESVIEW_DO_
#define _SAMPLEBARCODESVIEW_DO_
#include "../DoInclude.h"

/*
* 样本条码数据库实体类
*/
class SampleBarcodesViewDO
{
	//条形码内容
	CC_SYNTHESIZE(string, barcode, Barcode);
	//体检编号
	CC_SYNTHESIZE(string, test_num, Test_num);
	//体检人员名字
	CC_SYNTHESIZE(string, person_name, Person_name);
	//体检人员年龄
	CC_SYNTHESIZE(int, age, Age);
	//体检人员性别
	CC_SYNTHESIZE(string, sex, Sex);
	//分组项目名称
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
