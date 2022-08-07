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
};

typedef struct {
  char *login;
  char *password;
} User;

Errors connect_server(User);
Errors disconnect_server(User);

Errors add_balance(User, BalanceAsset, double add);
Errors set_balance(User, BalanceAsset, double set);

/*
 * Usage:
 * get_all_relative_balance(User,
 *                          BalanceAsset, double*,
 *                          BalanceAsset, double*,
 *                          ...);
 */
Errors get_balance(User, ...);

#ifdef __cplusplus
}
#endif
