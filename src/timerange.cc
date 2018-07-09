#include "timerange.hh"

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
  while (i < 19)
  {
    s_inf.push_back('0');
    s_sup.push_back('9');
    i++;
  }
  inf_ = Timestamp(s_inf.c_str());
  sup_ = Timestamp(s_sup.c_str());
}

Timestamp& Timerange::inf_get()
{
  return inf_;
}

Timestamp& Timerange::sup_get()
{
  return sup_;
}

std::ostream& operator<<(std::ostream& ostr, const Timerange& ts)
{
  ostr << ts.inf_ << std::endl << ts.sup_ ;
  return ostr;
}
