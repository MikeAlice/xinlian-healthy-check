/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/01/27 20:37:49

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
#ifndef _UNITREPORTDAO_H_
#define _UNITREPORTDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/UnitReport/UnitReportDO.h"

class UnitReportDAO : public BaseDAO
{
public:
	list<UnitReportDO> selectAll();
};

#endif // !_UNITREPORTDAO_H_