#pragma once
#ifndef _SAVERESITEM_DTO_
#define _SAVERESITEM_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SaveResItemDTO : public oatpp::DTO
{
	DTO_INIT(SaveResItemDTO, DTO);


	//// 公共部分
	//// 体检人id
	//API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	//// 科室id
	//API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	//// 科室名称
	//API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("save.filed.officeName"));
	//// 检查医生
	//API_DTO_FIELD_DEFAULT(String, checkDoc, ZH_WORDS_GETTER("save.filed.checkDoc"));
	//// 检查日期
	//API_DTO_FIELD(String, checkDate, ZH_WORDS_GETTER("save.filed.checkDate"), true, "2002-11-11");
	//// del flag
	//API_DTO_FIELD_DEFAULT(Int32, delFlag, ZH_WORDS_GETTER("save.filed.delFlag"));
	//// 分组项目id
	//API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));
	//// 分组项目名称
	//API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("save.filed.groupItemName"));
	//// 诊断小结
	//API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("save.filed.diagnoseSum"));
	//// 是否复查(0否1是）
	//API_DTO_FIELD_DEFAULT(Int32, isCheck, ZH_WORDS_GETTER("save.filed.isCheck"));



	// item depart res 部分

	// 关联的基础项目id
	API_DTO_FIELD(String, orderGroupItemProjectId, ZH_WORDS_GETTER("save.filed.orderGroupItemProjectId"), false, "");
	// 关联的基础项目名称
	API_DTO_FIELD_DEFAULT(String, orderGroupItemProjectName, ZH_WORDS_GETTER("save.filed.orderGroupItemProjectName"));
	// 体检结果
	API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("save.filed.result"));
	// 计量单位代码
	API_DTO_FIELD_DEFAULT(String, unitCode, ZH_WORDS_GETTER("save.filed.unitCode"));
	// 计量单位名称
	API_DTO_FIELD_DEFAULT(String, unitName, ZH_WORDS_GETTER("save.filed.unitName"));
	// 是否忽略异常（1-否，2-是）
	API_DTO_FIELD(Int32, ignoreStatus, ZH_WORDS_GETTER("save.filed.ignoreStatus"), false, 1);
	// 危急程度
	API_DTO_FIELD(String, crisisDegree, ZH_WORDS_GETTER("save.filed.crisisDegree"), false, u8"正常");
	// 阳性
	API_DTO_FIELD(Int32, positive, ZH_WORDS_GETTER("save.filed.positive"), false, 0);
	// 明细唯一id（仅在更改时有效）
	API_DTO_FIELD(String, itemId, ZH_WORDS_GETTER("save.filed.itemId"), false, "");

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVERESITEM_DTO_