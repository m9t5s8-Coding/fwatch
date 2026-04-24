#pragma once
#include <string>
#include <vector>

namespace fwatch
{
class Command
{
public:
  virtual void run(const std::vector<std::string>& args) = 0;

  virtual ~Command() = default;
};
}  // namespace fwatch
