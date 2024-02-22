#include "stdafx.h"
#include "PrintMoreDAO.h"
#include "PrintMoreMapper.h"
#include <sstream>

list<CertificateManageDO> PrintMoreDAO::selectById(uint64_t id) {
	string sql = "SELECT id,is_upload,medical_certificate_id FROM t_certificate_manage WHERE `id` = ?";
	CertificateManageMapper mapper;
	return sqlSession->executeQuery<CertificateManageDO, CertificateManageMapper>(sql, mapper, "%ull", id);
}

list<DocumentFileDO> PrintMoreDAO::selectByDocName(string name) {
	string sql = "SELECT url FROM t_document_file WHERE `name` = ?";
	DocumentFileMapper mapper;
	return sqlSession->executeQuery<DocumentFileDO, DocumentFileMapper>(sql, mapper, "%s", name);
}