#pragma once

#ifndef _TESTDETAILDO_H_
#define _TESTDETAILDO_H_

#include "../DoInclude.h"

class TestDetailDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, unitId, UnitId);
	CC_SYNTHESIZE(string, hazardFactors, HazardFactors);
	CC_SYNTHESIZE(string, hazardFactorsText, HazardFactorsText);
	CC_SYNTHESIZE(string, otherHazardFactors, OtherHazardFactors);
	CC_SYNTHESIZE(string, workStateCode, WorkStateCode);
	CC_SYNTHESIZE(string, workStateText, WorkStateText);
	CC_SYNTHESIZE(string, workTypeCode, WorkTypeCode);
	CC_SYNTHESIZE(string, workTypeText, WorkTypeText);
	CC_SYNTHESIZE(string, workName, WorkName);
	CC_SYNTHESIZE(string, strength, Strength);
	CC_SYNTHESIZE(string, testTime, TestTime);
	CC_SYNTHESIZE(uint32_t, delFlag, DelFlag);
	CC_SYNTHESIZE(string, createId, CreateId);
	CC_SYNTHESIZE(string, createTime, CreateTime);
	CC_SYNTHESIZE(string, updateId, UpdateId);
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	CC_SYNTHESIZE(string, deleteId, DeleteId);
	CC_SYNTHESIZE(string, deleteTime, DeleteTime);
public:
	TestDetailDO():id(""), unitId(""), hazardFactors(""), hazardFactorsText(""), otherHazardFactors(""), 
		workStateCode(""), workStateText(""), workTypeCode(""), workTypeText(""), workName(""), strength(""), 
		testTime(""), delFlag(0), createId(""), createTime(""), updateId(""), updateTime(""), deleteId(""), deleteTime("")
	{}
};

#endif // !_TESTDETAILDO_H_