#pragma once
#ifndef _ADDNEWITEMSVO_H_
#define _ADDNEWITEMSVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/addNewItems/AddNewItemsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  新增复查记录显示JsonVO实体
*/
class AddNewItemsJsonVO : public JsonVO<AddNewItemsDTO::Wrapper> {
	DTO_INIT(AddNewItemsJsonVO, JsonVO<AddNewItemsDTO::Wrapper>);
};

/**
 * 新增复查记录显示分页JsonVO
 */
class AddNewItemsPageJsonVO : public JsonVO<AddNewItemsPageDTO::Wrapper> {
	DTO_INIT(AddNewItemsPageJsonVO, JsonVO<AddNewItemsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDNEWITEMSVO_H_