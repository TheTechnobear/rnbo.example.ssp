# Building SSP modules from Max RNBO patches

this project is designed to allow non-developers to create modules for the Percussa SSP,  using  [Cycling 74s RNBO](https://cycling74.com/products/rnbo)

modules created are completely independent of RNBO, and so can be **used** without a Max or RNBO license.


# Requirements

This projects currently is only support on macOS and Linux.

Whilst windows users could modify build files, this is non-trivial.
I would recommend installing a Virtual Machine (VM), and run Linux under windows.


# Getting Started

There are two steps for creating Percussa SSP modules based on RNBO

first, is to create a 'development environment', covered in [docs/DEVENV.md](docs/DEVENV.md)

second, is to download projects, and build them, covered in [docs/BUILDING.md](docs/BUILDING.md)


note: the development enviroment stage is **identical** the one used for the percussa ssp sdk.


# Next Steps

This project does not contain any details relating how to code RNBO patches.
details and tutorials can be found here:

RNBO - https://cycling74.com/products/rnbo


# Do I need to buy Max/RNBO?

No, but its beneficial, if you wish to CREATE modules.

any module created with this project can be used by any SSP user **WITHOUT** MAX/RNBO.


# Max / RNBO Version
tested version :   Max 8.5.3 / RNBO v1.1.0 



# Advanced Info 

This projects works by using a 'template' of code that combines code necessary to build the module and the exported RNBO code.
It's important to realise that we **copy** this template when we use 'create_module', this means that this code can be fully customised.
(you can of course, keep exporting the RNBO patch, as this is not part of this template)
This is very powerful, as customised code can make assumptions about the RNBO patch, that a generic solution (this project) cannot.

In this way, we can use this project, to enable us to prototype a module, but later extend it to a 'polished' solution.


(I hope to add some details about how to do some common/easy customisations as a later date, assuming interest)


# Current Limitations 
(subject to change)
- no midi support
- in~/out~ are unnamed (RNBO limitation) 



# Can I develop/test modules with the SSP?

yes... but I dont support it ;) 

the environement we create above is a cross-compiling environent running on mac/linux.
we use CMake to supply the toolchain to do this (xcSSP.cmake)
however, if you use cmake and omit the toolchain (so simply `cmake ..`) , it will build natively.

this is why I build the SSP modules as 'wrapped' VST3, so that it can be loaded into Plugin host.
(hint: the JUCE audio plugin host is ideal)


Personally, I use (and recommend) JetBrains CLion for this type of development. It loads CMake file natively for projects, and is cross platform.
note: I do NOT use it for cross-compiling, I do this as described in the devenv/building docs, so as to ensure minimum dependancies for other users.

of course, any IDE that supports CMake could work.

IMPORTANT NOTE: as stated above, I do not support this workflow, how to set it up, use CLion or plugins running on anything other than the SSP.
(sorry, I just don't have the time)


# Licencing 
This project is covered by GPL.

ALSO, users should be are aware of other licencing implications, as this is THIER responsiblity.

JUCE - the template uses JUCE, which you may use FREE as an **OPEN SOURCE** project, commercial projects need a licence
RNBO - Cycling 74 have a licence for code exported using RNBO.
Steinberg VST3 SDK - check licence when you download

I will not give specifics here, as companies can change license details, it is your responsibly to check.


# Other Resources


Percussa SSP - https://percussa.com

VST3 SDK - https://www.steinberg.net/developers/

Percussa SSP SDK - https://sw13072022.s3.us-west-1.amazonaws.com/arm-rockchip-linux-gnueabihf_sdk-buildroot.tar.gz

