#include "timestamp.hh"

Timestamp::Timestamp()
  : date_(0)
  , hour_(0)
{}


Timestamp::Timestamp(const char *s)
  : date_(((s[0] - '0') * 1000 + (s[1] - '0') * 100 +
          (s[2] - '0') * 10 + (s[3] - '0')) * YEAR +
          ((s[5]- '0') * 10 + (s[6] - '0')) * MONTH +
          (s[8] - '0') * 10 + s[9] - '0')
  , hour_(((s[11] - '0') * 10 + (s[12] - '0')) * HOUR +
          ((s[14] - '0') * 10 + (s[15] - '0')) * MINUTE +
          (s[17] - '0') * 10 + s[18] - '0')
{}

bool Timestamp::operator<(Timestamp t) const
{
  if (date_ > t.date_)
    return false;
  return date_ < t.date_ || hour_ < t.hour_;
}

bool Timestamp::operator<=(Timestamp t) const
{
  if (date_ > t.date_)
    return false;
  return date_ < t.date_ || hour_ <= t.hour_;
}

bool Timestamp::operator>(Timestamp t) const
{
  if (date_ < t.date_)
    return false;
  return date_ > t.date_ || hour_ > t.hour_;
}

bool Timestamp::operator>=(Timestamp t) const
{
  if (date_ < t.date_)
    return false;
  return date_ > t.date_ || hour_ >= t.hour_;
}

bool Timestamp::operator==(Timestamp t) const
{
  return date_ == t.date_ && hour_ == t.hour_;
}

std::ostream& operator<<(std::ostream& ostr, const Timestamp& ts)
{
  ostr << ts.date_ / 10000 << "-" << ts.date_ / 100 % 100 << "-"
       << ts.date_ % 100 << " ";
  ostr << ts.hour_ / 10000 << "-" << ts.hour_ / 100 % 100 << "-"
       << ts.hour_ % 100;
  return ostr;
}
