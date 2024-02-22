#pragma once

#ifndef _HEALTH_CERTIFICATE_VO_
#define _HEALTH_CERTIFICATE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/healthcertificatelist/HealthCertificateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 健康证列表JsonVO，用于响应给客户端的Json对象
 */
class HealthCertificateListJsonVO : public JsonVO<HealthCertificateListDTO::Wrapper> {
	DTO_INIT(HealthCertificateListJsonVO, JsonVO<HealthCertificateListDTO::Wrapper>);
};

/**
 * 健康证列表分页JsonVO，用于响应给客户端的Json对象
 */
class HealthCertificateListPageJsonVO : public JsonVO<HealthCertificateListPageDTO::Wrapper> {
	DTO_INIT(HealthCertificateListPageJsonVO, JsonVO<HealthCertificateListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif