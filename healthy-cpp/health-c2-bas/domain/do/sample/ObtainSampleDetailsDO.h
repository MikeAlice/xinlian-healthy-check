#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _OBTAIN_SAMPLE_DETAILS_DO_
#define _OBTAIN_SAMPLE_DETAILS_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class  ObtainSampleDetailsDO
{	
	//����
	CC_SYNTHESIZE(std::string, name, Name);
	//�������
	CC_SYNTHESIZE(int, barcode_num, Barcode_num);
	//���
	CC_SYNTHESIZE(std::string, spec, Spec);
	//�Ƿ��Ѫ
	CC_SYNTHESIZE(int, need_take_blood, Need_take_blood);
	//�걾����
	CC_SYNTHESIZE(std::string, code, Code);
	//����
	CC_SYNTHESIZE(double, order_num, Order_num);
	//�Ƿ��ӡ
	CC_SYNTHESIZE(int, is_print, Is_print);
	//������
	CC_SYNTHESIZE(std::string, liscode, Liscode);
	//����
	CC_SYNTHESIZE(std::string, capacity, Capacity);
public:
	ObtainSampleDetailsDO() {
		/*id = 0;
		name = "";
		sex = "";
		age = -1;*/
		name = "";
		barcode_num = 0;
		spec = "";
		need_take_blood = 0;
		code = "";
		order_num = 0;
		is_print = 0;
		liscode = "";
		capacity = "";


	}
};

#endif // !_SAMPLE_DO_