# Tolc demo #

This is a demo over how to use [`Tolc`](https://github.com/Tolc-Software/tolc) the bindings compiler. It will make it trivial to use your `C++` from other languages.

This repo contains the project `MyCppLib` that exposes just a simple function `Hello::cppFunction` that we want to use from both `python` and `javascript`.

In the [`CMakeLists.txt`](./CMakeLists.txt) we download the `latest` version of `Tolc` and uses the `tolc_create_bindings` function provided by the `Tolc` package. When the bindings are built (for `python` a `CPython` library, and for `javascript` a `WebAssembly` module), they are copied to the [`./python`](./python) directory or to the [`./wasm`](./wasm) directory. In order to know what to copy we pass `-Dlanguage=python` or `-Dlanguage=wasm` at configure time.

### Prerequisites ###

You need the following installed locally:

* `CMake` (version `>=3.15`)
* `python3` - To run the `python` (on Debian/Ubuntu you also need `python3-dev` from `apt`)
* `node` - To run the `WebAssembly`

### Building and using ###

We'll start by downloading and configuring [`Emscripten`](https://emscripten.org/). Their `SDK` is stored as a submodule in this repository so all we have to do is:

```shell
$ git submodule update --init
$ cd emsdk
# Download Emscripten to emsdk/upstream
$ ./emsdk install 3.1.3
# Write the .emscripten config file
$ ./emsdk activate 3.1.3
```

Note that for `Windows` you switch out `./emsdk` for `emsdk.bat`. Now we can build the actual project.

Generate build files (this will also download `Tolc` to the build directory)

```shell
# For python
$ cmake -S. -Bbuild-py -Dlanguage=python
# For WebAssembly
$ cmake -S. -Bbuild-wasm -Dlanguage=wasm -DCMAKE_TOOLCHAIN_FILE=emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
```

Note that the `/` is used as a directory separator even on `Windows`.

Build the library:

```shell
# For python
$ cmake --build build-py
# For WebAssembly
$ cmake --build build-wasm
```

Since this copies the built artifacts to `./python` or `./wasm` we can now run

```shell
# For python
$ python3 python/main.py
# For WebAssembly
$ node wasm/main.js
```

Now whenever you change any of the headers in the include directory and rebuild,
the new functions and classes will be available from both `python` and `javascript`.

You can read more over at the [documentation for `Tolc`](https://docs.tolc.io/).
