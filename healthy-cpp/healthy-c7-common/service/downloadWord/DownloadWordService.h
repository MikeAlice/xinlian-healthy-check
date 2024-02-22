#pragma once

#ifndef _DOWNLOADWORD_SERVICE_
#define _DOWNLOADWORD_SERVICE_


//#include "../../GlobalInclude.h"
#include "ApiController.hpp"


class DownloadWordService
{
public:

	oatpp::data::mapping::type::String execDownload(const oatpp::web::server::api::ApiController::String& fileUrl);

};

#endif // !_SAMPLE_SERVICE_

