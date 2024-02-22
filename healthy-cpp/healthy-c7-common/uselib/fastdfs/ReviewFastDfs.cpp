#ifdef USE_DFS

#include "stdafx.h"
#include <iostream>
#include "ReviewFastDfs.h"
// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string ReviewFastDfs::ReviewDfsWithConf(string fileName)
{
	// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}

#endif // USE_DFS