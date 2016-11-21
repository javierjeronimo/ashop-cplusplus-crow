# Exercise - A shop API implemented in C++ & Crow

This is just an exercise to implement a simple shop API in C++14 with Crow REST framework.

## Install & compile
Install requirements (mainly conan.io) and compile with CMake:
```bash
brew install cmake conan

git clone https://github.com/javierjeronimo/ashop-cplusplus-crow.git

cd ashop-cplusplus-crow

mkdir build && cd build
conan install ..

# Better use CLion... but from console it works too :P
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .

```
