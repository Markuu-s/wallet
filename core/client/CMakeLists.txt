add_library(Wallet wallet.cpp)
target_link_libraries(Wallet ${CONAN_LIBS})

add_library(Client Client.cpp)