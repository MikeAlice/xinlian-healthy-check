#include "DelPackService.h"
#include "dao/combo/delPack/DelPackDAO.h"
#include "domain/dto/combo/DelPackDTO.h"
#include "domain/do/combo/DelPackDO.h"

int DelPackService::removeData(const DelPackDTO::Wrapper& dto)
{
    // 执行数据添加
    DelPackDAO dao;
    return dao.deleteById(dto->id.getValue(""));
}