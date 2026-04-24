#include <scanner.hpp>

namespace gm
{
std::vector<std::filesystem::path> Scanner::scan_directory(std::filesystem::path& root)
{
  std::vector<std::filesystem::path> files;

  if (std::filesystem::is_directory(root))
  {
    for (const auto& dir_entry : std::filesystem::recursive_directory_iterator(root))
    {
      if (dir_entry.is_regular_file())
      {
        files.push_back(dir_entry.path());
      }
    }
  }

  return files;
}
}  // namespace gm
