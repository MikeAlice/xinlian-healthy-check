#pragma once
#ifndef _BASEINFODTO_H_
#define _BASEINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个合同关键信息传输对象
 */
class BaseInfoDTO : public oatpp::DTO
{
	DTO_INIT(BaseInfoDTO, DTO);
	//合同名称
	API_DTO_FIELD_DEFAULT(String, orderName, ZH_WORDS_GETTER("contract.field.orderName"));
	//合同编号
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("contract.field.orderId"));
	//委托单位
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("contract.field.groupUnitName"));
	//委托内容
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("contract.field.physicalType"));
	//编制部门
	API_DTO_FIELD_DEFAULT(String, deptName, ZH_WORDS_GETTER("contract.field.deptName"));
	//编制人
	API_DTO_FIELD_DEFAULT(String, createId, ZH_WORDS_GETTER("contract.field.createId"));
	//审核人
	API_DTO_FIELD_DEFAULT(String, auditUserName, ZH_WORDS_GETTER("contract.field.auditUserName"));
	//审核状态
	API_DTO_FIELD_DEFAULT(String, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
	//联系人
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("contract.field.personName"));
	//联系电话
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("contract.field.mobile"));
	//审核日期
	API_DTO_FIELD_DEFAULT(String, auditTime, ZH_WORDS_GETTER("contract.field.auditTime"));
	//销售负责人
	API_DTO_FIELD_DEFAULT(String, salesDirectorName, ZH_WORDS_GETTER("contract.field.salesDirectorName"));
	//签订时间
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("contract.field.signingTime"));
	//交付时间
	API_DTO_FIELD_DEFAULT(String, dTime, ZH_WORDS_GETTER("contract.field.dTime"));

};

/**
 * 定义一个合同基础信息分页传输对象
 */
class BaseInfoPageDTO : public PageDTO<BaseInfoDTO::Wrapper>
{
	DTO_INIT(BaseInfoPageDTO, PageDTO<BaseInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_