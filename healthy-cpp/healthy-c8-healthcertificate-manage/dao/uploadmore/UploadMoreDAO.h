#pragma once
#ifndef _UPLOADMORE_DAO_
#define _UPLOADMORE_DAO_
#include "BaseDAO.h"
#include "domain/do/uploadmore/UploadMoreDO.h"

/**
 * ���ݿ����ʵ��
 */
class UploadMoreDAO : public BaseDAO
{
public:
	// ͨ����Աid��ѯ����
	UploadMoreDO selectBypersonId(const string& personId);
	//��t_certificate_manage���Ƿ��ϴ��ֶθ���Ϊ�ϴ�1��
	int updateIsUpload(const string& personId);
	//��t_document_file��������ϴ�����֤�ļ����ĵ���Ϣ
	uint64_t UploadMoreDAO::insertHealthcertificateFile(string id, string name, string type, string url);
	//ͨ���ļ����ƻ�ȡ�ļ���ַ
	UploadMoreDO getUrlByDocumentName(const string& documentname);
};
#endif 