#pragma once

#ifndef _BASEPROJECTLISTDTO_H_
#define _BASEPROJECTLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��������Ŀ����������ݴ���ģ��
 */
class BaseProjectListDTO : public oatpp::DTO
{
	DTO_INIT(BaseProjectListDTO, DTO);
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("checkitem.base.code"));
	//�����Ŀ
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.base.name"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("checkitem.base.unit_name"));
	//�ο�ֵ
	API_DTO_FIELD_DEFAULT(String, healthy_value, ZH_WORDS_GETTER("checkitem.base.healthy_value"));
	//Ĭ��ֵ
	API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("checkitem.base.default_value"));
	//��ϸ�������
	API_DTO_FIELD_DEFAULT(String, result_type, ZH_WORDS_GETTER("checkiten.base.result_type"));


};

class BaseProjectPageDTO : public PageDTO<BaseProjectListDTO::Wrapper> {
	DTO_INIT(BaseProjectPageDTO, PageDTO<BaseProjectListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASEPROJECTLISTDTO_H_

