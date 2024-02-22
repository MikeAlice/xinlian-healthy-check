#ifndef _REPORTDTO_H_
#define _REPORTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 示例传输对象
 */
class ReportDTO : public oatpp::DTO
{
	DTO_INIT(ReportDTO, DTO);
	//报告编号
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("uint.code"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, phyType, ZH_WORDS_GETTER("uint.phyType"));
	//体检单位
	API_DTO_FIELD_DEFAULT(String, phyUnit, ZH_WORDS_GETTER("uint.phyUnit"));
	//委托单位
	API_DTO_FIELD_DEFAULT(String, enUnit, ZH_WORDS_GETTER("uint.enUnit"));
	//报告日期
	API_DTO_FIELD_DEFAULT(String, phyDate, ZH_WORDS_GETTER("uint.phyDate"));
	//体检人数
	API_DTO_FIELD_DEFAULT(Int32, phyNum, ZH_WORDS_GETTER("uint.phyNum"));
	//危害因素
	API_DTO_FIELD_DEFAULT(String, hazFactor, ZH_WORDS_GETTER("uint.hazFactor"));
	//体检项目
	API_DTO_FIELD_DEFAULT(String, phyProj, ZH_WORDS_GETTER("uint.phyProj"));
	//评论依据
	API_DTO_FIELD_DEFAULT(String, evalBasis, ZH_WORDS_GETTER("uint.evalBasis"));
	//体检结论及处理意见
	API_DTO_FIELD_DEFAULT(String, phyConclusion, ZH_WORDS_GETTER("uint.phyConclusion"));

	//下载地址
	API_DTO_FIELD_DEFAULT(String, downloadAddr, ZH_WORDS_GETTER("uint.downloadAddr"));

};

#include OATPP_CODEGEN_END(DTO)
#endif 


