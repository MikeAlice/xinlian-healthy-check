#pragma once



#ifndef _INSERTSAMPLE_DTO_
#define _INSERTSAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//InsertSampleDTO
/**
 * 样本列表传输数据对象实体
 */
class InsertSampleDTO : public oatpp::DTO
{
	DTO_INIT(InsertSampleDTO, DTO);
	//id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sample.obsl.id"));
	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.obsl.name"));
	//规格
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("sample.obsl.spec"));
	//样本代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.obsl.code"));
	//是否打印
	API_DTO_FIELD_DEFAULT(UInt32, is_print, ZH_WORDS_GETTER("sample.obsl.is_print"));
	//容量
	API_DTO_FIELD_DEFAULT(String, capacity, ZH_WORDS_GETTER("sample.obsl.capacity"));
	// 条码份数
	API_DTO_FIELD_DEFAULT(UInt32, barcode_num, ZH_WORDS_GETTER("sample.obsl.barcode_num"));
	//是否采血
	API_DTO_FIELD_DEFAULT(UInt32, need_take_blood, ZH_WORDS_GETTER("sample.obsl.need_take_blood"));
	//排序
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("sample.obsl.order_num"));
	//关联码
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.obsl.liscode"));

	//del_flag
	API_DTO_FIELD_DEFAULT(UInt32, del_flag, ZH_WORDS_GETTER("sample.obsl.del_flag"));
};

/**
 * 分页传输对象实体
 */
class InsertSamplePageDTO : public PageDTO<InsertSampleDTO::Wrapper>
{
	DTO_INIT(InsertSamplePageDTO, PageDTO<InsertSampleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INSERTSAMPLE_DTO_