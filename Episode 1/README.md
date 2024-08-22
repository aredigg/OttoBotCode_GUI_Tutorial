## Episode 1 – Installing wxWidgets

https://youtu.be/ONYW3hBbk-8

Create some files as in the video

```
> mkdir Episode\ 1/
> cd Episode\ 1/
> mkdir FirstGUI
> cd FirstGUI
> nano Main.cpp
```

Insert code from the video description and compile it in the terminal like this

```
> c++ Main.cpp -o FirstGUI `wx-config --cxxflags --libs`
```

Then you can run it by typing

```
> ./FirstGUI
```
