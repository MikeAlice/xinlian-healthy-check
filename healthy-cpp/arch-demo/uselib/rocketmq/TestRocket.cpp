/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:15:07
 
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
#ifdef USE_ROCKETMQ

#include "stdafx.h"
#include "TestRocket.h"
#include "domain/dto/sample/SampleDTO.h"
#include <iostream>
// MQ���ʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"

TestRocket::TestRocket()
{
	this->client = nullptr;
	this->cb = nullptr;
}

TestRocket::~TestRocket()
{
	if (client)
	{
		client->unsubscribe();
	}
}

void TestRocket::testRocket()
{
	//��ȡ����
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
	string namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");

	// �����ͻ���
	client = make_shared<RocketClient>(namesrv);
	// ����������Ϣ�ص�
	cb = make_shared<RocketClient::RSendCallback>([](SendStatus staus)
		{
			std::cout << "RSendCallback send status: " << staus << endl;
		});
	
	// ���Կ�������
	client->subscribe("hello");
	client->addListener(this);
	// ������Ϣ����
	auto dto = SampleDTO::createShared();
	dto->name = "cat";
	dto->sex = "man";
	dto->age = 10;
	// ������Ϣ
	dto->id = 1;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, cb.get());
	dto->id = 2;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, nullptr);
	dto->id = 3;
	RC_PUBLISH_OBJ_MSG_SYNC(res1, client, "hello", dto);
	std::cout << "sync send result: " << res1 << endl;
}

void TestRocket::receiveMessage(std::string payload)
{
	RC_RECEIVER_MSG_CONVERT(dto, SampleDTO, payload);
	std::cout << "receiveMessage: " << dto->id.getValue(-1)
		<< "-" << dto->name.getValue("")
		<< "-" << dto->sex.getValue("")
		<< "-" << dto->age.getValue(0)
		<< endl;
}

#endif // USE_ROCKETMQ