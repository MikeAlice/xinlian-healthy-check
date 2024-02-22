#pragma once

#ifndef _DOWNQUERY_H_
#define _DOWNQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ģ��
 */
class DownQuery : public oatpp::DTO
{
	DTO_INIT(DownQuery, DTO);

	//�������
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("file.field.orderId"));

	//����
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("file.field.physicalType"));



};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
