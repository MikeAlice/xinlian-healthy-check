#include "stdafx.h"
#include "UseFastDfs.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string UseFastDfs::uploadFile(const string& fileName) {
	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}

string UseFastDfs::downloadFile(const string& url, string path)
{
	// ����DFS�ͻ��˶���
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);

	// ȥ��urlPrefixǰ׺
	string fieldName = url.substr(urlPrefix.length());

	string fullpath = "";
	if (!fieldName.empty())
	{
		fullpath = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fullpath << std::endl;
	}
	return fullpath;
}