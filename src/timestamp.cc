#include "timestamp.hh"

Timestamp::Timestamp(const char *s)
  : date_((*s - 48) * 10000000 + (*(s + 1) - 48) * 1000000 +
          (*(s + 2) - 48) * 100000 + (*(s + 3) - 48) * 10000 +
          (*(s + 5) - 48) * 1000 + (*(s + 6) - 48) * 100 +
          (*(s + 8) - 48) * 10 + *(s + 9) - 48)
  , hour_((*(s + 11) - 48) * 100000 + (*(s + 12) - 48) * 10000 +
          (*(s + 14) - 48) * 1000 + (*(s + 15) - 48) * 100 +
          (*(s + 17) - 48) * 10 + *(s + 18) - 48)
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
  ostr << ts.hour_ / 10000 << "-" << ts.hour_ / 100 % 100 << "-" << ts.hour_ % 100;
  return ostr;
}
