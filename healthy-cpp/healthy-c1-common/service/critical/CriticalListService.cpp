#include"stdafx.h"
#include<stdlib.h>
#include "CriticalListService.h"
#include"../../dao/critical/CriticalListDAO.h"

bool CriticalListService::updateData(const CriticalListDTO::Wrapper& dto)
{
    CriticalListDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Level, level, Type, type, IntervalValue, intervalValue, AllowSex, allowSex, MinAge, minAge, MaxAge, maxAge)
        // 执行数据修改
    CriticalListDAO dao;
    return dao.update(data) == 1;
}

bool CriticalListService::removeData(const CriticalDeleteListDTO::Wrapper& dto)
{
    CriticalListDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id)

    CriticalListDAO dao;
    return dao.deleteById(data) == 1;
}
