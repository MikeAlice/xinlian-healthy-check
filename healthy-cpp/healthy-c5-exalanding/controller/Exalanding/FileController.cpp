#include "stdafx.h"
#include <iostream>
#include "FileController.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper FileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "nickname", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "age", -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* ���Խ��ļ����浽�������� */
		/*string fullPath = "public/static/file/" + filename;
		file.saveToFile(fullPath.c_str());*/

		/* �����ϴ���FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// ��ȡ�ļ���׺��
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

		// �������·��
		std::cout << "download url: " << downloadUrl << std::endl;

		auto jvo = StringJsonVO::createShared();
		jvo->success("OK");
		return jvo;
	}

	// 5 ��Ӧ���
	/* TODO: ������Ӧʲô�������Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	auto jvo = StringJsonVO::createShared();
	jvo->fail("error");
	return jvo;
}
