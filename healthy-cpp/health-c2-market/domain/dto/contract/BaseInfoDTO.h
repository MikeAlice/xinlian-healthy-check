#pragma once
#ifndef _BASEINFODTO_H_
#define _BASEINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ͬ�ؼ���Ϣ�������
 */
class BaseInfoDTO : public oatpp::DTO
{
	DTO_INIT(BaseInfoDTO, DTO);
	//��ͬ����
	API_DTO_FIELD_DEFAULT(String, orderName, ZH_WORDS_GETTER("contract.field.orderName"));
	//��ͬ���
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("contract.field.orderId"));
	//ί�е�λ
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("contract.field.groupUnitName"));
	//ί������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("contract.field.physicalType"));
	//���Ʋ���
	API_DTO_FIELD_DEFAULT(String, deptName, ZH_WORDS_GETTER("contract.field.deptName"));
	//������
	API_DTO_FIELD_DEFAULT(String, createId, ZH_WORDS_GETTER("contract.field.createId"));
	//�����
	API_DTO_FIELD_DEFAULT(String, auditUserName, ZH_WORDS_GETTER("contract.field.auditUserName"));
	//���״̬
	API_DTO_FIELD_DEFAULT(String, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
	//��ϵ��
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("contract.field.personName"));
	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("contract.field.mobile"));
	//�������
	API_DTO_FIELD_DEFAULT(String, auditTime, ZH_WORDS_GETTER("contract.field.auditTime"));
	//���۸�����
	API_DTO_FIELD_DEFAULT(String, salesDirectorName, ZH_WORDS_GETTER("contract.field.salesDirectorName"));
	//ǩ��ʱ��
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("contract.field.signingTime"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, dTime, ZH_WORDS_GETTER("contract.field.dTime"));

};

/**
 * ����һ����ͬ������Ϣ��ҳ�������
 */
class BaseInfoPageDTO : public PageDTO<BaseInfoDTO::Wrapper>
{
	DTO_INIT(BaseInfoPageDTO, PageDTO<BaseInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_