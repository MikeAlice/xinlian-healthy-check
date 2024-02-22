#pragma once
#ifndef _SAVE_INFO_DO_H_
#define _SAVE_INFO_DO_H_
#include "../DoInclude.h"

/**
 * ���Բ˵����ݿ�ʵ��
 */
class SaveInfoDO
{
	// id
protected: string id; public: string getId(void) const {
	return id;
}public: void setId(string var) {
	id = var;
};
	// ���֤��
	CC_SYNTHESIZE(string, id_card, Id_card);
	//����
	CC_SYNTHESIZE(string, person_name, Person_name);
	//�Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	//����
	CC_SYNTHESIZE(int, age, Age);
	//��ϵ�绰
	CC_SYNTHESIZE(string, mobile, Mobile);
	//����״̬
	CC_SYNTHESIZE(string, is_marry, Is_marry);
	//�Ƿ�ͨ�����(1-�Ǽǣ�2-�ڼ�,3-�ܼ�,4-�����)
	CC_SYNTHESIZE(int, is_pass, Is_pass);
	//�������
	CC_SYNTHESIZE(string, physical_type, Physical_type);
public:
	SaveInfoDO() {}
	SaveInfoDO(string id_card, string person_name, string sex, int age, string mobile,string is_marry)
	{
		this->id_card = id_card;
		this->person_name = person_name;
		this->sex = sex;
		this->age = age;	
		this->mobile = mobile;
		this->is_marry = is_marry;
	}
};


#endif // !_SAVE_INFO_DO_H_