#pragma once
#include <iostream>

#include "timestamp.hh"

/**
* \brief Timerange class, used to represent a
*        time range with two Timestamps
*/
class Timerange
{
  public:
    Timerange() = delete;
    Timerange(const Timerange&) = default;
    Timerange(std::string& s);

    friend std::ostream& operator<<(std::ostream& ostr, const Timerange& ts);

    const Timestamp& inf_get() const;
    const Timestamp& sup_get() const;

  private:
    Timestamp inf_;
    Timestamp sup_;
};

std::ostream& operator<<(std::ostream& ostr, const Timerange& ts);
