#ifndef _DeleteTBP_DO_
#define _DeleteTBP_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class DeleteTBPDO
{
    // 
    CC_SYNTHESIZE(uint64_t, code, Code);
    // ����
    CC_SYNTHESIZE(string, del_flag, Del_flag);


public:
    DeleteTBPDO() {
        code = 0;
        del_flag = "";
    }
};
#endif // !_DeleteTBP_DO_