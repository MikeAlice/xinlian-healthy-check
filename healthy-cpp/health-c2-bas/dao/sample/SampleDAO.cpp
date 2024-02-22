#include "stdafx.h"
#include "SampleDAO.h"
#include "SampleMapper.h"
#include <sstream>

int SampleDAO::update(const SampleDO & uObj) {

	string sql = "UPDATE `t_sample` SET `name`=?, `spec`=?, `code`=?, `is_print`=?, `capacity`=?, `need_take_blood`=?, `order_num`=?, `liscode`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%i%d%s%s", uObj.getName(), uObj.getSpec(), uObj.getCode(), uObj.getIs_print(), uObj.getCapacity(), uObj.getNeed_take_blood(), uObj.getOrder_num(), uObj.getLiscode(), uObj.getId());

}