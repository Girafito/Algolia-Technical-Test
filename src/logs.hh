#pragma once

#include <memory>
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
#include <string_view>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#include "timestamp.hh"
#include "timerange.hh"

class Logs
{
  public:
    using LogOcc = std::unordered_map<std::string_view, size_t>;
    using LogMap = std::map<Timestamp, LogOcc>;

    Logs(char* filename);
    ~Logs();
    size_t str_to_timestamp(const char* s);
    void parseFile();

    void top(Timerange tr, int n);
    size_t count(Timerange tr);

  private:
    int fd_;
    struct tm* timeinfo_;
    size_t size_;
    void* mmap_ptr_;
    LogMap log_map_;
};
