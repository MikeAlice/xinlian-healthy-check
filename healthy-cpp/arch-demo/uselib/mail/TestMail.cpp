/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/24 20:50:24

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
#include "stdafx.h"
#include <iostream>
#include "TestMail.h"
// 邮件组件使用需要相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "EmailSender.h"

void TestMail::test()
{
	std::string topic = ZH_WORDS_GETTER("mail.topic");
	std::string body1 = ZH_WORDS_GETTER("mail.body1");
	std::string body2 = ZH_WORDS_GETTER("mail.body2");
	// 创建邮件发送对象
	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.setCharset("utf8");
	emailSender.addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender.setEmailContent(topic, body1);
	emailSender.addAttachment("/home/file/1.zip");
	if (emailSender.send())
		std::cout << "mail send ok" << std::endl;
	else
		std::cout << "mail send fail" << std::endl;
}
