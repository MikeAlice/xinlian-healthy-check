#include "stdafx.h"
#include "UseFastDfs.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string UseFastDfs::uploadFile(const string& fileName) {
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

string UseFastDfs::downloadFile(const string& url, string path)
{
	// 定义DFS客户端对象
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);

	// 去掉urlPrefix前缀
	string fieldName = url.substr(urlPrefix.length());

	string fullpath = "";
	if (!fieldName.empty())
	{
		fullpath = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fullpath << std::endl;
	}
	return fullpath;
}