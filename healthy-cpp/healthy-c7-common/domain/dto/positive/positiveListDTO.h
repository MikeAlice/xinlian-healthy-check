#pragma once
#ifndef _POSITIVEListDTO_H_
#define _POSITIVEListDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ���б������ݶ���ʵ��
 * ���Խ��λ��t_depart_item_result����
 */
class PositiveListDTO : public oatpp::DTO {
	DTO_INIT(PositiveListDTO, DTO);
	// Ψһ��� 
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.filed.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("positive.filed.personname"));
	// ����� t_group_person����
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("positive.filed.test_num"));
	// ������
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("positive.filed.officename"));
	// �����Ŀ
	API_DTO_FIELD_DEFAULT(String, order_group_item_project_name, ZH_WORDS_GETTER("positive.filed.order_group_item_project_name"));
	// ��� �ضȳ̶�
	API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("positive.filed.result"));
	// ��λ
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("positive.filed.unit_name"));
	// �ο���Χ
	API_DTO_FIELD_DEFAULT(String, scope, ZH_WORDS_GETTER("positive.filed.scope"));
	// ��ʾ
	API_DTO_FIELD_DEFAULT(String, diagnose_sum, ZH_WORDS_GETTER("positive.filed.diagnose_sum"));
	// Σ���̶�
	API_DTO_FIELD_DEFAULT(String, crisis_degree, ZH_WORDS_GETTER("positive.filed.crisis_degree"));
	// �������
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("positive.filed.checkdate"));
public:
	// ��ȡΨһ��ŵĳ�Ա����
	const String& getId() const {
		return id;
	}

	// ��ȡ�����ĳ�Ա����
	const String& getPersonName() const {
		return personName;
	}
	// ��ȡ����ŵĳ�Ա����
	const String& geTest_num() const {
		return test_num;
	}
	// ��ȡ�����ҵĳ�Ա����
	const String& getOfficeName() const {
		return officeName;
	}
	// ��ȡ�����Ŀ�Ĵ�Ա����
	const String& getOrder_group_item_project_name() const {
		return order_group_item_project_name;
	}
	// ��ȡ����ĳ�Ա����
	const String& getResult() const {
		return result;
	}
	// ��ȡ��λ�ĳ�Ա����
	const String& getUnit_name() const {
		return unit_name;
	}
	// ��ȡ�ο���Χ�ĳ�Ա����
	const String& getScope() const {
		return scope;
	}
	// ��ȡ��ʾ�ĳ�Ա����
	const String& getDiagnose_sum() const {
		return diagnose_sum;
	}
	// ��ȡΣ���̶ȵĳ�Ա����
	const String& getCrisis_degree() const {
		return crisis_degree;
	}
	// ��ȡ������ڵĳ�Ա����
	const String& getCheckDate() const {
		return checkDate;
	}
};

/**
 * ���Խ���б��ҳ����ʵ��
 */
class PositiveListPageDTO : public PageDTO<PositiveListDTO::Wrapper> {
	DTO_INIT(PositiveListPageDTO, PageDTO<PositiveListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSITIVEListDTO_H_