#pragma once
#include "sha_util.hpp"

#include <vector>

#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>

namespace core::common::sha_util {
  std::vector<CryptoPP::byte> sha256(std::string_view x) {
    CryptoPP::SHA256 hash;
    std::vector<CryptoPP::byte> returned(hash.DigestSize());

    hash.Update((const CryptoPP::byte *)x.data(), x.size());
    hash.Final(returned.data());

    return returned;
  }

  std::string bytesToString(std::vector<CryptoPP::byte> const &bytes) {
    std::string encoded;
    CryptoPP::StringSource stringSource(
        bytes.data(),
        bytes.size(),
        true,
        new CryptoPP::HexEncoder(new CryptoPP::StringSink(encoded)));
    return encoded;
  }
}  // namespace core::common::sha_util
