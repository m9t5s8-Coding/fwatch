#pragma once
#include <filesystem>
#include <string>

namespace fwatch
{
class Hasher
{
public:
  std::string hash_file(const std::filesystem::path& file_path);
};
}  // namespace fwatch
