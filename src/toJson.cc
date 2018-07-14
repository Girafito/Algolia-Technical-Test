#include "toJson.hh"

ToJson::ToJson(char* filename)
  : logs_(Logs(filename))
  , filename_(filename)
{}

void ToJson::count(std::string s)
{
  Timerange tr(s);
  auto c = logs_.count(tr);
  str_ += "{\"count\":" + std::to_string(c) + "}";
}

void ToJson::top(std::string s, std::string size)
{
  auto nb = std::stoul(size);
  Timerange tr(s);
  auto vec = logs_.top(tr, nb);
  str_ += "{\"queries\":[";
  for (auto pair: vec)
  {
    str_ += "{\"query\":\"";
    str_ += pair.first;
    str_ += "\", \"count\":";
    str_ += std::to_string(pair.second);
    str_ += "}";
    if (pair != vec.back())
      str_ += ",";
  }
  str_ += "]}";
}

const std::string& ToJson::get_str() const
{
  return str_;
}

char* ToJson::get_filename() const
{
  return filename_;
}

void ToJson::set_filename(char* filename)
{
  filename_ = filename;
}

void ToJson::reset()
{
  logs_.reset(filename_);
  str_ = std::string();
}
