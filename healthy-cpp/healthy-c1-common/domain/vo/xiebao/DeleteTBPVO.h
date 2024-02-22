#pragma once
#ifndef _DeleteTBPVO_H_
#define _DeleteTBPVO_H_
#include"../../GlobalInclude.h"
#include "../../dto/xiebao/DeleteTBPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class DeleteTBPJsonVO : public JsonVO<DeleteTBPDTO::Wrapper>
{
    DTO_INIT(DeleteTBPJsonVO, JsonVO<DeleteTBPDTO::Wrapper>);
public:
    // 在构造函数中实例化data列表
    DeleteTBPJsonVO() {
        this->data = {};
    }
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DeleteTBPVO_H_
