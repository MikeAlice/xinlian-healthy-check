/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:19:12
 
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
#include "TestDb.h"
#include "SqlSession.h"
#include "LibTest.h"
#include "TransactionManager.h"

void TestDb::testSS()
{
	SqlSession sqlsession;
	//����һ�±���
	sqlsession.setCharset("GBK");
	//������
	string table = "CREATE TABLE IF NOT EXISTS `lib_test` (`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,`first` text NOT NULL,`last` text NOT NULL,`age` smallint(5) unsigned NOT NULL,PRIMARY KEY(`id`)) ENGINE = InnoDB DEFAULT CHARSET = utf8";
	sqlsession.execute(table);
	//��������
	string fullSql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES('��', '��', '96')";
	string sql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES(?, ?, ?)";
	uint64_t id = sqlsession.executeInsert(fullSql);
	cout << "id is " << id << endl;
	id = sqlsession.executeInsert(sql, "cs%cs%i", "С", "����", 97);
	cout << "id is " << id << endl;
	//��ѯ����
	string qsql = "SELECT * FROM `lib_test` WHERE id=?";
	string qfullSql = "SELECT * FROM `lib_test`";
	LibTestMapper mapper;
	list<LibTest> results = sqlsession.executeQuery<LibTest, LibTestMapper>(qsql, mapper, "cs", "2");
	cout << "query id is 2:" << endl;
	if (results.size() != 0) {
		LibTest sub = results.front();
		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
	}
	cout << "query all:" << endl;
	results = sqlsession.executeQuery<LibTest, LibTestMapper>(qfullSql, mapper);
	for (LibTest sub : results)
	{
		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
	}

	//��������
	cout << "test transaction begin" << endl;
	sqlsession.beginTransaction();
	string usql = "UPDATE `lib_test` SET `first`='��' WHERE `id`=2";
	int row = sqlsession.executeUpdate(usql);
	id = sqlsession.executeInsert(sql, "s%s%i", string("С"), string("����"), 98);
	if (row == 1) sqlsession.commitTransaction();
	else sqlsession.rollbackTransaction();
	cout << "test transaction end" << endl;

	//����������ύһ������,�����Ƿ���������ύ����
	id = sqlsession.executeInsert(sql, "cs%cs%i", "С", "����", 99);
	cout << "id is " << id << endl;
}

void TestDb::testTM()
{
	//��������DAO
	LibTestDAO1 d1;
	LibTestDAO2 d2;

	//���ñ��룬ע�⣺������Ŀģ���в���Ҫ�������ñ��룬���������Windows�����������ʹ��
	d1.getSqlSession()->setCharset("GBK");
	d2.getSqlSession()->setCharset("GBK");

	//�������������
	TransactionManager tm(&d1, &d2);

	//ִ�е�һ��DAO����
	LibTest uObj;
	uObj.first = "��";
	uObj.id = 1;
	int row = d1.update(uObj);
	//ִ�еڶ���DAO����
	row = row + d2.deleteById(6);
	//�ж��Ƿ��ύ����
	if (row == 2)
	{
		cout << "tm commit" << endl;
		tm.commit();
	}
	else
	{
		cout << "tm rollback" << endl;
		tm.rollback();
	}
}
