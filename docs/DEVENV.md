#### WORK IN PROGRESS ### 


# Setting up a development environment

This document discusses how to setup a development environment for build SSP modules.



# General procedure

there are 3 general steps to setting up our environment for building SSP modules.
this document covers the first two step, the others are covered in the BUILDING document.


- install development tools 
- install required libraries (VST SDK and SSP Buildroot)
- download repository with code
- prepare build
- build module


# install Linux development tools 
```
    sudo apt install cmake git llvm clang g++-10-arm-linux-gnueabihf 
```
this is debian package manager, similar with pacman etc on other distros

(although this is v10 of g++ others will likely work)


# install macOS development using homebrew
homebrew is useful package manager for macos for many open source tools.
highly recommended :)  see https://brew.sh



```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install cmake git llvm 

```
(some installs may need arm-linux-gnueabihf-binutils, gcc-arm-embedded)


## mac m1 - homebrew config
place the following in .zshrc
```
export PATH=/opt/homebrew/bin:"${PATH}"
```

## intel macs - homebrew config 
place the following in .zshrc/.bashrc as appropiate.


```
export TOOLSROOT=/usr/local/opt/llvm/bin
export PATH=/usr/local/bin:"${PATH}"
```

this is required to place build tools on your path.
TOOLSROOT in the cmake file default to the M1 location for homebrew.
but the above overrides for where homebrew is placed for intel macs.



# setup requirements for build

we need a copy of the build root for the SSP to build
this is detailed in this post
https://forum.percussa.com/t/update-13072022-superbooth-2022-sd-card-image-fixes-for-usb-audio-sample-rate-switching-asio-support/1556

we need to download from :
https://sw13072022.s3.us-west-1.amazonaws.com/arm-rockchip-linux-gnueabihf_sdk-buildroot.tar.gz

unzip into `~/buildroot` e.g.

```
mkdir ~/buildroot
cd ~/buildroot
mv ~/Downloads/arm-rockchip-linux-gnueabihf_sdk-buildroot.tar.gz  .
tar xzf arm-rockchip-linux-gnueabihf_sdk-buildroot.tar.gz
```

the location of the buildroot can be changed e.g.
```
export BUILDROOT=$HOME/buildroot/ssp/arm-rockchip-linux-gnueabihf_sdk-buildroot
```

### VST SDK

the modules are build as VST3 with an interface that then bridges this to the SSP SDK.
so, we also need to download the VST 3 SDK from steinberg and place into SDKs dirctory
https://www.steinberg.net/developers/


by defaul build expects the '~/SDKs/'
```
mkdir ~/SDKs
cd ~/SDKs
```
then unzip into this diretory

note: expecting SDK in $HOME/SDKs/vst3-sdk", 

this directory can be overrided e.g. 
```
export VSTSDK=$HOME/SDKs/vst3-sdk
```

## build environment 

## TODO : talk about using llvm as cross compiler and the role of build root ## 


## building 

```
cd examples
mkdir build 
cd build 
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../xcSSP.cmake .. 
cmake --build . -- -j 8 
```






