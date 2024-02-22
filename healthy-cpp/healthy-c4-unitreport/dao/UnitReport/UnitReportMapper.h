/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/01/27 21:00:33

 Licensed under the Apache License, Version 2.0 (the License);
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an AS IS BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _UNITREPORTMAPPER_H_
#define _UNITREPORTMAPPER_H_

#include "Mapper.h"
#include "domain/do/UnitReport/UnitReportDO.h"

class UnitReportMapper : public Mapper<UnitReportDO>
{
public:
	UnitReportDO mapper(ResultSet* rs) const override
	{
		UnitReportDO date;
		date.setConcludingObservations(rs->getString(1));
		date.setEntrustUnit(rs->getString(2));
		date.setEvaluationBasis(rs->getString(3));
		date.setPhysicalDate(rs->getString(4));
		date.setPhysicalNumber(rs->getString(5));
		date.setPhysicalProject(rs->getString(6));
		date.setPhysicalType(rs->getString(7));
		date.setPhysicalUnit(rs->getString(8));
		date.setCCode(rs->getString(9));
		return date;
	}
};

#endif // !_UNITREPORTMAPPER_H_