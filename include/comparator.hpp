#pragma once
#include <filesystem>
#include <snapshot.hpp>
#include <vector>

namespace gm
{
class SnapshotComparator
{
public:
  struct Diff
  {
    std::vector<std::filesystem::path> added;
    std::vector<std::filesystem::path> modified;
    std::vector<std::filesystem::path> deleted;
  };

  Diff compare(const Snapshot& old_snap, const Snapshot& new_snap);
};
}  // namespace gm
