#pragma once

#include <hasher.hpp>
#include <snapshot.hpp>
#include <vector>

namespace fwatch
{
class SnapshotBuilder
{
public:
  Snapshot
  build(const std::vector<std::filesystem::path>& files, Hasher& hasher, const std::string& root);
};
}  // namespace fwatch
