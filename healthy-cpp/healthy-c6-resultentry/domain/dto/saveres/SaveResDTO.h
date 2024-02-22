#pragma once
#ifndef _SAVERES_DTO_
#define _SAVERES_DTO_
#include "../../GlobalInclude.h"
#include "SaveResItemDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class SaveResDTO : public oatpp::DTO
{
	DTO_INIT(SaveResDTO, DTO);


	// ��������
	// �����id
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("save.filed.officeName"));
	// ���ҽ��
	API_DTO_FIELD_DEFAULT(String, checkDoc, ZH_WORDS_GETTER("save.filed.checkDoc"));
	// �������
	API_DTO_FIELD(String, checkDate, ZH_WORDS_GETTER("save.filed.checkDate"), true, "2002-11-11");
	// del flag
	API_DTO_FIELD_DEFAULT(Int32, delFlag, ZH_WORDS_GETTER("save.filed.delFlag"));
	// ������Ŀid
	API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));
	// ������Ŀ����
	API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("save.filed.groupItemName"));
	// ���С��
	API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("save.filed.diagnoseSum"));
	// �Ƿ񸴲�(0��1�ǣ�
	API_DTO_FIELD_DEFAULT(Int32, isCheck, ZH_WORDS_GETTER("save.filed.isCheck"));

	// depart res ����
	// �������
	API_DTO_FIELD_DEFAULT(String, diagnoseTip, ZH_WORDS_GETTER("save.filed.diagnoseTip"));
	
	// �Ƿ��Ǹ���(0���Ǹ��£� 1�Ǹ��£�
	API_DTO_FIELD(Int32, isUpdate, ZH_WORDS_GETTER("save.filed.isUpdate"), false, 0);
	// ����Ǹ��£����µ�depart_res_id
	API_DTO_FIELD(String, updateId, ZH_WORDS_GETTER("save.filed.updateId"), false, "");

	// item depart res ����

	//// �����Ļ�����Ŀid
	//API_DTO_FIELD(String, orderGroupItemProjectId, ZH_WORDS_GETTER("save.filed.orderGroupItemProjectId"),false, "");
	//// �����Ļ�����Ŀ����
	//API_DTO_FIELD_DEFAULT(String, orderGroupItemProjectName, ZH_WORDS_GETTER("save.filed.orderGroupItemProjectName"));
	//// �����
	//API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("save.filed.result"));
	//// ������λ����
	//API_DTO_FIELD_DEFAULT(String, unitCode, ZH_WORDS_GETTER("save.filed.unitCode"));
	//// ������λ����
	//API_DTO_FIELD_DEFAULT(String, unitName, ZH_WORDS_GETTER("save.filed.unitName"));
	//// �Ƿ�����쳣��1-��2-�ǣ�
	//API_DTO_FIELD(Int32, ignoreStatus, ZH_WORDS_GETTER("save.filed.ignoreStatus"), false, 1);
	//// Σ���̶�
	//API_DTO_FIELD(String, crisisDegree, ZH_WORDS_GETTER("save.filed.crisisDegree"), false, u8"����");
	//// ����
	//API_DTO_FIELD(Int32, postive, ZH_WORDS_GETTER("save.filed.postive"), false, 0);
	// ��ϸdto
	API_DTO_FIELD_DEFAULT(List<SaveResItemDTO::Wrapper>, itemList, ZH_WORDS_GETTER("save.filed.item"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVERES_DTO_