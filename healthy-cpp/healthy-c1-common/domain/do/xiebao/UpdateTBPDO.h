#ifndef _UpdateTBP_DO_
#define _UpdateTBP_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UpdateTBPDO
{
    // 所属科室
    CC_SYNTHESIZE(string, office_id, Office_id);
    // 项目代码
    CC_SYNTHESIZE(string, code, Code);
    // 项目名称
    CC_SYNTHESIZE(string, name, Name);
    // 项目简称
    CC_SYNTHESIZE(string, short_name, Short_name);
    // 排序
    CC_SYNTHESIZE(float, order_num, Order_num);
    // 结果类型
    CC_SYNTHESIZE(string, result_type, Result_type);
    // 项目单位
    CC_SYNTHESIZE(string, unit_name, Unit_name);
    // 默认值
    CC_SYNTHESIZE(string, default_value, Default_value);
    // 进入小结
    CC_SYNTHESIZE(string, in_conclution, In_conclution);
    // 进入报告
    CC_SYNTHESIZE(string, inreport, Inreport);
    // LIS关联码
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