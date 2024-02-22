#include "RPProCheckDAO.h"

uint64_t RPProCheckDAO::insert(const RPProCheckDO& iObj)
{
	string sql = "INSERT INTO `relation_person_project_check` "
		"(`id`, `person_id`, `office_id`, `state`, `order_group_item_id`)"
		"VALUES(? , ? , ? , ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s", \
		iObj.getId(), iObj.getPersonId(), iObj.getOfficeId(), iObj.getState(),iObj.getGroupItemId());
}

int RPProCheckDAO::update(const RPProCheckDO& uObj)
{
	string sql = "UPDATE `relation_person_project_check` "
		"SET `state`=? WHERE `person_id`=? AND `office_id`=? AND `order_group_item_id`=?";
	return sqlSession->executeUpdate(sql, "%i%s%s%s", uObj.getState(), uObj.getPersonId(), uObj.getOfficeId(), uObj.getGroupItemId());
}
