/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/2/3

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
#include "InquiryDetailService.h"
#include "../../dao/evalue/InquiryDetailDAO.h"

#include "uselib/fastdfs/InquiryDetailFastDfs.h"
#include "uselib/pdf/InquiryDetailPdf.h"

//������
InquiryDetailPageDTO::Wrapper InquiryDetailService::listAll(const InquiryDetailQuery::Wrapper& query)
{
	// �������ض���
	auto pages = InquiryDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	InquiryDetailDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<InquiryDetailDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (InquiryDetailDO sub : result)
	{
		auto dto = InquiryDetailDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, workYear, WorkYear, workMonth, WorkMonth, isMarry, IsMarry, exposureWorkYear, ExposureWorkYear,
			exposureWorkMonth, ExposureWorkMonth, education, Education, familyAddress, FamilyAddress, workTypeText, WorkTypeText,
			workName, WorkName, department, Department, id, Id)
			pages->addData(dto);

	}
	return pages;
}

//�������ݱ�
bool InquiryDetailService::updateData(const InquiryDetailDTO::Wrapper& dto)
{
	// ��װDO����
	InquiryDetailDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,WorkYear, workYear, WorkMonth, workMonth, IsMarry, isMarry, ExposureWorkYear, exposureWorkYear,
		ExposureWorkMonth, exposureWorkMonth, Education, education, FamilyAddress, familyAddress, WorkTypeText, workTypeText,
		WorkName, workName, Department, department)
		// ִ�������޸�
		InquiryDetailDAO dao;
	return dao.update(data) == 1;
}
//pdf����id���ɶ�Ӧ��fastpdf
InquiryDetailDTO::Wrapper InquiryDetailService::listById(const InquiryDetailQuery::Wrapper& query)
{
	// �������ض���
	auto pages = InquiryDetailDTO::createShared();
	InquiryDetailDAO dao;
	InquiryDetailPdf pdf;
	InquiryDetailFastDfs FastDfs;
	list<InquiryDetailDO> result = dao.selectById(to_string(query->id));
	// ��DOת����DTO
	for (InquiryDetailDO sub : result)
	{
		auto dto = InquiryDetailDTO::createShared();
		pdf.InquiryDetailText(sub);
		//pdf.InquiryDetailTpl(sub);
		dto->downloadUrl = FastDfs.InquiryDetailDfsWithConf("InquiryDetailReport.pdf");
		pages = dto;
	}
	return pages;
}

