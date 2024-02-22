#ifndef _DeleteTBP_DO_
#define _DeleteTBP_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class DeleteTBPDO
{
    // 
    CC_SYNTHESIZE(uint64_t, code, Code);
    // 姓名
    CC_SYNTHESIZE(string, del_flag, Del_flag);


public:
    DeleteTBPDO() {
        code = 0;
        del_flag = "";
    }
};
#endif // !_DeleteTBP_DO_