//����get-order-detail���������ģ��
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
// * ��λ�б������ݶ���ʵ��
// */
// class AddOrderListDTO : public oatpp::DTO
// {
// 	DTO_INIT(AddOrderListDTO, DTO);
// 	//Ψһ���
// 	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("addorder.field.id"));
// 	//�������
// 	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("addorder.field.orderCode"));
// 	//�Ž���λ����
// 	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("addorder.field.groupUnitName"));
// 	//���۸���������
// 	API_DTO_FIELD_DEFAULT(String, salesDirectorName, ZH_WORDS_GETTER("addorder.field.salesDirectorName"));
// 	//ǩ������
// 	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("addorder.field.signingTime"));
// 	//�������
// 	API_DTO_FIELD_DEFAULT(String, deliveryTime, ZH_WORDS_GETTER("addorder.field.deliveryTime"));
// 	//�������
// 	API_DTO_FIELD_DEFAULT(Int32, sporadicPhysical, ZH_WORDS_GETTER("addorder.field.sporadicPhysical"));
// 	//��ͬ����
// 	API_DTO_FIELD_DEFAULT(Int32, contractReview, ZH_WORDS_GETTER("addorder.field.contractReview"));
// 	//�����Ŀ����
// 	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("addorder.field.projectName"));
// 	//��Ŀԭ��
// 	API_DTO_FIELD_DEFAULT(Int32, projectPrice, ZH_WORDS_GETTER("addorder.field.projectPrice"));
// 	//��Ŀ�ۿ�
// 	API_DTO_FIELD_DEFAULT(Int32, projectDiscount, ZH_WORDS_GETTER("addorder.field.projectDiscount"));
// 	//��Ŀ�ۿۼ�
// 	API_DTO_FIELD_DEFAULT(Int32, projectDiscountPrice, ZH_WORDS_GETTER("addorder.field.projectDiscountPrice"));
// 	//��Ŀ����
// 	API_DTO_FIELD_DEFAULT(Int32, projectType, ZH_WORDS_GETTER("addorder.field.projectType"));
// 	//����ԭ��
// 	API_DTO_FIELD_DEFAULT(Int32, orderPrice, ZH_WORDS_GETTER("addorder.field.orderPrice"));
// 	//�����ϼ�
// 	API_DTO_FIELD_DEFAULT(Int32, orderTotal, ZH_WORDS_GETTER("addorder.field.orderTotal"));
// };
// 
// #include OATPP_CODEGEN_BEGIN(DTO)
// 
// #endif // !_ADDORDERLISTDTO_H_
