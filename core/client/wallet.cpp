#include "wallet/wallet.h"
#include "cryptopp/sha.h"

#ifdef __cplusplus
extern "C" {
#endif

Errors connect_server(User) {
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