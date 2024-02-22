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
#ifndef _REPORT_DO_
#define _REPORT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ReportDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(uint32_t, age, Age);
	// ���֤��
	CC_SYNTHESIZE(string, idCard, IdCard);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �������
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// ������λ
	CC_SYNTHESIZE(string, dept, Dept);
	// ����
	CC_SYNTHESIZE(string, conclusion, Conclusion);
	// �������
	CC_SYNTHESIZE(string, handleOpinion, HandleOpinion);
	// ����ҽ��
	CC_SYNTHESIZE(string, inspectionDoctor, InspectionDoctor);
	// �������
	CC_SYNTHESIZE(string, inspectionDate, InspectionDate);
	// ��쵥λ
	CC_SYNTHESIZE(string, diagnosticUnit, DiagnosticUnit);
	// PDF��ַ
	CC_SYNTHESIZE(string, href, Href);

public:
	ReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		idCard = "";
		mobile = "";
		physicalType = "";
		dept = "";
		conclusion = "";
		handleOpinion = "";
		inspectionDoctor = "";
		inspectionDate = "";
		diagnosticUnit = "";
		href = "2";
	}
};

#endif // !_REPORT_DO_
