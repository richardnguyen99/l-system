# Lindenmayer System Rewriting Project

A simple L-system rewriting application written in Qt and C++.

_(More: <https://en.wikipedia.org/wiki/L-system>)_

## Prerequisites

- Qt Framework (`>= 6.4.0`)
- CMake (`>= 3.16`)
- C++ (`>= stdc++17`)

## Build

### 1. Build from Qt Creator (Recommended)

The easiest way to build the project is to import it in Qt Creator, then simply build it.

### 2. Build from terminal 

Before building from terminal, you might need to know where your Qt installation is located. 

```sh
# after cd l-system

cmake -DCMAKE_PREFIX_PATH=<QT_LOCATION> -S . -B build 

cd build

make
```

For example:

```sh
cmake -DCMAKE_PREFIX_PATH=~/Applications/Qt/6.5.2/gcc_64/ -S . -B build

cd build

make
```

After building, simply run 

```sh
./lsystem
```

## LICENSE

(To be updated)
