#ifndef _DeleteTBP_SERVICE_
#define _DeleteTBP_SERVICE_
#include <list>
#include "domain/vo/xiebao/DeleteTBPVO.h"
#include "domain/dto/xiebao/DeleteTBPDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DeleteTBPService
{
public:
    // ͨ��IDɾ������
    bool DeleteTBP(const DeleteTBPDTO::Wrapper& dto);

    //// ͨ��IDɾ������
    //bool DeleteTBP(uint64_t id);
};

#endif // !_DeleteTBP_SERVICE_