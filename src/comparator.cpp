#include <comparator.hpp>

namespace fwatch
{
SnapshotComparator::Diff SnapshotComparator::compare(Snapshot& old_snap, Snapshot& new_snap)
{
  SnapshotComparator::Diff diff;

  const auto& old_map = old_snap.get();
  const auto& new_map = new_snap.get();

  for (const auto& [path, new_hash] : new_map)
  {
    auto old_it = old_map.find(path);

    if (old_it == old_map.end())
      diff.added.push_back(path);
    else if (old_it->second != new_hash)
      diff.modified.push_back(path);
  }

  for (const auto& [path, old_hash] : old_map)
  {
    if (new_map.find(path) == new_map.end())
      diff.deleted.push_back(path);
  }
  return diff;
}
}  // namespace fwatch
