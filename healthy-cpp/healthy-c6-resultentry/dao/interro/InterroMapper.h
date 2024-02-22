#pragma once
#ifndef _INTERRO_MAPPER_
#define _INTERRO_MAPPER_
#include"Mapper.h"
#include"../../domain/do/interro/InterroDO.h"

/**
* �ֶ�ƥ��
*/
class InterroMapper : public Mapper<InterroDO> {
public:
	InterroDO mapper(ResultSet* resultSet) const override {
		InterroDO data;
		// ���
		data.setType(resultSet->getString(1));
		// �����Ŀ
		data.setProject(resultSet->getString(2));
		// ��Ŀ���
		data.setCode(resultSet->getString(3));
		// Σ���̶�
		data.setDegree(resultSet->getString(4));
		// ����ʱ��
		data.setCoursetime(resultSet->getString(5));
		// ��Ա�������
		data.setPersonid(resultSet->getString(6));
		// ������-���ҽ��
		data.setCreateid(resultSet->getString(7));
		//���ҽ��
		data.setCreatename(resultSet->getString(8));
		return data;
	}
};


#endif // !_INTERRO_MAPPER_
