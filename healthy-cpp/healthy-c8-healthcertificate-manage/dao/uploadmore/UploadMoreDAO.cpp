#include "stdafx.h"
#include "UploadMoreDAO.h"
#include "UploadMoreMapper.h"
#include <sstream>

UploadMoreDO UploadMoreDAO::selectBypersonId(const string& personId)
{
	string sql = "SELECT name,sex,age,code,unit_of_issue,date_of_issue, term_of_validity, is_upload FROM t_certificate_manage WHERE `person_id`=?";
	UploadMoreMapper mapper;
	list<UploadMoreDO> uploadmoredolist = sqlSession->executeQuery<UploadMoreDO, UploadMoreMapper>(sql, mapper, "%s", personId);
	//如果personId不存在,返回一个空do
	if (uploadmoredolist.empty()) {
		cout << "PersonId " << personId << " not exists." << endl;
		UploadMoreDO nulldo;
		return nulldo;
	}
	else
	{
		UploadMoreDO& uploadmoredo = uploadmoredolist.front();
		return uploadmoredo;
	}
}

int UploadMoreDAO::updateIsUpload(const string& personId)
{
	string sql = "UPDATE `t_certificate_manage` SET `is_upload`=1 WHERE `person_id`=?";
	return sqlSession->executeUpdate(sql, "%s", personId);
}

uint64_t UploadMoreDAO::insertHealthcertificateFile(string id, string name, string type, string url)
{
	string sql = "INSERT INTO `t_document_file` (`id`, `name`, `type`,`url`) VALUES (?, ?,?, ? )";
	return sqlSession->executeInsert(sql, "%s%s%s%s", id, name, type, url);
}

UploadMoreDO UploadMoreDAO::getUrlByDocumentName(const string& documentname)
{
	string sql = "SELECT url FROM t_document_file WHERE `name`=?";
	UpLoadUrlMapper mapper;
	list<UploadMoreDO> uploadmoredolist = sqlSession->executeQuery<UploadMoreDO, UpLoadUrlMapper>(sql, mapper, "%s", documentname);
	if (!uploadmoredolist.empty()) {
		UploadMoreDO& uploadmoredo = uploadmoredolist.front();
		return uploadmoredo;
	}
	return {};
}

