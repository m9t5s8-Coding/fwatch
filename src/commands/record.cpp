#include <commands/record.hpp>
#include <comparator.hpp>
#include <hasher.hpp>
#include <reporter.hpp>
#include <scanner.hpp>
#include <snapshot.hpp>
#include <snapshotbuilder.hpp>

namespace fwatch
{
void RecordCommand::run(const std::vector<std::string>& args)
{
  std::filesystem::path root    = args.empty() ? "." : args.front();
  std::string           db_path = ".fwatch/hashes.db";

  fwatch::Scanner            scanner;
  fwatch::Hasher             hasher;
  fwatch::SnapshotBuilder    snapshot_builder;
  fwatch::Snapshot           old_snapshot;
  fwatch::SnapshotComparator comparator;
  fwatch::Reporter           reporter;

  old_snapshot.load(db_path);

  auto files        = scanner.scan_directory(args.front());
  auto new_snapshot = snapshot_builder.build(files, hasher, root);

  auto diff = comparator.compare(old_snapshot, new_snapshot);

  new_snapshot.save(db_path);
  reporter.report_record(diff, db_path);
}
}  // namespace fwatch
