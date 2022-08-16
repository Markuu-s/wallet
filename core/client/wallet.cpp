#include "wallet/wallet.h"
#include "../common/sha_util.hpp"  // TODO fix this.
#include "Client.hpp"

#include <iostream>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

using core::common::sha_util::bytesToString;
using core::common::sha_util::sha256;

inline std::string getPassword(std::string_view password) {
  return bytesToString(sha256(password));
}

Errors connectServer(User user) {
  core::client::Client::connect("127.0.0.1", 8080);
  return Errors::WALLET_OK;
}

Errors disconnectServer(User) {
  return Errors::WALLET_OK;
}

Errors addBalance(User user, BalanceAsset balance_asset, double add) {
  core::client::Client::sendReceive(
      "addBalance", user.login, getPassword(user.password), balance_asset, add);

  return Errors::WALLET_OK;
}

Errors setBalance(User user, BalanceAsset balance_asset, double set) {
  core::client::Client::sendReceive(
      "setBalance", user.login, getPassword(user.password), balance_asset, set);
  return Errors::WALLET_OK;
}

Errors getBalance(User user, ...) {
//  core::client::Client::sendReceive(
//      "getBalance", user.login, getPassword(user.password), ...);
// TODO transfer parametrs via va_list and etc.
  return Errors::WALLET_OK;
}

#ifdef __cplusplus
}
#endif