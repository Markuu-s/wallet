#include "wallet/wallet.h"

#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>

#include <iostream>
#include <string>

void SHA256(std::string_view x) {
  CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));

  CryptoPP::SHA256 hash;
  hash.Update((const CryptoPP::byte *)x.data(), x.size());

  std::string returned;
  returned.resize(hash.DigestSize());
  hash.Final((CryptoPP::byte *)returned.data());

  CryptoPP::StringSource(returned, true, new CryptoPP::Redirector(encoder));
}

#ifdef __cplusplus
extern "C" {
#endif

Errors connect_server(User user) {
  std::cout << user.login << ' ' << user.password << '\n';
  SHA256(user.password);
  return Errors::WALLET_OK;
}

Errors disconnect_server(User) {
  return Errors::WALLET_OK;
}

Errors add_balance(User, BalanceAsset, double add) {
  return Errors::WALLET_OK;
}

Errors set_balance(User, BalanceAsset, double set) {
  return Errors::WALLET_OK;
}

Errors get_balance(User, ...) {
  return Errors::WALLET_OK;
}

#ifdef __cplusplus
}
#endif