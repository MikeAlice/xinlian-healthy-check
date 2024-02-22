#ifndef _DeleteTBP_SERVICE_
#define _DeleteTBP_SERVICE_
#include <list>
#include "domain/vo/xiebao/DeleteTBPVO.h"
#include "domain/dto/xiebao/DeleteTBPDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DeleteTBPService
{
public:
    // 通过ID删除数据
    bool DeleteTBP(const DeleteTBPDTO::Wrapper& dto);

    //// 通过ID删除数据
    //bool DeleteTBP(uint64_t id);
};

#endif // !_DeleteTBP_SERVICE_