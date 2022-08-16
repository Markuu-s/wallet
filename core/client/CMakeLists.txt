add_library(Wallet STATIC
        wallet.cpp Client.cpp)
target_link_libraries(Wallet
        sha_util
        nlohmann_json
        Boost::asio)
