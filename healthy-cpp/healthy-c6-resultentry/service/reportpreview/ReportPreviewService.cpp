#include "stdafx.h"
#include "ReportPreviewService.h"
#include"domain/do/reportpreview/ReportPreviewDO.h"
#include"dao/reportpreview/ReportPreviewDAO.h"

oatpp::List<ReportPreviewViewDTO::Wrapper> ReportPreviewService::reportview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //先创建一个DAO对象
    ReportPreviewDAO rpdao;
    //要拼装的DTO
    auto lsdto = oatpp::List<ReportPreviewViewDTO::Wrapper>::createShared();
    auto nulldto = ReportPreviewViewDTO::createShared();
    //查询数据，拼接DTO
        auto result = rpdao.queryReportPreview(qdto->person_id,qdto->person_name);
        for (ReportPreviewDO sub : result) {
            lsdto->push_back(nulldto);
            ZO_STAR_DOMAIN_DO_TO_DTO(lsdto->front(), sub, person_name, Person_name, sex, Sex, id_card, Id_card,
                birth, Birth, age, Age, home_address, Home_address, mobile, Mobile, test_num, Test_num,
                department, Department, dept, Dept, check_date, Check_date, other_hazard_factors, Other_hazard_factors,
                work_type_text, Work_type_text, work_year, Work_year, exposure_work_year, Exposure_work_year,
                education, Education, marriage_date, Marriage_date, period, Period, cycle, Cycle, menarche, Menarche,
                existing_children, Existing_children, abortion, Abortion,
                premature, Premature, death, Death, abnormal_fetus, Abnormal_fetus, allergies, Allergies,
                package_every_day, Package_every_day, smoke_year, Smoke_year);
            ZO_STAR_DOMAIN_DO_TO_DTO(lsdto->front(), sub, ml_every_day, Ml_every_day, drink_year, Drink_year,
                birthplace_name, Birthplace_name, family_history, Family_history, past_medical_history, Past_medical_history,
                disease_name, Disease_name, last_menstruation, Last_menstruation);
        }
        return lsdto;
}

oatpp::List<T_symptomDTO::Wrapper> ReportPreviewService::symptomview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //先创建一个DAO对象
    ReportPreviewDAO sbvdao;
    //要拼装的DTO
    auto lsdto = oatpp::List<T_symptomDTO::Wrapper>::createShared();
    auto nulldto = T_symptomDTO::createShared();
    //查询数据，拼接DTO
    for (int i = 0; i < qdto->code->size(); i++)
    {
        auto result = sbvdao.queryT_symptom(qdto->person_id,qdto->code[i]);
        for (T_symptomDO sub : result) {
            lsdto->push_back(nulldto);
            ZO_STAR_DOMAIN_DO_TO_DTO(lsdto->front(), sub, degree, Degree, course_time, Course_time, project_name, Project_name);
        }
    }
    return lsdto;
}
