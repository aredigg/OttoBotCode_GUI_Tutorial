## Episode 2 – Creating a Window

https://youtu.be/cQalRGqRRp4

We use the same structure as in the previous episode

```
> mkdir Episode\ 1/
> cd Episode\ 1/
> mkdir FirstGUI
> cd FirstGUI
```

Create the MainFrame class files

```
> nano MainFrame.h
> nano MainFrame.cpp
```

and the App class for the entry-point

```
> nano App.h
> nano App.cpp
```

To build it you could use
```
> c++ -std=c++11 *.cpp -o FirstGUI `wx-config --cxxflags --libs`
```

and use the same command to run it
```
> ./FirstGUI
```
