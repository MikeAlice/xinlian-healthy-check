#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2023/12/29 11:30:58

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
#ifndef _INSPECT_PDF_H_
#define _INSPECT_PDF_H_

#include "domain/do/ReportView/ReportDO.h"
/**
 * PDF�������ʹ��
 */
class InspectPdf
{
public:
	// ģ�����
	static void ReportText(const ReportDO & Do);
	static void testText();
};

#endif // !_INSPECT_PDF_H_