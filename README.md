# OttoBotCode Tutorial: C++ GUI Programming for Beginners

## How to install wxWidgets on macOS

```
> cd wxWidgets-3.2.5
> mkdir build-macos
> cd build-macos
> ../configure --disable-shared --disable-pnm --disable-pcx --disable-gif --disable-iff --disable-debug_flag --disable-sys-libs --enable-universal_binary=arm64,x86_64
> sudo make install
```
