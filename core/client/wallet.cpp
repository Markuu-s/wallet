#include "wallet/wallet.h"

#ifdef __cplusplus
extern "C" {
#endif

Errors add_balance(BalanceAsset, double add) {
    return Errors::WALLET_OK;
}

Errors set_balance(BalanceAsset, double set) {
    return Errors::WALLET_OK;
}

Errors get_balance(...) {
    return Errors::WALLET_OK;
}

#ifdef __cplusplus
}
#endif