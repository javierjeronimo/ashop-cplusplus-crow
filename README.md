# Exercise - A shop API implemented in C++ & Crow

This is just an exercise to implement a simple shop API in C++14 with Crow REST framework.

This is incomplete, and it will remain incomplete...
See blog post (Spanish, sorry): [Entorno de desarrollo C++: CLion, CMake, Clang, Conan.io y TDD con Catch, FakeIt](http://javierjeronimo.es/2016/11/28/entorno-de-desarrollo-c-clion-cmake-clang-conan-io-y-tdd-con-catch-fakeit/)

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

## TODO:
 - Run tests from CMake
 - Swagger documentation VS Crow... not possible automatically :-(
 - More endpoints... nope! This is just a concept test: CMake, Clang, CLion, conan.io, Catch, FakeIt
 - Run a better performance analysis:
 ```bash
 $ ab -n 1000000 -c 1000 -s 1 http://localhost:18080/baskets/4ae4d4ac-dce5-46bd-8476-5727566cf376
 This is ApacheBench, Version 2.3 <$Revision: 1748469 $>
 Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
 Licensed to The Apache Software Foundation, http://www.apache.org/
 
 Benchmarking localhost (be patient)
 apr_socket_recv: Connection reset by peer (54)
 Total of 9494 requests completed
 ```