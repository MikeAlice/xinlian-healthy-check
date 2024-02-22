#ifndef _UpdateTBPSERVICE_H_
#define _UpdateTBPSERVICE_H_
#include <list>
#include "domain/vo/xiebao/UpdateTBPVO.h"
#include "domain/dto/xiebao/UpdateTBPDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UpdateTBPService
{
public:
    // 通过ID删除数据
    bool updateTBP(const UpdateTBPDTO::Wrapper& dto);
};

#endif // !_UpdateTBPSERVICE_H_