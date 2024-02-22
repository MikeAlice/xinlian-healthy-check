#pragma once
#ifndef _DeleteTBPVO_H_
#define _DeleteTBPVO_H_
#include"../../GlobalInclude.h"
#include "../../dto/xiebao/DeleteTBPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class DeleteTBPJsonVO : public JsonVO<DeleteTBPDTO::Wrapper>
{
    DTO_INIT(DeleteTBPJsonVO, JsonVO<DeleteTBPDTO::Wrapper>);
public:
    // �ڹ��캯����ʵ����data�б�
    DeleteTBPJsonVO() {
        this->data = {};
    }
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DeleteTBPVO_H_
