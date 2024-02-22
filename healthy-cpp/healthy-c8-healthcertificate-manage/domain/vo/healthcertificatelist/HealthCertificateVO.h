#pragma once

#ifndef _HEALTH_CERTIFICATE_VO_
#define _HEALTH_CERTIFICATE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/healthcertificatelist/HealthCertificateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����֤�б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class HealthCertificateListJsonVO : public JsonVO<HealthCertificateListDTO::Wrapper> {
	DTO_INIT(HealthCertificateListJsonVO, JsonVO<HealthCertificateListDTO::Wrapper>);
};

/**
 * ����֤�б��ҳJsonVO��������Ӧ���ͻ��˵�Json����
 */
class HealthCertificateListPageJsonVO : public JsonVO<HealthCertificateListPageDTO::Wrapper> {
	DTO_INIT(HealthCertificateListPageJsonVO, JsonVO<HealthCertificateListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif