#pragma once
#ifndef _BASEPROJECT_H_
#define _BASEPROJECT_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*����һ����ѯ�����Ŀ�ڻ�����Ŀ������Ĵ���ģ��
*/

class BaseProjectQuery : public PageQuery
{
	DTO_INIT(BaseProjectQuery, PageQuery);
	//��ѡ�������Ŀ����
	API_DTO_FIELD_DEFAULT(String, portfolioId, ZH_WORDS_GETTER("checkitem.portfolio.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASEPROJECT_H_
