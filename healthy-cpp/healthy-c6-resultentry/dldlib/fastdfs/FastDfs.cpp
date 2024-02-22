
#ifdef USE_DFS

#include "stdafx.h"
#include <iostream>
#include "FastDfs.h"
// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

void BarcodesFastDfs::testDfs(string fileName)
{
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("192.168.220.128");
#endif

	//测试上传
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	//测试下载
	if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fileName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fileName << std::endl;
	}
	//测试删除文件
	if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}

}

void BarcodesFastDfs::testDfsWithConf(string fileName)
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
	// 输出下载路径
	std::cout << "download url: " << downloadUrl << std::endl;
}

string BarcodesFastDfs::barcodesDfs(string fileName)
{
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("39.101.128.111");
	//ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
#endif
	//测试上传
	std::string fieldName = client.uploadFile(fileName);
	//测试是否上传成功
	if (fieldName.empty()) {
		return "";
	}
	else {
		return fileName;
	}

}

#endif // USE_DFS