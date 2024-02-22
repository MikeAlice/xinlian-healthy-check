#include "stdafx.h"
#include <iostream>
#include "UpFileDFS.h"
// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string UpFileDFS::testDfs(string fileName)
{
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	//FastDfsClient client("192.168.163.130");
	FastDfsClient client("39.101.128.111");
#endif

	//�����ϴ�
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	return fieldName;
}

//string UpFileDFS::testDfsWithConf(string fileName)
//{
//		// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
//		NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
//	#ifdef LINUX
//		// ��ȡ�������ݽڵ�
//		auto thirdServerConfig = ns.getConfig("third-services.yaml");
//		// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
//		std::string config = ns.getConfigText("client.conf");
//		// ����ͻ��˶���
//		FastDfsClient client(config, false);
//	#else
//		// ��ȡ�������ݽڵ�
//		auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
//		// �������л�ȡFastDFS�ͻ�����������
//		std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
//		std::string ip = ipPort.substr(0, ipPort.find(":"));
//		int port = stoi(ipPort.substr(ipPort.find(":") + 1));
//		// ����ͻ��˶���
//		FastDfsClient client(ip, port);
//	#endif
//		// ����urlǰ׺
//		std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
//
//		// ����DFS�ͻ��˶����URLǰ׺
//	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
//	// ��ʼ�ϴ��ļ�
//	std::string fieldName = client.uploadFile(fileName);
//     
//	return fieldName;
//	
//}

