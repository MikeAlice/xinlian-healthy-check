#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
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
#ifndef _INFO_LIST_DO_
#define _INFO_LIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class InfoListDO
{
	CC_SYNTHESIZE(int, id, Id);
	//�����Ա
	CC_SYNTHESIZE(int, personId, PersonId);
	//�ܼ�ҽ��
	CC_SYNTHESIZE(string, inspectionDoctor, InspectionDoctor);
	//�ܼ�����
	CC_SYNTHESIZE(string, inspectionDate, InspectionDate);
	//ҽѧ����
	CC_SYNTHESIZE(string, medicalAdvice, MedicalAdvice);
	//�������
	CC_SYNTHESIZE(string, handleOpinion, HandleOpinion);

public:
	InfoListDO() {
		personId = 0;
		inspectionDoctor = "";
		inspectionDate = "";
		medicalAdvice = "";
		handleOpinion = "";
	}
};

#endif // !_SAMPLE_DO_
