#pragma once
/*
Copyright Zero One Star. All rights reserved.

@Author: lenyan~
@Date: 2024/1/27

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
#ifndef _INQUIRYDETAIL_MAPPER
#define _INQUIRYDETAIL_MAPPER

#include "Mapper.h"
#include "../../domain/do/evalue/InquiryDetailDO.h"


// Œ ’Ô√˜œ∏±Ì◊÷∂Œ∆•≈‰”≥…‰
class InquiryDetailMapper : public Mapper<InquiryDetailDO> {
public:
	InquiryDetailDO mapper(ResultSet* resultSet) const override {
		InquiryDetailDO data;
		//data.setId(resultSet->getUInt64(1));
		data.setWorkYear(resultSet->getUInt64(1));
		data.setWorkMonth(resultSet->getUInt64(2));
		data.setIsMarry(resultSet->getString(3));
		data.setExposureWorkYear(resultSet->getUInt64(4));
		data.setExposureWorkMonth(resultSet->getUInt64(5));
		data.setEducation(resultSet->getString(6));
		data.setFamilyAddress(resultSet->getString(7));
		data.setWorkTypeText(resultSet->getString(8));
		data.setWorkName(resultSet->getString(9));
		data.setDepartment(resultSet->getString(10));
		return data;
	}
};
#endif // !_INQUIRYDETAIL_MAPPER