#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>

namespace fwatch
{
class Snapshot
{
public:
  void add(const std::filesystem::path& data, const std::string& hash)
  {
    m_data[data.string()] = hash;
  }
  const std::unordered_map<std::string, std::string>& get() const
  {
    return m_data;
  }
  std::unordered_map<std::string, std::string>& get()
  {
    return m_data;
  }

  void save(const std::filesystem::path& db_path) const;
  void load(const std::filesystem::path& db_path);

private:
  std::unordered_map<std::string, std::string> m_data;
};
}  // namespace fwatch
