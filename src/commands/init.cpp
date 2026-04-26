#include <commands/init.hpp>
#include <hasher.hpp>
#include <reporter.hpp>
#include <scanner.hpp>
#include <snapshot.hpp>
#include <snapshotbuilder.hpp>

namespace fwatch
{
void InitCommand::run(const std::vector<std::string>& args)
{
  std::filesystem::path root    = args.empty() ? "." : args.front();
  std::string           db_path = ".fwatch/hashes.db";

  fwatch::Scanner         scanner;
  fwatch::Hasher          hasher;
  fwatch::SnapshotBuilder snapshot_builder;
  fwatch::Reporter        reporter;

  auto files    = scanner.scan_directory(args.front());
  auto snapshot = snapshot_builder.build(files, hasher, root);

  snapshot.save(db_path);
  reporter.report_init(snapshot, db_path);
}
}  // namespace fwatch
