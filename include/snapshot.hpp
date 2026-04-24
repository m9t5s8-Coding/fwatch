#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>

namespace gm
{
class Snapshot
{
public:
  void add(const std::filesystem::path& data, const std::string& hash);
  const std::unordered_map<std::filesystem::path, std::string>& get() const
  {
    return m_data;
  }

private:
  std::unordered_map<std::filesystem::path, std::string> m_data;
};
}  // namespace gm
