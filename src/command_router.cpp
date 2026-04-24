#include <command_router.hpp>
#include <commands/command.hpp>
#include <commands/command_header.hpp>
#include <memory>
#include <unordered_map>

namespace fwatch
{
void execute_command(const std::string& cmd, const std::vector<std::string>& args)
{
  std::unordered_map<std::string, std::unique_ptr<Command>> command_table;

  command_table["help"]   = std::make_unique<HelpCommand>();
  command_table["init"]   = std::make_unique<InitCommand>();
  command_table["scan"]   = std::make_unique<ScanCommand>();
  command_table["status"] = std::make_unique<StatusCommand>();

  auto it = command_table.find(cmd);
  if (it != command_table.end())
  {
    it->second->run(args);
  }
}
}  // namespace fwatch
