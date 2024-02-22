//调用get-order-detail定义的领域模型
// 
// #pragma once
// #ifndef _ADDORDERLISTDTO_H_
// #define _ADDORDERLISTDTO_H_
// 
// #include "../../GlobalInclude.h"
// 
// #include OATPP_CODEGEN_BEGIN(DTO)
// 
// /*
// * 单位列表传输数据对象实体
// */
// class AddOrderListDTO : public oatpp::DTO
// {
// 	DTO_INIT(AddOrderListDTO, DTO);
// 	//唯一编号
// 	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("addorder.field.id"));
// 	//订单编号
// 	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("addorder.field.orderCode"));
// 	//团建单位名称
// 	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("addorder.field.groupUnitName"));
// 	//销售负责人姓名
// 	API_DTO_FIELD_DEFAULT(String, salesDirectorName, ZH_WORDS_GETTER("addorder.field.salesDirectorName"));
// 	//签订日期
// 	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("addorder.field.signingTime"));
// 	//体检日期
// 	API_DTO_FIELD_DEFAULT(String, deliveryTime, ZH_WORDS_GETTER("addorder.field.deliveryTime"));
// 	//零星体检
// 	API_DTO_FIELD_DEFAULT(Int32, sporadicPhysical, ZH_WORDS_GETTER("addorder.field.sporadicPhysical"));
// 	//合同评审
// 	API_DTO_FIELD_DEFAULT(Int32, contractReview, ZH_WORDS_GETTER("addorder.field.contractReview"));
// 	//体检项目名称
// 	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("addorder.field.projectName"));
// 	//项目原价
// 	API_DTO_FIELD_DEFAULT(Int32, projectPrice, ZH_WORDS_GETTER("addorder.field.projectPrice"));
// 	//项目折扣
// 	API_DTO_FIELD_DEFAULT(Int32, projectDiscount, ZH_WORDS_GETTER("addorder.field.projectDiscount"));
// 	//项目折扣价
// 	API_DTO_FIELD_DEFAULT(Int32, projectDiscountPrice, ZH_WORDS_GETTER("addorder.field.projectDiscountPrice"));
// 	//项目类型
// 	API_DTO_FIELD_DEFAULT(Int32, projectType, ZH_WORDS_GETTER("addorder.field.projectType"));
// 	//订单原价
// 	API_DTO_FIELD_DEFAULT(Int32, orderPrice, ZH_WORDS_GETTER("addorder.field.orderPrice"));
// 	//订单合计
// 	API_DTO_FIELD_DEFAULT(Int32, orderTotal, ZH_WORDS_GETTER("addorder.field.orderTotal"));
// };
// 
// #include OATPP_CODEGEN_BEGIN(DTO)
// 
// #endif // !_ADDORDERLISTDTO_H_
