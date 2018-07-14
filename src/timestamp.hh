#pragma once

#include <iostream>

#define YEAR 10000
#define MONTH 100

#define HOUR 10000
#define MINUTE 100

/**
* \brief Timestamp class, used to represent
*        a precise date and hour
*/
class Timestamp
{
  public:
    Timestamp();
    Timestamp(const Timestamp&) = default;
    Timestamp(const char* s);

    bool operator<(Timestamp t) const;
    bool operator<=(Timestamp t) const;
    bool operator>(Timestamp t) const;
    bool operator>=(Timestamp t) const;
    bool operator==(Timestamp t) const;

    friend std::ostream& operator<<(std::ostream& ostr, const Timestamp& ts);

  private:
    int date_;
    int hour_;
};

std::ostream& operator<<(std::ostream& ostr, const Timestamp& ts);
