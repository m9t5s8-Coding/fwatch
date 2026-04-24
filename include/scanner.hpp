#pragma once
#include <filesystem>
#include <vector>

namespace gm
{
class Scanner
{
public:
  std::vector<std::filesystem::path> scan_directory(std::filesystem::path& root);
};
}  // namespace gm
