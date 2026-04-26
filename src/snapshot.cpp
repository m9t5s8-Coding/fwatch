#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <snapshot.hpp>

using json = nlohmann::json;

namespace fwatch
{
void Snapshot::save(const std::filesystem::path& db_path) const
{
  json j;
  j["files"] = json::array();

  for (const auto& [path, hash] : m_data)
  {
    j["files"].push_back({
        {"path", path},
        {"hash", hash}
    });
  }
  std::filesystem::create_directories(db_path.parent_path());
  std::ofstream out(db_path);
  out << j.dump(4);
}

void Snapshot::load(const std::filesystem::path& db_path)
{
  std::ifstream in(db_path);
  if (!in)
    throw std::runtime_error("no snapshot found. Run fwatch init");

  json j = json::parse(in);
  m_data.clear();

  for (const auto& entry : j["files"])
    m_data[entry["path"]] = entry["hash"];
}

}  // namespace fwatch
