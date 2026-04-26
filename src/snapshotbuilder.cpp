#include <snapshotbuilder.hpp>

namespace fwatch
{
Snapshot SnapshotBuilder::build(const std::vector<std::filesystem::path>& files,
                                Hasher&                                   hasher,
                                const std::string&                        root)
{
  Snapshot snapshot;

  for (const auto& relative_path : files)
  {
    std::filesystem::path full_path = root / relative_path;

    auto hash = hasher.hash_file(full_path);
    snapshot.add(relative_path, hash);
  }

  return snapshot;
}
}  // namespace fwatch
