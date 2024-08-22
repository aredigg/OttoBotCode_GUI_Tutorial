## Episode 10 – To-Do List Application

https://youtu.be/MPLfOoRUKMU

Setup folders for episode and project

```
> mkdir Episode\ 10/
> cd Episode\ 10/
> mkdir ToDoList
> cd ToDoList
```

Create files for the class
```
> nano Task.h
> nano Task.cpp
> nano MainFrame.h
> nano MainFrame.cpp
> nano App.h
> nano App.cpp
```

To build you could use
```
> c++ -std=c++17 *.cpp -o ToDoList `wx-config --cxxflags --libs`
```

* To better fit macOS with Retina displays, I have changed some of the positions and sizes