// #pragma once
// 
// 
// #ifndef _ORDERQUERY_H_
// #define _ORDERQUERY_H_
// 
// #include "../../GlobalInclude.h"
// 
// #include OATPP_CODEGEN_BEGIN(DTO)
// 
// /**
//  * ²éÑ¯¶©µ¥ÏêÇé
//  */
// class OrderQuery : public oatpp::DTO
// {
// 	DTO_INIT(OrderQuery, DTO);
// 	
// 	//Ò³Âë
// 	API_DTO_FIELD_DEFAULT(UInt32, pageNumber, ZH_WORDS_GETTER("unit.field.pageNumber"));
// 
// 	//Ò³´óÐ¡
// 	API_DTO_FIELD_DEFAULT(UInt32, pageSize, ZH_WORDS_GETTER("unit.field.pageSize"));
// 
// 	//µ¥Î»±àºÅ
// 	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("unit.field.groupId"));
// 
// 	//¶©µ¥±àºÅ
// 	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("unit.field.orderId"));
// };
// 
// #include OATPP_CODEGEN_END(DTO)
// #endif // !_SAMPLE_QUERY_