#include <openssl/evp.h>

#include <filesystem>
#include <fstream>
#include <hasher.hpp>
#include <iomanip>
#include <sstream>
#include <vector>

namespace fwatch
{

std::string Hasher::hash_file(const std::filesystem::path& file_path)
{
  std::ifstream file(file_path, std::ios::binary);

  if (!file)
    throw std::runtime_error("Cannot open file");

  EVP_MD_CTX*   ctx = EVP_MD_CTX_new();
  const EVP_MD* md  = EVP_get_digestbyname("sha256");
  if (!md)
    throw std::runtime_error("Unknown Algorithm");

  EVP_DigestInit_ex(ctx, md, nullptr);

  const size_t      CHUNK_SIZE = 65536;
  std::vector<char> buffer(CHUNK_SIZE);

  while (file.read(buffer.data(), CHUNK_SIZE) || file.gcount() > 0)
  {
    EVP_DigestUpdate(ctx, buffer.data(), file.gcount());
  }

  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int  hash_len = 0;

  EVP_DigestFinal_ex(ctx, hash, &hash_len);
  EVP_MD_CTX_free(ctx);

  std::ostringstream oss;
  for (unsigned int i = 0; i < hash_len; i++)
  {
    oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }

  return oss.str();
}
}  // namespace fwatch
