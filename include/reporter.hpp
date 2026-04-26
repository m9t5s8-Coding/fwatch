#pragma once

#include <comparator.hpp>
#include <snapshot.hpp>

namespace fwatch
{
class Reporter
{
public:
  void report_init(Snapshot& snapshot, const std::string& db_path);
  void report_status(SnapshotComparator::Diff& diff);
  void report_record(SnapshotComparator::Diff& diff, const std::string& db_path);

private:
  void report_difference(SnapshotComparator::Diff& diff);
};
}  // namespace fwatch
