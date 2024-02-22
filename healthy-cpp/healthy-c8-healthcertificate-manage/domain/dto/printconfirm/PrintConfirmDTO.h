#pragma once
#ifndef _PRINTCONFIRMDTO_H_
#define _PRINTCONFIRMDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӡȷ�ϴ������ݶ���ʵ��
 */
class PrintConfirmDTO :public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(PrintConfirmDTO, DTO);
	// �������
	API_DTO_FIELD_DEFAULT(String, orderid, ZH_WORDS_GETTER("printconfirm.field.order-id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTCONFIRMDTO_H_
