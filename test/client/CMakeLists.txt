add_executable(CLIENT_TEST client_test.cpp)
target_link_libraries(CLIENT_TEST
        GTest::gtest_main)

add_executable(WALLET_TEST wallet_test.cpp)
target_link_libraries(WALLET_TEST
        GTest::gtest_main
        Wallet)