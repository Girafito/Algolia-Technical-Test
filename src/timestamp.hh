#pragma once

#include <iostream>

class Timestamp
{
  public:
    Timestamp(const char* s);
    Timestamp();

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
