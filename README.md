# Tolc demo #

This is a demo over how to use [`Tolc`](https://github.com/Tolc-Software/tolc) the bindings compiler. The goal is to make it trivial to use `C++` from other languages.

This repo contains the project `MyCppLib` that exposes just a simple function `Hello::cppFunction` that we want to use from both `python`, `Objective-C` and `javascript`.

In the [`CMakeLists.txt`](./CMakeLists.txt) we download the `latest` version of `Tolc` and uses the `tolc_create_bindings` function provided by the `Tolc` package. When the bindings are built, the deliverables are copied to the corresponding directory ([`./python`](./python), [`./objc`](./objc), and [`./wasm`](./wasm)). In order to know what to copy we pass `-Dlanguage=python` at configure time.

## Prerequisites ##

You need the following installed locally:

* `CMake` (version `>=3.15`)
* `python3`
* For `python` bindings:
  * `python` headers (`python3-dev` on Debian/Ubuntu, usually included elsewhere)
* For `WebAssembly` bindings:
  * `node` - To run the `WebAssembly` example
* For `Objective-C` bindings:
  * `MacOS` - Depends on the `Foundation` library provided by `MacOS`


## Building and using ##

### Python ###

Configure the build files:

```shell
$ cmake -S. -Bbuild-py -Dlanguage=python
```

Build the module:

```shell
$ cmake --build build-py
```

Since this copies the built artifacts (e.g. `MyCppLib.cpython-39-darwin.so`) to `./python` we can now run:

```shell
$ python3 python/main.py
```

### Objective-C ###

Note that this only works on `MacOS`.

Configure the build files:

```shell
$ cmake -S. -Bbuild-objc -Dlanguage=objc
```

Build the module:

```shell
$ cmake --build build-objc
```

You can now find the built `Objective-C` library with the corresponding header in the `objc` directory.

Run the example code ([`./objc/main.m`](./objc/main.m):

```shell
$ ./build-objc/main
```

## WebAssembly ##

We'll start by downloading and configuring [`Emscripten`](https://emscripten.org/). Their `SDK` is stored as a submodule in this repository so all we have to do is:

```shell
$ git submodule update --init
$ cd emsdk
# Download Emscripten to emsdk/upstream
$ ./emsdk install 3.1.3
# Write the .emscripten config file
$ ./emsdk activate 3.1.3
```

Or any later version of `emsdk`.

Note that for `Windows` you switch out `./emsdk` for `emsdk.bat`. Now we can build the actual project.


Configure the build files:

```shell
$ cmake -S. -Bbuild-wasm -Dlanguage=wasm -DCMAKE_TOOLCHAIN_FILE=emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
```

Note that the `/` is used as a directory separator even on `Windows`.

Build the module:

```shell
$ cmake --build build-wasm
$ node wasm/main.js
```

Since this copies the built artifacts (`MyCppLib.js` and `MyCppLib.wasm`) to `./wasm` we can now run:

```shell
$ node wasm/main.js
```

You can read more over at the [documentation for `Tolc`](https://docs.tolc.io/).
