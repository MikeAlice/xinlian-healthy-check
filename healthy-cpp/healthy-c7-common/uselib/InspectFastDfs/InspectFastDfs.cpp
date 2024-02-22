/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:29:51

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
#include "InspectFastDfs.h"
// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string test = "";
string InspectFastDfs::InspectDfsWithConf(string fileName)
{
	//	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	//#ifdef LINUX
	//	// ��ȡ�������ݽڵ�
	//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	//	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
	//	std::string config = ns.getConfigText("client.conf");
	//	// ����ͻ��˶���
	//	FastDfsClient client(config, false);
	//#else
	//	// ��ȡ�������ݽڵ�
	//	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	//	// �������л�ȡFastDFS�ͻ�����������
	//	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	//	std::string ip = ipPort.substr(0, ipPort.find(":"));
	//	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	//	// ����ͻ��˶���
	//	FastDfsClient client(ip, port);
	//#endif
	//	// ����urlǰ׺
	//	std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";

		// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	cout << downloadUrl << endl;
	test = downloadUrl;
	return downloadUrl;
}

