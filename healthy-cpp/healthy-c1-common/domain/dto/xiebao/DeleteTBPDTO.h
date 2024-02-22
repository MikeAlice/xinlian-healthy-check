#pragma once
#ifndef _DeleteTBPDTO_H_
#define _DeleteTBPDTO_H_
#include"../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class DeleteTBPDTO : public oatpp::DTO,public TreeNode
{
    DTO_INIT(DeleteTBPDTO, DTO);

    // ��Ŀ����
    API_DTO_FIELD_DEFAULT(UInt64, code, ZH_WORDS_GETTER("code"));
    // �Ƿ���ɾ��
    API_DTO_FIELD_DEFAULT(UInt32, del_flag, ZH_WORDS_GETTER("del_flag"));

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DeleteTBPDTO_H_
