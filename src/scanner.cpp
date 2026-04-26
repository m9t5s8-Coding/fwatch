#include <scanner.hpp>

namespace fwatch
{
std::vector<std::filesystem::path> Scanner::scan_directory(const std::filesystem::path& root)
{
  std::vector<std::filesystem::path> files;

  if (std::filesystem::is_directory(root))
  {
    for (const auto& dir_entry : std::filesystem::recursive_directory_iterator(root))
    {
      if (!dir_entry.is_regular_file())
        continue;

      std::filesystem::path relative_path = std::filesystem::relative(dir_entry.path(), root);

      if (relative_path.begin()->string() == ".fwatch")
        continue;

      files.push_back(relative_path);
    }
  }

  return files;
}
}  // namespace fwatch
