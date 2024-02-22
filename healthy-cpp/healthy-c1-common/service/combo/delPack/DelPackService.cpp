#include "DelPackService.h"
#include "dao/combo/delPack/DelPackDAO.h"
#include "domain/dto/combo/DelPackDTO.h"
#include "domain/do/combo/DelPackDO.h"

int DelPackService::removeData(const DelPackDTO::Wrapper& dto)
{
    // ִ���������
    DelPackDAO dao;
    return dao.deleteById(dto->id.getValue(""));
}