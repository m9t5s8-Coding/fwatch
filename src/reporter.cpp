#include <iostream>
#include <reporter.hpp>

namespace fwatch
{

void Reporter::report_difference(SnapshotComparator::Diff& diff)
{
  if (!diff.added.empty())
  {
    std::cout << "    new files (" << diff.added.size() << " files)\n";
    for (const auto& f : diff.added)
      std::cout << '\t' << f << "\n";
    std::cout << "\n";
  }

  if (!diff.modified.empty())
  {
    std::cout << "    modified (" << diff.modified.size() << " files )\n";
    for (const auto& f : diff.modified)
      std::cout << '\t' << f << "\n";
    std::cout << "\n";
  }

  if (!diff.deleted.empty())
  {
    std::cout << "    deleted (" << diff.deleted.size() << " files)\n";
    for (const auto& f : diff.deleted)
      std::cout << '\t' << f << "\n";
    std::cout << "\n";
  }
}

static void print_summary(SnapshotComparator::Diff& diff)
{
  std::cout << "    summary: " << diff.added.size() << " new, " << diff.modified.size()
            << " modified, " << diff.deleted.size() << " deleted"
            << "\n";
}

static bool is_clean(SnapshotComparator::Diff& diff)
{
  return diff.added.empty() && diff.modified.empty() && diff.deleted.empty();
}

void Reporter::report_init(Snapshot& snapshot, const std::string& db_path)
{
  const auto& snap_map = snapshot.get();

  std::cout << '\n';
  for (const auto& [path, hash] : snap_map)
    std::cout << "    hashed\t" << path << "\n";

  std::cout << "\n    snapshot saved -> " << db_path << "  (" << snap_map.size() << " files)\n\n";
}

void Reporter::report_status(SnapshotComparator::Diff& diff)
{
  std::cout << "\n";

  if (is_clean(diff))
  {
    std::cout << "    nothing changed — snapshot is clean\n\n";
    return;
  }

  report_difference(diff);
  print_summary(diff);
  std::cout << '\n';
}

void Reporter::report_record(SnapshotComparator::Diff& diff, const std::string& db_path)
{
  std::cout << "\n";

  if (is_clean(diff))
  {
    std::cout << "    nothing changed — snapshot is clean\n\n";
    return;
  }

  report_difference(diff);
  print_summary(diff);

  std::cout << "    snapshot recorded -> " << db_path << "\n\n";
}

}  // namespace fwatch
