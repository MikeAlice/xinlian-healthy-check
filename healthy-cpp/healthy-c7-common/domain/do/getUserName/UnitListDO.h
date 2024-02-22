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
#ifndef _UnitList_DO_
#define _UnitList_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UnitListDO
{
	//�������
	CC_SYNTHESIZE(int, ispass, Ispass);
	// ����״̬  ������Ա�ڸ�����Ա��Ϣ���в�ѯ
	CC_SYNTHESIZE(int, isRecheck, IsRecheck);
	//��ʼʱ��
	CC_SYNTHESIZE(string, startDate, StartDate);
	//����ʱ��
	CC_SYNTHESIZE(string, endDate, EndDate);
	//�����
	CC_SYNTHESIZE(string, testNum, TestNum);
	//��λ����
	CC_SYNTHESIZE(string, dept, Dept);


	// ����
	CC_SYNTHESIZE(string, personName, PersonName);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ������� physicalType
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// �Ƿ��������(0-��1-��)
	CC_SYNTHESIZE(int, sporadicPhysical, SporadicPhysical);//int���Ϳ����е�С����

public:
	UnitListDO() {
		ispass = 1;
		isRecheck = 0;
		startDate = "";
		endDate = "";
		testNum = "";
		dept = "";

		personName = "";
		sex = "";
		age = -1;
		physicalType = "";
		sporadicPhysical = 0;
	}
};

#endif // !_SAMPLE_DO_
