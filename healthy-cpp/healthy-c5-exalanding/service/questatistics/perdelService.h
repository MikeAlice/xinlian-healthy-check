#ifndef _PERDEL_SERVICE_H_
#define _PERDEL_SERVICE_H_
#include <string>

class perdelService
{
public:
	// 通过id删除体检人员
	bool removeData(const std::string& id);
};

#endif // !_PERDEL_SERVICE_H_
