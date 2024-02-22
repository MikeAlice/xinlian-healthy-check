#pragma once
#ifndef _PackageProListVO_
#define _PackageProListVO_

#include "../../GlobalInclude.h"
#include "../../dto/packageprolist/PackageProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PackageProListJsonVO : public JsonVO<PackageProListDTO::Wrapper> {
	DTO_INIT(PackageProListJsonVO, JsonVO<PackageProListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PackageProListPageJsonVO : public JsonVO<PackageProListPageDTO::Wrapper> {
	DTO_INIT(PackageProListPageJsonVO, JsonVO<PackageProListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_