#include "stdafx.h"
#include <iostream>
#include "UpFileController.h"
#include "../../service/file_chengfeng/UpFileService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "upfastDFS/UpFileDFS.h"
StringJsonVO::Wrapper UpFileController::execModifySample(const UpFileDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	 //定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	jvo->fail(ZH_WORDS_GETTER("file_chengfeng.field.fail"));

	//上传文件是否为.zip
	string testZip;
	testZip = dto->file_addr->substr(dto->file_addr->size() - 4, 4);
	if (testZip == ".zip") {

		//获得DFS中文件下载地址
		UpFileDFS dfs;
		string download = dfs.testDfs(dto->file_addr);
		
		//判断上传服务器是否成功
		if (download == "") {
			jvo->fail(ZH_WORDS_GETTER("file_chengfeng.field.fail_dfs"));
		}
		else {
			// 定义一个Service
			UpFileService service;
			//// 执行数据修改
			if (service.updateData(dto, download, payload)) {
				jvo->success(ZH_WORDS_GETTER("file_chengfeng.field.success"));
			}
		}
		
	}
	else {
		jvo->fail(ZH_WORDS_GETTER("file_chengfeng.field.no_zip"));
	}

	//响应结果
	return jvo;


}


