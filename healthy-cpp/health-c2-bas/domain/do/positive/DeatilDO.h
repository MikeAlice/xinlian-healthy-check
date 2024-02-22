#ifndef _DEATIL_DO_
#define _DEATIL_DO_

#include "../DoInclude.h
class DeatilDo {
	//查询id  名称 简拼 是否严重 是否阳性 科室 职业建议 健康建议
	CC_SYNTHESIZE(int, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, name_pinyin, namePinYin); 
	CC_SYNTHESIZE(string, degree, Degree);
	CC_SYNTHESIZE(string, positive, Positive);
	CC_SYNTHESIZE(string, section_name, sectionName);
	CC_SYNTHESIZE(string, advise, Advise);
	CC_SYNTHESIZE(string, health_knowledge, healthKnowledge);
public:
	DeatilDo() {
		id = 1;
		name = " ";
		name_pinyin = " ";
		degree = " ";
		positive = " ";
		section_name = " ";
		advise = " ";
		health_knowledge = " ";

	}
};

#endif // !_DEATIL_DO_

