#pragma once
#include <iostream>

#include "timestamp.hh"

class Timerange
{
  public:
    Timerange(std::string& s);
    friend std::ostream& operator<<(std::ostream& ostr, const Timerange& ts);
    Timestamp& inf_get();
    Timestamp& sup_get();
  private:
    Timestamp inf_;
    Timestamp sup_;
};

std::ostream& operator<<(std::ostream& ostr, const Timerange& ts);
