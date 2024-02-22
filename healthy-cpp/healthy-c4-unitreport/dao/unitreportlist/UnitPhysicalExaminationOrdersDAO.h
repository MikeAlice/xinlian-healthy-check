#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_DAO_
#define _UNITPHYSICALEXAMINATIONORDERS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unitreportlist/UnitPhysicalExaminationOrdersDO.h"
#include "../../domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class UnitPhysicalExaminationOrdersDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<UnitPhysicalExaminationOrdersDO> selectWithPage(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_