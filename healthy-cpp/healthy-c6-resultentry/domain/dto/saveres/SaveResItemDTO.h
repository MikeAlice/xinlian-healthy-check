#pragma once
#ifndef _SAVERESITEM_DTO_
#define _SAVERESITEM_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class SaveResItemDTO : public oatpp::DTO
{
	DTO_INIT(SaveResItemDTO, DTO);


	//// ��������
	//// �����id
	//API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	//// ����id
	//API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	//// ��������
	//API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("save.filed.officeName"));
	//// ���ҽ��
	//API_DTO_FIELD_DEFAULT(String, checkDoc, ZH_WORDS_GETTER("save.filed.checkDoc"));
	//// �������
	//API_DTO_FIELD(String, checkDate, ZH_WORDS_GETTER("save.filed.checkDate"), true, "2002-11-11");
	//// del flag
	//API_DTO_FIELD_DEFAULT(Int32, delFlag, ZH_WORDS_GETTER("save.filed.delFlag"));
	//// ������Ŀid
	//API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));
	//// ������Ŀ����
	//API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("save.filed.groupItemName"));
	//// ���С��
	//API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("save.filed.diagnoseSum"));
	//// �Ƿ񸴲�(0��1�ǣ�
	//API_DTO_FIELD_DEFAULT(Int32, isCheck, ZH_WORDS_GETTER("save.filed.isCheck"));



	// item depart res ����

	// �����Ļ�����Ŀid
	API_DTO_FIELD(String, orderGroupItemProjectId, ZH_WORDS_GETTER("save.filed.orderGroupItemProjectId"), false, "");
	// �����Ļ�����Ŀ����
	API_DTO_FIELD_DEFAULT(String, orderGroupItemProjectName, ZH_WORDS_GETTER("save.filed.orderGroupItemProjectName"));
	// �����
	API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("save.filed.result"));
	// ������λ����
	API_DTO_FIELD_DEFAULT(String, unitCode, ZH_WORDS_GETTER("save.filed.unitCode"));
	// ������λ����
	API_DTO_FIELD_DEFAULT(String, unitName, ZH_WORDS_GETTER("save.filed.unitName"));
	// �Ƿ�����쳣��1-��2-�ǣ�
	API_DTO_FIELD(Int32, ignoreStatus, ZH_WORDS_GETTER("save.filed.ignoreStatus"), false, 1);
	// Σ���̶�
	API_DTO_FIELD(String, crisisDegree, ZH_WORDS_GETTER("save.filed.crisisDegree"), false, u8"����");
	// ����
	API_DTO_FIELD(Int32, positive, ZH_WORDS_GETTER("save.filed.positive"), false, 0);
	// ��ϸΨһid�����ڸ���ʱ��Ч��
	API_DTO_FIELD(String, itemId, ZH_WORDS_GETTER("save.filed.itemId"), false, "");

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVERESITEM_DTO_