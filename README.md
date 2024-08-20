# OttoBotCode Tutorial: C++ GUI Programming for Beginners

## The tutorial

I wanted to learn using a GUI library when making simple programs in C++ on my Mac. I found these videos on YouTube which was simple, descriptive and easy to follow. But they were for Windows and Visual Code, so I had to adapt a bit. Here are the notes I have made, maybe it will be helpful for others.

## How to install wxWidgets on macOS

```
> cd wxWidgets-3.2.5
> mkdir build-macos
> cd build-macos
> ../configure --disable-shared --disable-pnm --disable-pcx --disable-gif --disable-iff --disable-debug_flag --disable-sys-libs --enable-universal_binary=arm64,x86_64
> sudo make install
```

This makes a static release version of the library and installs the source files into `/usr/local/include` and makes it as easy as possible to follow the videos. It should not require any extra software installed except Xcode. And the compiled binaries will link it statically so it should work on other Macs as is.

## Episodes

* [Episode 1](Episode 1)

