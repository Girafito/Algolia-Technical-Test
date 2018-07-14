#pragma once
#include "logs.hh"

/**
* \brief ToJson class, used to generate Json responses
*        to top and count queries
*/
class ToJson
{
  public:
    ToJson() = default;
    ToJson(const ToJson&) = delete;
    ToJson(char* filename);

    void top(std::string s, std::string size);
    void count(std::string s);

    const std::string& get_str() const;
    char* get_filename() const;
    void set_filename(char* filename);
    void reset();

    private:
     Logs logs_;
     char* filename_;
     std::string str_;
};
