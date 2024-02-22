#include "stdafx.h"
#include "SampleBarcodesViewService.h"
#include"dao/samplebarcodesview/SampleBarcodesViewDAO.h"
#include"domain/do/samplebarcodesview/SampleBarcodesViewDO.h"

oatpp::List<SampleBarcodesViewDTO::Wrapper> SampleBarcodesViewServer::barcodesview(const SampleBarcodesViewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //�ȴ���һ��DAO����
    SampleBarcodesViewDAO sbvdao;
    //Ҫƴװ��DTO
    auto lsdto = oatpp::List<SampleBarcodesViewDTO::Wrapper>::createShared();
    auto nulldto = SampleBarcodesViewDTO::createShared();
    //��ѯ���ݣ�ƴ��DTO
    for (int i = 0; i < qdto->group_item_id->size(); i++)
    {
        auto result = sbvdao.querySampleBarcodesView(qdto->person_id, qdto->group_item_id[i], qdto->type);
        for (SampleBarcodesViewDO sub : result) {
            lsdto->push_back(nulldto);
            ZO_STAR_DOMAIN_DO_TO_DTO(lsdto->front(), sub, barcode, Barcode, test_num, Test_num, person_name, Person_name
                , age, Age, sex, Sex, group_item_name, Group_item_name);
        }
    }
    return lsdto;
}
