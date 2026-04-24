#pragma once
#include <filesystem>
namespace gm
{
class Hasher
{
public:
  std::string hash_file(const std::filesystem::path& file_path);
};
}  // namespace gm
