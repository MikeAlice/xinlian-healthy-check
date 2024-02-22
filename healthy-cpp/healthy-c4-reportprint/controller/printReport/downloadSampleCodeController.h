#pragma once

#ifndef _DOWNLOADSAMPLECODE_CONTROLLER_H_
#define _DOWNLOADSAMPLECODE_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include <iostream>
#include <utility>

#include "domain/vo/printreport/DownloadSampleCodeVO.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 报告下载接口
 */
class DownloadSampleCodeController : public oatpp::web::server::api::ApiController
{
	//  定义控制器访问入口
	API_ACCESS_DECLARE(DownloadSampleCodeController);

public:


	// 定义一个样本条码获取接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		// 接口标题
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("print.get.sampleCode"), Void);
		// 条码编号
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeNum", ZH_WORDS_GETTER("addition.field.sampleCodeNum"), "436591946372", false);
		// 条码名称
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeName", ZH_WORDS_GETTER("addition.field.sampleCodeName"), ZH_WORDS_GETTER("addition.test.sampleCodeName"), false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/downloadSampleCode", downloadFile, QUERY(String, sampleCodeName)) {
		return execDownloadSampleCode(sampleCodeName);
	}

private: // 定义接口执行函数
	// 获取样本条码
	std::shared_ptr<OutgoingResponse> execDownloadSampleCode(const String& sampleCodeName);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _DOWNLOADSAMPLECODE_CONTROLLER_H_