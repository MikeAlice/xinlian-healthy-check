#ifndef _CHECKLIST_DAO_
#define _CHECKLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Exalanding/CheckListDO.h"
#include "../../domain/query/Exalanding/CheckListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CheckListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CheckListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<CheckListDO> selectWithPage(const CheckListQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<CheckListDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const CheckListDO& iObj);
	// �޸�����
	int update(const CheckListDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_PEOPLELIST_DAO_