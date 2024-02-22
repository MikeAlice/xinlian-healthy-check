#pragma once
#ifndef _UpdateTBPVO_H_
#define _UpdateTBPVO_H_
#include"../../GlobalInclude.h"
#include"../../dto/xiebao/UpdateTBPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class UpdateTBPJsonVO : public JsonVO<UpdateTBPDTO::Wrapper>
{
    DTO_INIT(UpdateTBPJsonVO, JsonVO<UpdateTBPDTO::Wrapper>);
public:
    // 在构造函数中实例化data列表
    UpdateTBPJsonVO() {
        this->data = {};
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UpdateTBPVO_H_
