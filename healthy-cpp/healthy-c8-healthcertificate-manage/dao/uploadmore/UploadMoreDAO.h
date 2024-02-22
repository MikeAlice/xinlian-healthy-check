#pragma once
#ifndef _UPLOADMORE_DAO_
#define _UPLOADMORE_DAO_
#include "BaseDAO.h"
#include "domain/do/uploadmore/UploadMoreDO.h"

/**
 * 数据库操作实现
 */
class UploadMoreDAO : public BaseDAO
{
public:
	// 通过人员id查询数据
	UploadMoreDO selectBypersonId(const string& personId);
	//将t_certificate_manage表是否上传字段更新为上传1；
	int updateIsUpload(const string& personId);
	//在t_document_file表中添加上传健康证文件的文档信息
	uint64_t UploadMoreDAO::insertHealthcertificateFile(string id, string name, string type, string url);
	//通过文件名称获取文件地址
	UploadMoreDO getUrlByDocumentName(const string& documentname);
};
#endif 