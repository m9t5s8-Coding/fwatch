
#pragma once

#include <commands/command.hpp>

namespace fwatch
{
class ScanCommand : public Command
{
public:
  virtual void run(const std::vector<std::string>& args) override;
};
}  // namespace fwatch
