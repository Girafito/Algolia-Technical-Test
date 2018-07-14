#pragma once

#include <memory>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string_view>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#include "timestamp.hh"
#include "timerange.hh"

/**
* \brief Logs class, used to parse the log file and
*        execute top and count search on the parsed data
*
* \note  The file is supposed to be a well formated TSV file.
*/

class Logs
{
  public:
    using LogOcc = std::unordered_map<std::string_view, size_t>;
    using LogMap = std::map<Timestamp, LogOcc>;

    Logs() = default;
    Logs(const Logs&) = delete;
    Logs(char* filename);
    ~Logs();

    /**
    * \brief Parse the input file and build the map.
    */
    void parseFile();

    /**
    * \brief Extract the n most popular queries during
    *        the time range tr
    */
    std::vector<std::pair<std::string_view, size_t>>
    top(Timerange& tr, size_t& n) const;

    /**
    * \brief Count the number of queries done during the time range tr
    */
    size_t count(Timerange tr) const;

    /**
    * \brief Open the file and mmap it
    * \param filename The name of the file to map
    */
    void reset(char* filename);

  private:
    int fd_;
    struct tm* timeinfo_;
    size_t size_;
    void* mmap_ptr_;
    LogMap log_map_;

    /**
    * \brief Dump the log map. Used for debug.
    */
    void dump_log_map() const;
};
