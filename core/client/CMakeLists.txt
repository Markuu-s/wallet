add_library(Wallet wallet.cpp)
target_link_libraries(Wallet cryptopp-static)

add_library(Client Client.cpp)