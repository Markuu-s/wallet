#include <string>
#include <vector>

#include <cryptopp/cryptlib.h>

namespace core::common::sha_util {
  std::vector<CryptoPP::byte> sha256(std::string_view x);

  std::string bytesToString(std::vector<CryptoPP::byte> const &bytes);
}  // namespace core::common::sha_util
