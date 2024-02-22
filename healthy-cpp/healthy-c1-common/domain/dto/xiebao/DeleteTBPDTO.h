#pragma once
#ifndef _DeleteTBPDTO_H_
#define _DeleteTBPDTO_H_
#include"../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class DeleteTBPDTO : public oatpp::DTO,public TreeNode
{
    DTO_INIT(DeleteTBPDTO, DTO);

    // 项目代码
    API_DTO_FIELD_DEFAULT(UInt64, code, ZH_WORDS_GETTER("code"));
    // 是否已删除
    API_DTO_FIELD_DEFAULT(UInt32, del_flag, ZH_WORDS_GETTER("del_flag"));

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DeleteTBPDTO_H_
