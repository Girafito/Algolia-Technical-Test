#include "timerange.hh"

#define DATE_SIZE 19

Timerange::Timerange(std::string& s)
{
  std::string s_inf, s_sup;
  size_t len = s.size();
  size_t i = 0;
  while (i < len)
  {
    s_inf.push_back(s[i]);
    s_sup.push_back(s[i]);
    i++;
  }
  while (i < DATE_SIZE)
  {
    s_inf.push_back('0');
    s_sup.push_back('9');
    i++;
  }
  inf_ = Timestamp(s_inf.c_str());
  sup_ = Timestamp(s_sup.c_str());
}

const Timestamp& Timerange::inf_get() const
{
  return inf_;
}

const Timestamp& Timerange::sup_get() const
{
  return sup_;
}

std::ostream& operator<<(std::ostream& ostr, const Timerange& ts)
{
  ostr << ts.inf_ << std::endl << ts.sup_ ;
  return ostr;
}
