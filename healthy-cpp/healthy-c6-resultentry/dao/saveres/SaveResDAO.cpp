#include "SaveResDAO.h"
#include "../../domain/do/saveres/SaveResDO.h"


//string sql = "INSERT INTO `sample` (`id`, `project`, `degree`, `time`) VALUES(? , ? , ? , ? )";
//return sqlSession->executeInsert(sql, "%s%s%i", iObj.getId(), iObj.getProject(), iObj.getDegree(), iObj.getTime());

uint64_t SaveResDAO::insert(const SaveResDO& iObj)
{
	string sql = "INSERT INTO `t_depart_result` "
		"(`id`, `person_id`, `group_item_id`, `group_item_name`, `diagnose_tip`,"
		" `diagnose_sum`, `office_id`, `office_name`, `check_num`, `check_doc`, `check_date`, `del_flag`,"
		"`create_id`, `create_date`, `is_file`,`state`)"
		"VALUES(? , ? , ? , ?, ? , ? , ?, ? , ? , ?, ? , ? , ?, ? , ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%i%s%s%i%s%s%s%i",\
		iObj.getId(), iObj.getPersonId(), iObj.getGroupItemId(), iObj.getGroupItemName(),\
		iObj.getDiagnoseTip(), iObj.getDiagnoseSum(), iObj.getOfficeId(), iObj.getOfficeName(),\
		iObj.getCheck_num(), iObj.getCheckDoc(), iObj.getCheckDate(), iObj.getDelFlag(),\
		iObj.getCreateId(), iObj.getCreateDate(), iObj.getIsFile(), iObj.getState());
}

uint64_t SaveResDAO::insertItem(const SaveResDO& iObj)
{
	string sql = "INSERT INTO `t_depart_item_result`"
		"(`id`, `person_id`, `order_group_item_project_id`, `order_group_item_project_name`, `office_id`,"
		" `office_name`, `result`, `unit_code`, `unit_name`, `check_doc`, `check_date`, `crisis_degree`,"
		"`del_flag`, `create_id`, `create_date`,`ignore_status`,`depart_result_id`,"
		"`order_group_item_id`, `order_group_item_name`, `order_num`,`diagnose_sum`,`positive`)"
		"VALUES(? , ? , ? , ?, ? , ? , ?, ? , ? , ?, ? , ? , ?, ? , ?, ?, ?, ?, ? , ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%i%s%s%s%i%s%i", \
		iObj.getId(), iObj.getPersonId(), iObj.getOrderGroupItemProjectId(), iObj.getOrderGroupItemProjectName(),iObj.getOfficeId(), \
		iObj.getOfficeName(), iObj.getResult(), iObj.getUnitCode(), iObj.getUnitName(),iObj.getCheckDoc(),iObj.getCheckDate(), iObj.getCrisisDegree(),\
		iObj.getDelFlag(), iObj.getCreateId(), iObj.getCreateDate(), iObj.getIgnoreStatus(),iObj.getDepartResId(), \
		iObj.getGroupItemId(), iObj.getGroupItemName(), iObj.getOrderNum(), iObj.getDiagnoseSum(), iObj.getPositive());

}

int SaveResDAO::update(const SaveResDO& iObj)
{
	string sql = "UPDATE `t_depart_result` SET `check_doc`=?, `diagnose_tip`=?, `diagnose_sum`=?, `update_date`=?, `update_id`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", iObj.getCheckDoc(), iObj.getDiagnoseTip(), iObj.getDiagnoseSum(),\
		 iObj.getUpdateDate(), iObj.getCreateId(), iObj.getUpdateId());
}

int SaveResDAO::updateItem(const SaveResDO& iObj)
{
	string sql = "UPDATE `t_depart_item_result` SET `result`=?, `diagnose_sum`=?, `positive`=?,  `update_date`=?, `update_id`=? ,`check_doc`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s", iObj.getResult(), iObj.getDiagnoseSum(), iObj.getPositive(), iObj.getUpdateDate(),\
		iObj.getCreateId(), iObj.getCheckDoc(), iObj.getId());
}
