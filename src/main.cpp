#include <command_router.hpp>
#include <filesystem>
#include <iostream>

#define FWATCH_VERSION "0.1.0"

int main(int argc, const char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Usuage: fwatch [command]\n";
    return 0;
  }

  std::string cmd = argv[1];

  if (cmd == "--version")
  {
    std::cout << "fwatch version " << FWATCH_VERSION << '\n';
    return 0;
  }

  if (cmd == "--help")
  {
    std::cout << "fwatch - file watcher tool\n";
    std::cout << "Useage: fwatch [command]\n";
    return 0;
  }

  std::vector<std::string> args;
  args.push_back(std::filesystem::current_path().string());
  for (int i = 2; i < argc; i++)
  {
    args.push_back(argv[i]);
  }

  fwatch::execute_command(cmd, args);

  return 0;
}
