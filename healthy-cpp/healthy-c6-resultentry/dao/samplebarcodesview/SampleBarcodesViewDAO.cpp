#include "stdafx.h"
#include "SampleBarcodesViewDAO.h"
#include"SampleBarcodesViewMapper.h"

list<SampleBarcodesViewDO> SampleBarcodesViewDAO::querySampleBarcodesView(const string& person_id, const string& group_item_id, const int& type)
{
	string sql="SELECT t2.age,t1.barcode,t1.group_item_id,t2.person_name,t2.sex,t2.test_num FROM t_barcode t1 LEFT JOIN t_group_person t2 ON t1.test_num = t2.test_num WHERE t1.person_id = ? AND t1.group_item_id = ? AND t1.type = ?";
	SampleBarcodesViewMapper mapper;
	return sqlSession->executeQuery<SampleBarcodesViewDO, SampleBarcodesViewMapper>(sql, mapper, "%s%s%ll", person_id, group_item_id,type);
		

}
