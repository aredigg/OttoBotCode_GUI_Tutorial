# OttoBotCode Tutorial: C++ GUI Programming for Beginners

## The tutorial

I wanted to learn using a GUI library when making simple programs in C++ on my Mac. I found these videos on YouTube which was simple, descriptive and easy to follow. But they were for Windows and Visual Code, so I had to adapt a bit. Here are the notes I have made, maybe it will be helpful for others.

## How to install wxWidgets on macOS

Download it from https://wxwidgets.org/downloads/ choose "Source Code" and "Source for Linux, macOS, etc" and unpack it somewhere usful. If you use Safari it will most likely be downloaded to the "Downloads" folder for your current logged on user. So then open terminal and go there.

```
> cd
> cd Downloads
```
If you did not unpack it already you can use the following command (you may have to change it to the filename that was downloaded)
```
> tar xf wxWidgets-3.2.5.tar.bz2
```
then build it
```
> cd wxWidgets-3.2.5
> mkdir build-macos
> cd build-macos
> ../configure --disable-shared --disable-pnm --disable-pcx --disable-gif --disable-iff --disable-debug_flag --disable-sys-libs --enable-universal_binary=arm64,x86_64
> sudo make install
```

This makes a static release version of the library and installs the source files into `/usr/local/include` and makes it as easy as possible to follow the videos. It should not require any extra software installed except Xcode. And the compiled binaries will link it statically so it should work on other Macs as is. While the video builds both a debug and 32 bit version, I chose not to do so here. 32 bit version is not supported anymore on macOS, but if you want a debug version change `--disable-debug_flag` to `--enable-debug` on the above configure line.

## Other hints

It may be useful to make a symbolic link for the wx include files, as they are installed in a wx-version subfolder, so for some text editors and LSP to find the correct files, you can add it like this
```
sudo ln -s /usr/local/include/wx-3.2/wx /usr/local/include/wx
```

I have used `nano` as the text editor in the notes, but any code editor is of course fine.

## Episodes

* [Episode 1](Episode%201)
* [Episode 2](Episode%202)
* [Episode 3](Episode%203)
* [Episode 4](Episode%204)

