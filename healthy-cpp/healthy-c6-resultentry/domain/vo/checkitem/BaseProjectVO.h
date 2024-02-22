#pragma once
#ifndef _BASEPROJECTVO_H_
#define _BASEPROJECTVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/checkitem/BaseProjectListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
*单位列表显示JsonVO实体
*/
class BaseProjectJsonVO : public JsonVO<BaseProjectListDTO::Wrapper> {
	DTO_INIT(BaseProjectJsonVO, JsonVO<BaseProjectListDTO::Wrapper>);

};

class BaseProjectPageJsonVO : public JsonVO<BaseProjectPageDTO::Wrapper> {
	DTO_INIT(BaseProjectPageJsonVO, JsonVO<BaseProjectPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASEPROJECTVO_H_
