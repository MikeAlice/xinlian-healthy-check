#ifndef _REPORTDO_H_
#define _REPORTDO_H_
#include "../DoInclude.h"

/*
 * 示例数据库实体类
 */
class ReportDO
{
	//报告编号
	CC_SYNTHESIZE(string, code, Code);
	//体检类型
	CC_SYNTHESIZE(string, phyType, PhyType);
	//体检单位
	CC_SYNTHESIZE(string, phyUnit, PhyUnit);
	//委托单位
	CC_SYNTHESIZE(string, enUnit, EnUnit);
	//报告日期
	CC_SYNTHESIZE(string, phyDate, PhyDate);
	//体检人数
	CC_SYNTHESIZE(int, phyNum, PhyNum);
	//危害因素
	CC_SYNTHESIZE(string, hazFactor, HazFactor);
	//体检项目
	CC_SYNTHESIZE(string, phyProj, PhyProj);
	//评论依据
	CC_SYNTHESIZE(string, evalBasis, EvalBasis);
	//体检结论及处理意见
	CC_SYNTHESIZE(string, phyConclusion, PhyConclusion);
public:
	ReportDO() {
		code = "";
		phyType = "";
		phyUnit = "";
		enUnit = "";
		phyDate = "";
		phyNum = 0;
		hazFactor = "";
		phyProj = "";
		evalBasis = "";
		phyConclusion = "";

	}
};
#endif 


