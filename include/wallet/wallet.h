#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

enum BalanceAsset {
  RUBBLES,
  DOLLARS,
  ETH,
  BTC,
  XSTUSD,
};

enum Errors {
  WALLET_OK = 0,
  SERVER_ERROR,
  BUFFER_ERROR,

  LOGIN_BUSY,
  WRONG_PASSWORD,
};

typedef struct {
  char *login;
  char *password;
} User;

Errors connectServer(User);
Errors disconnectServer(User);

Errors addBalance(User, BalanceAsset, double add);
Errors setBalance(User, BalanceAsset, double set);

/*
 * Usage:
 * get_all_relative_balance(User,
 *                          BalanceAsset, double*,
 *                          BalanceAsset, double*,
 *                          ...);
 */
Errors getBalance(User, ...);

#ifdef __cplusplus
}
#endif
