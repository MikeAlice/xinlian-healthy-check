#ifndef _UpdateTBP_DO_
#define _UpdateTBP_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UpdateTBPDO
{
    // ��������
    CC_SYNTHESIZE(string, office_id, Office_id);
    // ��Ŀ����
    CC_SYNTHESIZE(string, code, Code);
    // ��Ŀ����
    CC_SYNTHESIZE(string, name, Name);
    // ��Ŀ���
    CC_SYNTHESIZE(string, short_name, Short_name);
    // ����
    CC_SYNTHESIZE(float, order_num, Order_num);
    // �������
    CC_SYNTHESIZE(string, result_type, Result_type);
    // ��Ŀ��λ
    CC_SYNTHESIZE(string, unit_name, Unit_name);
    // Ĭ��ֵ
    CC_SYNTHESIZE(string, default_value, Default_value);
    // ����С��
    CC_SYNTHESIZE(string, in_conclution, In_conclution);
    // ���뱨��
    CC_SYNTHESIZE(string, inreport, Inreport);
    // LIS������
    CC_SYNTHESIZE(string, relation_code, Relation_code);


public:
    UpdateTBPDO() {
        code = "";
        office_id = "";
        name = "";
        short_name = "";
        order_num = 0.0;
        result_type = "";
        unit_name = "";
        default_value = "";
        in_conclution = "";
        inreport = "";
        relation_code = "";
    }
};
#endif // !_UpdateTBP_DO_