#ifdef USE_DFS

#include "stdafx.h"
#include <iostream>
#include "PreviewReportFastDfs.h"
// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string PreviewReportFastDfs::PreviewReportDfsWithConf(string fileName)
{
	//	// 定义一个Nacos客户端对象，用于获取配置
	//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	//#ifdef LINUX
	//	// 读取配置数据节点
	//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	//	// 从Nacos配置中心获取FastDFS客户端配置数据
	//	std::string config = ns.getConfigText("client.conf");
	//	// 定义客户端对象
	//	FastDfsClient client(config, false);
	//#else
	//	// 读取配置数据节点
	//	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	//	// 从配置中获取FastDFS客户端配置数据
	//	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	//	std::string ip = ipPort.substr(0, ipPort.find(":"));
	//	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	//	// 定义客户端对象
	//	FastDfsClient client(ip, port);
	//#endif
	//	// 设置url前缀
	//	std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";

		// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	cout << downloadUrl << endl;
	return downloadUrl;
}


#endif // USE_DFS