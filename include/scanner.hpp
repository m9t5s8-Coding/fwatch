#pragma once
#include <filesystem>
#include <vector>

namespace fwatch
{
class Scanner
{
public:
  std::vector<std::filesystem::path> scan_directory(const std::filesystem::path& root);
};
}  // namespace fwatch
