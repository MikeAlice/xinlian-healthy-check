#pragma once

#ifndef _GETDATE_H_
#define _GETDATE_H_

#include <string>

class GetDate {
public:

    static std::string getCurrentDate();
    static std::string getPreviousMonthDate();

private:
   
    static std::string getCurrentDateFormatted();
    static std::string getPreviousMonthDateFormatted();
};

#endif