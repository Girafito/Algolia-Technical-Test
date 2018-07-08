#pragma once

class Timestamp
{
  public:
    Timestamp(const char* s);

    bool operator<(Timestamp t) const;
    bool operator<=(Timestamp t) const;
    bool operator>(Timestamp t) const;
    bool operator>=(Timestamp t) const;
    bool operator==(Timestamp t) const;
  private:
    int date_;
    int hour_;
};
