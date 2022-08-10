#include "wallet/wallet.h"
#include "common/sha_util.hpp"
#include <iostream>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

using core::common::sha_util::bytes_to_string;
using core::common::sha_util::SHA256;

Errors connect_server(User user) {
  std::cout << user.login << ' ' << user.password << '\n';
  std::cout << bytes_to_string(SHA256(user.password));

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