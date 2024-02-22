#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _GROUPAPPROVE_MAPPER_
#define _GROUPAPPROVE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/groupapprove/GroupApproveDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GroupApproveMapper : public Mapper<GroupApproveDO>
{
public:
	GroupApproveDO mapper(ResultSet* resultSet) const override
	{
		GroupApproveDO data;
		data.setId(resultSet->getUInt64(1));
		data.setAudit_level(resultSet->getUInt64(2));
		data.setIs_info_table(resultSet->getString(3));
		data.setIs_assessment_report(resultSet->getString(4));
		data.setIs_business_license(resultSet->getString(5));
		data.setIs_person_info(resultSet->getString(6));
		data.setIs_entrust_report(resultSet->getString(7));
		data.setIs_keep_record(resultSet->getString(8));
		data.setIs_equipment_true(resultSet->getString(9));
		data.setIs_standard(resultSet->getString(10));
		data.setIs_understand_needs(resultSet->getString(11));
		data.setIs_subcontract(resultSet->getString(12));
		data.setIs_special_requirements(resultSet->getString(13));
		data.setIs_inform(resultSet->getString(14));
		data.setIs_take_from_oneself(resultSet->getString(15));
		data.setIs_can_service(resultSet->getString(16));
		data.setReason(resultSet->getString(17));
		data.setConclusion_person_in_charge(resultSet->getString(18));

		return data;
	}
};

#endif // !_GROUPAPPROVE_MAPPER_