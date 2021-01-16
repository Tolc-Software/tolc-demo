# Tolc demo - Using `C++` from other languages #

![Ubuntu](https://github.com/Tolc-Software/tolc-demo/workflows/Ubuntu/badge.svg) ![MacOS](https://github.com/Tolc-Software/tolc-demo/workflows/MacOS/badge.svg)

`tolc` is a project aiming to making it effortless to use `C++` from other languages. This demo is meant to show how easy it is to get going and start using existing `C++` libraries from for example `python` with the help of `tolc`.

`tolc` itself is a simple executable that takes one file (typically a `C++` header), and spits out binding code that can be built to provide a bridge from the input to some other language. This demo uses the open beta version of `tolc` and shows the available `CMake` wrappers to translate a library to be used from `python`.

## Usage ##

### Prerequisites ###

You need the following installed locally:

* `CMake` - Tested with `>3.11`.
* `python` - The language to translate to.

### Building and importing ###

Fork and download this repository.

Go to the root of the project and generate the build files;

```shell
# The python part is only strictly needed on MacOS
$ cmake -S. -Bbuild -DPYTHON_EXECUTABLE=$(which python3)
```

This will automatically download `tolc`, and anything needed to build the library for use in `python` (in this case, [the `pybind11` project](https://github.com/pybind/pybind11)).

Build the library;

```shell
$ cmake --build build
```

You should now be able to start using the `C++` library `Math` from `python`;

```shell
$ cd build
$ python3
>>> import Math
>>> Math.Demo.merge({"tolc": 0}, {"demo": 1})
{'demo': 1, 'tolc': 0}
```

It's that easy!

## Contributing ##

As of writing this `tolc` is in *beta*. This demo is meant to try to find the biggest bugs aswell as gather information about what is most important to users. The best way to help the project is to use the beta and report any issue you find, nothing is too small!
