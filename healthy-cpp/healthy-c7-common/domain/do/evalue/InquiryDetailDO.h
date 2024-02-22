#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/1/27 

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
#ifndef _INQUIRYDETAIL_DO_
#define _INQUIRYDETAIL_DO_
#include "../DoInclude.h"

/**
 * ������ϸ���ݿ�ʵ����
 */
class InquiryDetailDO
{
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �������
	CC_SYNTHESIZE(uint64_t, workYear, WorkYear);
	// �����¶�
	CC_SYNTHESIZE(uint64_t, workMonth, WorkMonth);
	// ���״��
	CC_SYNTHESIZE(string, isMarry, IsMarry);
	//��������
	CC_SYNTHESIZE(uint64_t, exposureWorkYear, ExposureWorkYear);
	//��������
	CC_SYNTHESIZE(uint64_t, exposureWorkMonth, ExposureWorkMonth);

	//�Ǳ���
	
	//�Ļ��̶�
	CC_SYNTHESIZE(string, education, Education);
	//��ͥ��ַ
	CC_SYNTHESIZE(string, familyAddress, FamilyAddress);
	//��������
	CC_SYNTHESIZE(string, workTypeText, WorkTypeText);
	//������������
	CC_SYNTHESIZE(string, workName, WorkName);
	//��������
	CC_SYNTHESIZE(string, department, Department);



public:
	InquiryDetailDO() {
		id = 1;
		workYear = 0;
		workMonth = 0;
		isMarry = "";
		exposureWorkYear = 0;
		exposureWorkMonth = 0;

		//�Ǳ��룬����Ϊ��
		education = "";
		familyAddress = "";
		workTypeText = "";
		workName = "";
		department = "";
	}
};

#endif // !_INQUIRYDETAIL_DO_

