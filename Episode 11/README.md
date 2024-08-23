## Episode 11 – Adaptive Layouts

https://youtu.be/ZdsQWQSZWXQ

Create an empty app for the tutorial

```
mkdir Episode\ 11/
cd Episode\ 11/
mkdir TutorialApp
cd TutorialApp

```

Create the basic classes
```
nano App.h
nano App.cpp
nano MainFrame.h
nano MainFrame.cpp
```

Copy the empty app
```
cp -a ../TutorialApp ../ManualLayout
cd ../ManualLayout
```

Edit and then build
```
c++ -std=c++11 *.cpp -o TutorialApp `wx-config --cxxflags --libs`
```
