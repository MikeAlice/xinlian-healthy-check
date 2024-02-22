#include "stdafx.h"
#include "AddBaseProjectDAO.h"
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: AddBaseProjectDAO.cpp
 @version: 1.0

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
uint64_t AddBaseProjectDAO::insert(const AddBaseProjectDO& iObj)
{

    string sql = "INSERT INTO `t_base_project` (`id`, `code`, `name`, `short_name`, `order_num`, `office_id`, `office_name`, `unit_code`, `unit_name`, `default_value`, `result_type`, `in_conclusion`, `in_report`, `relation_code`, `del_flag`, `create_id`, `create_time`, `update_id`, `update_time`, `delete_id`, `delete_time`, `department_id`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";



    //"%s%s%s%s%f%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s%s"
    return sqlSession->executeInsert(sql, "%s%s%s%s%i%s%s%s%s%s%s%s%s%s%i%s%dt%s%dt%s%dt%s",
        iObj.getId(),        
        iObj.getCode(),      
        iObj.getName(),      
        iObj.getShortName(), 
        iObj.getOrderNum(), 
        iObj.getOfficeId(),  
        iObj.getOfficeName(),
        iObj.getUnitCode(),  
        iObj.getUnitName(),  
        iObj.getDefaultValue(),
        iObj.getResultType(),
        iObj.getInConclusion(),
        iObj.getInReport(),  
        iObj.getRelationCode(),
        iObj.getDelFlag(), 
        iObj.getCreateId(),  
        iObj.getCreateTime(),
        iObj.getUpdateId(),  
        iObj.getUpdateTime(),
        iObj.getDeleteId(),  
        iObj.getDeleteTime(),
        iObj.getDepartmentId() 
    );

}
