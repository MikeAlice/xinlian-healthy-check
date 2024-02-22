/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/25 16:57:17

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
#ifdef USE_ALISMS

#include "stdafx.h"
#include "TestAliSms.h"
#include "sms/aliyun/AliSmsSender.h"
#include <iostream>

void TestAliSms::test()
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以所有中文字从中文词典中获取，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms("电话号码", "阿里云短信测试", "SMS_154950909", "{\"code\":\"996007\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
}

void TestAliSms::testBatch()
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以所有中文字从中文词典中获取，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSmsBatch("[\"号码1\",\"号码2\"]", "[\"签名1\",\"签名2\"]", "SMS_********", "[{\"code\":\"996007\"},{\"code\":\"857857\"}]");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
}

#endif // USE_ALISMS