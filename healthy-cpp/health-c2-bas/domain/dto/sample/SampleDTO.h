#pragma once
#ifndef _SAMPLE_DTO_H_
#define _SAMPLE_DTO_H_


#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//单位列表传输数据对象实体
class SampleDTO : public oatpp::DTO
{
public:
	DTO_INIT(SampleDTO, DTO);
	// 主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sample.field.id"));
	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.field.name"));
	//规格
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("sample.field.spec"));
	//标本代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.field.code"));
	//是否打印
	API_DTO_FIELD_DEFAULT(Int32, is_print, ZH_WORDS_GETTER("sample.field.is_print"));
	//容量
	API_DTO_FIELD_DEFAULT(String, capacity, ZH_WORDS_GETTER("sample.field.capacity"));
	//是否需要采血
	API_DTO_FIELD_DEFAULT(Int32, need_take_blood, ZH_WORDS_GETTER("sample.field.need_take_blood"));
	//排序
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("sample.field.order_num"));
	//关联码
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.field.liscode"));
};


#include OATPP_CODEGEN_END(DTO)

#endif