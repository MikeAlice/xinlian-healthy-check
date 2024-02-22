#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _TESTPDF_H_
#define _TESTPDF_H_
/**
 * PDF组件测试使用
 */
class TestPdf
{
public:
	// 测试绘制文本
	static void testText();
	// 测试模板绘制
	static void testTpl();
};

#endif // !_TESTPDF_H_