#ifndef _UpdateTBPSERVICE_H_
#define _UpdateTBPSERVICE_H_
#include <list>
#include "domain/vo/xiebao/UpdateTBPVO.h"
#include "domain/dto/xiebao/UpdateTBPDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class UpdateTBPService
{
public:
    // ͨ��IDɾ������
    bool updateTBP(const UpdateTBPDTO::Wrapper& dto);
};

#endif // !_UpdateTBPSERVICE_H_