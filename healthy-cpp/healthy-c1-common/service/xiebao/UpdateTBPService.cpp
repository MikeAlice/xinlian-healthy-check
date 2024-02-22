#include "UpdateTBPService.h"
#include "stdafx.h"
#include "../../dao/xiebao/UpdateTBPDAO.h"
#include "../../domain/do/xiebao/UpdateTBPDO.h"
bool UpdateTBPService::updateTBP(const UpdateTBPDTO::Wrapper& dto)
{
    // 组装DO数据
    UpdateTBPDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Office_id, office_id,
        Code, code, 
        Name, name, 
        Short_name, short_name,
        Order_num, order_num,
        Result_type, result_type,
        Unit_name, unit_name,
        Default_value, default_value,
        In_conclution, in_conclution,
        Inreport, inreport,
        Relation_code, relation_code)
    // 执行数据修改
    UpdateTBPDAO dao;
    return dao.UpdateTBP(data) == 1;
}

