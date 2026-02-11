# Linear Model Project

A small C++ project demonstrating a linear model implementation with
unit tests using Bazel, Eigen, and GoogleTest.\
The project is fully reproducible using a hermetic C++ toolchain and can
be built either locally or inside Docker.

##  Features

-   **Hermetic, reproducible build** using Bazel toolchains\
-   **Linear model implementation** in C++\
-   **Unit tests** using GoogleTest\
-   **Eigen** for numerical operations\
-   **Docker environment** for fully isolated builds\
-   **Clean build configuration** for both local and container workflows

##  1. Build and Test

###  Build & Test Inside Docker (Fully Reproducible)

#### Build the image

    docker build -t linear-model .

#### Run tests inside the container

    docker run --rm -it linear-model

###  Local Build (Using Bazelisk)

#### Build all targets

    bazel build //...

#### Run all tests

    bazel test //...

##  2. File Overview

###  `MODULE.bazel`

Defines Bazel dependencies and activates the hermetic C++ toolchain.

-   Declares module name and version\
-   Adds Eigen and GoogleTest\
-   Loads and registers the hermetic toolchain

###  `.bazelrc`

-   Linux-specific settings\
-   Sandbox/cache options for Docker\
-   Minimal flags for cleanliness

### `Dockerfile`

-   Ubuntu 24.04 base\
-   Installs build tools + Bazelisk\
-   Copies workspace\
-   Default command runs tests

###  `util/BUILD.bazel`

-   `cc_library` for linear model\
-   Depends on Eigen\
-   `cc_test` using GoogleTest

##  Running Tests

    bazel test //util:linear_model_test

