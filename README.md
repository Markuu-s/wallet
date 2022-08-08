# Wallet library-Client and Server

A multiplatform library for controlling cryptocurrencies from all wallets to see how much fiat money you currently have

## Build on Unix System
```
sudo python3 -m pip install conan
git clone https://github.com/Markuu-s/wallet/ && cd wallet 
git submodule update --init --recursive

mkdir cmake_build && cd cmake_build

# For MacOs: 
conan install ..
# For Ubuntu:
conan install .. compiler.libcxx=libstdc++11 --build=missing

cmake ..
cmake --build . --config Release

```
