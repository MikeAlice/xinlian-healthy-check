#ifdef USE_DFS

#include "stdafx.h"
#include <iostream>
#include "InquiryDetailFastDfs.h"
// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string InquiryDetailFastDfs::InquiryDetailDfsWithConf(string fileName)
{
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

#endif // USE_DFS