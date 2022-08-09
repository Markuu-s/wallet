#include <string>
#include <vector>

#include <cryptopp/cryptlib.h>

namespace core::common::sha_util {
  std::vector<CryptoPP::byte> SHA256(std::string_view x);

  std::string bytes_to_string(std::vector<CryptoPP::byte> const &bytes);
}  // namespace core::common::sha_util
