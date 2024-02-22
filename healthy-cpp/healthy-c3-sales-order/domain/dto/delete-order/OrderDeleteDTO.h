////删除（非批量）操作不涉及query、dto、vo

// #pragma once
// 
// #ifndef _ORDER_DELETE_DTO_
// #define _ORDER_DELETE_DTO_
// #include "../../GlobalInclude.h"
// 
// #include OATPP_CODEGEN_BEGIN(DTO)
// 
// /**
//  * 删除对象
//  */
// class OrderDeleteDTO : public oatpp::DTO
// {	
// 	DTO_INIT(OrderDeleteDTO, DTO);
// 	// 订单编号
// 	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("sales.field.ordercode"));
// };
// 
// 
// 
// #include OATPP_CODEGEN_END(DTO)
// #endif // !_ORDER_DELETE_DTO_