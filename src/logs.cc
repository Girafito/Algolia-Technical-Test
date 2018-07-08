#include "logs.hh"

Logs::Logs(char* filename)
  : fd_( open(filename, O_RDONLY))
{
  struct stat st;
  fstat(fd_, &st);
  size_ = st.st_size;

  mmap_ptr_ = mmap(NULL, size_, PROT_READ, MAP_SHARED, fd_, 0);

  time_t rawtime;
  time(&rawtime);
  timeinfo_ = localtime(&rawtime);
  parseFile();
}

Logs::~Logs()
{
  close(fd_);
  munmap(mmap_ptr_, size_);
}

void dump_log_map(Logs::LogMap lm)
{
  for (auto it1 = lm.begin(); it1 != lm.end(); it1++)
  {
    for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
    {
      for (size_t i = 0; i < it2->second; i++)
      {
        std::cout << it1->first << "\t" << it2->first << std::endl;
      }
    }
  }
}

void Logs::parseFile()
{
  const char* logfile = static_cast<const char*>(mmap_ptr_);
  std::cout << "Parsing log file please wait." << std::endl;
  size_t index = 0;
  size_t len;
  size_t nb_logs = 0;
  while (index < size_)
  {
    len = 0;
    Timestamp ts(logfile + index);
    index += 20;
    while (index + len < size_ && *(logfile + index + len) != '\n')
      len++;
    std::string_view log(logfile + index, len);
    log_map_[ts][log] += 1;
    index += len + 1;
    nb_logs++;
  }
  std::cout << "Done, " << nb_logs << " logs parsed." << std::endl;

//  dump_log_map(log_map_);
}
