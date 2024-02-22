#pragma once

#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class SampleDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	//����
	CC_SYNTHESIZE(string, name, Name);
	//���
	CC_SYNTHESIZE(string, spec, Spec);
	//�걾����
	CC_SYNTHESIZE(string, code, Code);
	//�Ƿ��ӡ
	CC_SYNTHESIZE(int32_t, is_print, Is_print);
	//����
	CC_SYNTHESIZE(string, capacity, Capacity);
	//�Ƿ���Ҫ��Ѫ
	CC_SYNTHESIZE(int32_t, need_take_blood, Need_take_blood);
	//����
	CC_SYNTHESIZE(double, order_num, Order_num);
	//������
	CC_SYNTHESIZE(string, liscode, Liscode);

public:
	SampleDO() {
		id = "";
		name = "";
		spec = "";
		code = "";
		is_print = -1;
		capacity = "";
		need_take_blood = -1;
		order_num = 0;
		liscode = "";

	}
};

#endif // !_SAMPLE_DO_

