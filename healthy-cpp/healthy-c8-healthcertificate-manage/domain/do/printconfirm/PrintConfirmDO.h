#pragma once
#ifndef _PRINT_CONFIRM_DO_
#define _PRINT_CONFIRM_DO_
#include "../DoInclude.h"

/**
 * ��ӡȷ�����ݿ�ʵ����
 * ��DTO���������ת����C++���������
 * eg��OATPP�е�String����ת����C++�е�string����
 */
class PrintConfirmDO
{
	// �������
	CC_SYNTHESIZE(string, orderid, Orderid);
public:
	PrintConfirmDO() {
		orderid = "";
	}
};

#endif // !_PRINT_CONFIRM_DO_