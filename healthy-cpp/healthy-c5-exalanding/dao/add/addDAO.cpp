#include "stdafx.h"
#include "addDAO.h"
#include <sstream>
#include <SnowFlake.h>

uint64_t addDAO::insert(const addDO& iObj)
{
	SnowFlake sf(1,2);
	
	
	//sql << "INSERT INTO `t_group_person`  (`id`, `id_card`, `sex`, `age`,`person_name`,`work_name`,`mobile`,`is_marry`,`dept`,`is_pass`,`physical_type`) VALUES (" << sf.nextId() <<", ? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";
	string sql = "INSERT INTO `t_group_person`  (`id`, `id_card`, `sex`, `age`,`person_name`,`work_name`,`mobile`,`is_marry`,`dept`,`is_pass`,`physical_type`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	
	return sqlSession->executeInsert(sql, "%i%i%s%i%s%s%i%s%s%i%s",sf.nextId(), iObj.getIdCard(), iObj.getSex(), iObj.getAge(), \
		iObj.getU_Name(), iObj.getName(), iObj.getLinkPhone(), iObj.getMarriage(), iObj.getG_name(),iObj.getIs_pass(),iObj.getType());
}