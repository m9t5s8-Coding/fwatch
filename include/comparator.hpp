#pragma once
#include <filesystem>
#include <snapshot.hpp>
#include <vector>

namespace fwatch
{
class SnapshotComparator
{
public:
  struct Diff
  {
    std::vector<std::string> added;
    std::vector<std::string> modified;
    std::vector<std::string> deleted;
  };

  Diff compare(Snapshot& old_snap, Snapshot& new_snap);
};
}  // namespace fwatch
