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

Errors connectServer(User user) {
  std::cout << user.login << ' ' << user.password << '\n';
  std::cout << bytesToString(sha256(user.password));

  return Errors::WALLET_OK;
}

Errors disconnectServer(User) {
  return Errors::WALLET_OK;
}

Errors addBalance(User user, BalanceAsset balanceAsset, double add) {
  core::client::Client::sendReceive("addBalance",
                                    user.login,
                                    bytesToString(sha256(user.password)),
                                    balanceAsset,
                                    add);

  return Errors::WALLET_OK;
}

Errors setBalance(User, BalanceAsset, double set) {
  return Errors::WALLET_OK;
}

Errors getBalance(User, ...) {
  return Errors::WALLET_OK;
}

#ifdef __cplusplus
}
#endif