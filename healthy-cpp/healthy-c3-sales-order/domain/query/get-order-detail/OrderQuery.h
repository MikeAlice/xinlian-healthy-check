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
//  * ��ѯ��������
//  */
// class OrderQuery : public oatpp::DTO
// {
// 	DTO_INIT(OrderQuery, DTO);
// 	
// 	//ҳ��
// 	API_DTO_FIELD_DEFAULT(UInt32, pageNumber, ZH_WORDS_GETTER("unit.field.pageNumber"));
// 
// 	//ҳ��С
// 	API_DTO_FIELD_DEFAULT(UInt32, pageSize, ZH_WORDS_GETTER("unit.field.pageSize"));
// 
// 	//��λ���
// 	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("unit.field.groupId"));
// 
// 	//�������
// 	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("unit.field.orderId"));
// };
// 
// #include OATPP_CODEGEN_END(DTO)
// #endif // !_SAMPLE_QUERY_