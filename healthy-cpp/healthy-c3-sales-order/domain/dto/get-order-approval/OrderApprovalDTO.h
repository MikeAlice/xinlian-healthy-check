#pragma once

#ifndef _ORDERVIEWAPPROVAL_DTO_
#define _ORDERVIEWAPPROVAL_DTO_
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrderApprovalDTO :public oatpp::DTO
{
	DTO_INIT(OrderApprovalDTO, DTO);
// 	//Ψһ��ʶ ������id
// 	DTO_FIELD(UInt64, id);
// 	DTO_FIELD_INFO(id) {
// 		info->description = ZH_WORDS_GETTER("order.field.id");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, id, ZH_WORDS_GETTER("order.field.id"));
// 	//����״̬
// 	DTO_FIELD(String, audit_state);
// 	DTO_FIELD_INFO(audit_state) {
// 		info->description = ZH_WORDS_GETTER("order.field.audit_state");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, audit_state, ZH_WORDS_GETTER("order.field.audit_state"));
// 	//������
//     DTO_FIELD(String, audit_user_name);
// 	DTO_FIELD_INFO(audit_user_name) {
// 		info->description = ZH_WORDS_GETTER("order.field.audit_user_name");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, audit_user_name, ZH_WORDS_GETTER("order.field.audit_user_name"));
// 	//����ʱ��
// 	DTO_FIELD(String, audit_time);
// 	DTO_FIELD_INFO(audit_time) {
// 		info->description = ZH_WORDS_GETTER("order.field.audit_time");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, audit_time, ZH_WORDS_GETTER("order.field.audit_time"));
// 	//�������
//     DTO_FIELD(String, audit_content);
// 	DTO_FIELD_INFO(audit_content) {
// 		info->description = ZH_WORDS_GETTER("order.field.audit_content");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, audit_content, ZH_WORDS_GETTER("order.field. audit_content"));

	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("flow.field.id"));
	//����id
	API_DTO_FIELD_DEFAULT(String, groupOrderId, ZH_WORDS_GETTER("flow.field.group_order_id"));
	//���״̬ 2ͨ�� 3δͨ��  0Ĭ��
	API_DTO_FIELD_DEFAULT(Int32, auditState, ZH_WORDS_GETTER("flow.field.audit_state"));
	//�����Աid
	API_DTO_FIELD_DEFAULT(String, auditUserId, ZH_WORDS_GETTER("flow.field.audit_user_id"));
	//�����Ա
	API_DTO_FIELD_DEFAULT(String, auditUserName, ZH_WORDS_GETTER("flow.field.audit_user_name"));
	//���ʱ��
	API_DTO_FIELD_DEFAULT(String, auditTime, ZH_WORDS_GETTER("flow.field.audit_time"));
	//������
	API_DTO_FIELD_DEFAULT(String, auditContent, ZH_WORDS_GETTER("flow.field.audit_content"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 