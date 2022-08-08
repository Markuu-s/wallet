add_library(Wallet wallet.cpp)
target_link_libraries(Wallet cryptopp)

add_library(Client Client.cpp)