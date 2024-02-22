#pragma once
#ifndef _UpdateTBPVO_H_
#define _UpdateTBPVO_H_
#include"../../GlobalInclude.h"
#include"../../dto/xiebao/UpdateTBPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class UpdateTBPJsonVO : public JsonVO<UpdateTBPDTO::Wrapper>
{
    DTO_INIT(UpdateTBPJsonVO, JsonVO<UpdateTBPDTO::Wrapper>);
public:
    // �ڹ��캯����ʵ����data�б�
    UpdateTBPJsonVO() {
        this->data = {};
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UpdateTBPVO_H_
