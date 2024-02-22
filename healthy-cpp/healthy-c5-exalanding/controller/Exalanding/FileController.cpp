#include "stdafx.h"
#include <iostream>
#include "FileController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper FileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "nickname", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "age", -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* 测试将文件保存到磁盘上面 */
		/*string fullPath = "public/static/file/" + filename;
		file.saveToFile(fullPath.c_str());*/

		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

		// 输出下载路径
		std::cout << "download url: " << downloadUrl << std::endl;

		auto jvo = StringJsonVO::createShared();
		jvo->success("OK");
		return jvo;
	}

	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->fail("error");
	return jvo;
}
