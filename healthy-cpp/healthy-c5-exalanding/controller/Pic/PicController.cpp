/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:37:57

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
#include "PicController.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

PicImageVO::Wrapper PicController::execUploadPicImage(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);
	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 ��ȡ����
	request->transferBody(&reader);
	// 4 ��ȡ�ļ�����
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		// ��ȡ�ļ���׺��
		string filename = partfile->getFilename().getValue("");
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// ���Խ��ļ����浽��������
		std::string newFileName = SimpleDateTimeFormat::formatWithMilli("%Y%m%d%H%M%S", "") + "." + suffix;
		string fullPath = "public/static/file/" + newFileName;
		file.saveToFile(fullPath.c_str());

		// ������Ӧ����
		string downloadUrl = "http://localhost:8090/file/download?filename=file/" + newFileName;
		auto jvo = PicImageVO::createShared();
		jvo->success(PicImageDTO::createShared(downloadUrl));
		return jvo;
	}
	// 5 ��Ӧʧ��
	auto jvo = PicImageVO::createShared();
	jvo->fail({});
	return jvo;
}
