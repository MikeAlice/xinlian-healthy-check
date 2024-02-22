#pragma once
#ifndef _INTERRO_MAPPER_
#define _INTERRO_MAPPER_
#include"Mapper.h"
#include"../../domain/do/interro/InterroDO.h"

/**
* 字段匹配
*/
class InterroMapper : public Mapper<InterroDO> {
public:
	InterroDO mapper(ResultSet* resultSet) const override {
		InterroDO data;
		// 类别
		data.setType(resultSet->getString(1));
		// 体检项目
		data.setProject(resultSet->getString(2));
		// 项目编号
		data.setCode(resultSet->getString(3));
		// 危机程度
		data.setDegree(resultSet->getString(4));
		// 病程时间
		data.setCoursetime(resultSet->getString(5));
		// 人员编号主键
		data.setPersonid(resultSet->getString(6));
		// 创建人-体检医生
		data.setCreateid(resultSet->getString(7));
		//检查医生
		data.setCreatename(resultSet->getString(8));
		return data;
	}
};


#endif // !_INTERRO_MAPPER_
