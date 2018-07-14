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

void Logs::dump_log_map() const
{
  for (auto it1 = log_map_.begin(); it1 != log_map_.end(); it1++)
    for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
      for (size_t i = 0; i < it2->second; i++)
        std::cout << it1->first << "\t" << it2->first << std::endl;
}



std::vector<std::pair<std::string_view, size_t>>
Logs::top(Timerange& range, size_t& n) const
{
  auto low = log_map_.lower_bound(range.inf_get());
  auto up = log_map_.upper_bound(range.sup_get());
  Logs::LogOcc log_count;

  for (; low != up; low++)
    for (auto it = low->second.begin(); it != low->second.end(); it++)
      log_count[it->first] += it->second;

  std::vector<std::pair<std::string_view, size_t>> res(n);
  std::partial_sort_copy(log_count.begin(), log_count.end(),
                         res.begin(), res.end(),
                         [](auto& a, auto& b){return a.second > b.second;});

  return res;
}

size_t Logs::count(Timerange range) const
{
  auto low = log_map_.lower_bound(range.inf_get());
  auto up = log_map_.upper_bound(range.sup_get());
  std::unordered_map<std::string_view, size_t> log_count;

  for (; low != up; low++)
    for (auto it = low->second.begin(); it != low->second.end(); it++)
      log_count[it->first] += it->second;

   return log_count.size();
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
    while (index + len < size_ && logfile[index + len] != '\n')
      len++;
    std::string_view log(logfile + index, len);
    log_map_[ts][log] += 1;
    index += len + 1;
    nb_logs++;
  }
  std::cout << "Done, " << nb_logs << " logs parsed." << std::endl;
}
void Logs::reset(char* filename)
{
  close(fd_);
  munmap(mmap_ptr_, size_);
  fd_ = open(filename, O_RDONLY);
  mmap_ptr_ = mmap(NULL, size_, PROT_READ, MAP_SHARED, fd_, 0);
}
