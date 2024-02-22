#pragma once
#ifndef _PREFIX_MODIFYRESULTVO_H_
#define _PREFIX_MODIFYRESULTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/positive/ModifyResultDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
    class ModifyResultJasonVO : public JsonVO<ModifyResultDTO::Wrapper>
      {
        DTO_INIT(ModifyResultJasonVO, JsonVO<ModifyResultDTO::Wrapper>);
      };
#include OATPP_CODEGEN_END(DTO)
#endif  //  _PREFIX_MODIFYRESULTVO_H_