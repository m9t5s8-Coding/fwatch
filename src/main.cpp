#include <command_router.hpp>
#include <filesystem>
#include <iostream>

int main(int argc, const char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Usuage: fwatch [command]\n";
    return 0;
  }

  std::string cmd = argv[1];

  std::vector<std::string> args;
  args.push_back(std::filesystem::current_path().string());
  for (int i = 2; i < argc; i++)
  {
    args.push_back(argv[i]);
  }

  fwatch::execute_command(cmd, args);

  for (const auto& arg : args)
  {
    std::cout << arg << '\n';
  }

  return 0;
}
