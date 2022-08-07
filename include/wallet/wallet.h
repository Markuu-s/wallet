#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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

Errors connect_server();
Errors disconnect_server();

Errors add_balance(BalanceAsset, double add);
Errors set_balance(BalanceAsset, double set);

/*
 * Usage:
 * get_all_relative_balance(BalanceAsset, double*,
 *                          BalanceAsset, double*,
 *                          ...);
 */
Errors get_balance(...);

#ifdef __cplusplus
}
#endif
