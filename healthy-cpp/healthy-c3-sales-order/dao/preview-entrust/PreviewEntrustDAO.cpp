#include "stdafx.h"
#include "PreviewEntrustDAO.h"
#include <string>
#include "PreviewEntrustMapper.h"


std::list<PreviewEntrustUrlDO> PreviewEntrustDAO::selectUrl(const std::string& orderId)
{
	std::string sql = "SELECT order_path FROM t_group_order WHERE id=?;";
	MapperUrl mapper;
	return sqlSession->executeQuery<PreviewEntrustUrlDO, MapperUrl>(sql, mapper, "%s", orderId);
}

std::list<PreviewEntrustInfoDO> PreviewEntrustDAO::selectInfo(const std::string& orderId)
{
	std::string sql = "SELECT order.order_code, order.group_unit_name, unit.link_man2, unit.link_phone2, "
		"order.signing_time, order.delivery_time FROM `t_group_order` as `order` "
		"JOIN `t_group_unit` as `unit` ON order.group_unit_id = unit.id "
		"WHERE order.id = ?;";
	MapperInfo mapper;
	return sqlSession->executeQuery<PreviewEntrustInfoDO, MapperInfo>(sql, mapper, "%s", orderId);
}

int PreviewEntrustDAO::updateUrl(const std::string& orderId, const std::string& url)
{
	std::string sql = "UPDATE `t_group_order` SET `order_path`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s", url, orderId);
}
