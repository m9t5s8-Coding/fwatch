#pragma once

#include <hasher.hpp>
#include <snapshot.hpp>
#include <vector>

namespace gm
{
class SnapshotBuilder
{
public:
  Snapshot build(const std::vector<std::filesystem::path>& files, Hasher& hasher);
};
}  // namespace gm
