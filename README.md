# Push Swap

A terrible sorting algorithm, because, you can't stop me Tynen, I am, TOO POWERFUL.

## Usage

### Compilation

To use this project, you must first compile it using the `make` command, it should automatically
clone the library `ft` from its [radicle repo](https://app.radicle.xyz/nodes/seed.radicle.garden/rad:z4xiekV66Dw3AhVVnp7c93hC5aD6).

The library is then downgraded to ensure the correct version of ft is used for this project at time of correction,
through the usage of the `git checkout` command, with the current version used being the `de93b67` commit visible
in the [Garden](https://app.radicle.xyz/nodes/seed.radicle.garden/rad:z4xiekV66Dw3AhVVnp7c93hC5aD6/commits/de93b679bd3ad136e195652376a1e714cff6bc55)
or on [GitHub](https://github.com/cliftontoaster-reid/libft/commit/de93b679bd3ad136e195652376a1e714cff6bc55).

More information on the `checkout` command is available [here](https://git-scm.com/docs/git-checkout).

### How to use

To use this project, you must have run in a terminal the produced `push_swap` executable,
if it does not appear in the root directory, please run `make` a single more time just in case.

The command can be used in one of these ways.

```text
push_swap [ARG="numbers"]

push_swap "numbers"

push_swap number [number ...]
```

Please note that the numbers can only contain numerical characters (but you have a bigger brain than mine so you already know),
and must contain no same numbers, please note that the numbers are not case-sensitive and 02 will be considered equal to 2.

If you have followed the instructions properly, the program will either return nothing, meaning the list of numbers you have provided
is already sorted from small to big, or return a string similar to this one.

```txt
ra
sa
```

This example being returned when used with the following list of numbers $[5, 4, 3]$.
Though any list longer than 3 elements will suffer from a much larger response.

To learn more please read the subject available at [School 42's website](https://cdn.intra.42.fr/pdf/pdf/143086/en.subject.pdf).

## Dependencies

This project requires the following programs to be installed in your machine

- Clang
- Make

It is also possible to use the following linkers, as the Makefile will choose the linker in this order.

- Mold
- LLVM LLD

You can install these tools using the command based on your operating system

### Debian / Ubuntu

Required packages

```bash
  sudo apt-get install clang make
```

Optional packages

```bash
  sudo apt-get install lld
  sudo apt-get install mold
```

### Fedora

Required packages

```bash
  sudo dnf install clang make
```

Optional packages

```bash
  sudo dnf install lld
  sudo dnf install mold
```

### Arch Linux

Required packages

```bash
  sudo pacman -S clang make
```

Optional packages

```bash
  sudo pacman -S lld
  sudo pacman -S mold
```

### MacOS

Required packages

```bash
  brew install clang make
```

Optional packages

```bash
  brew install lld
  brew install mold
```

### Windows

#### MinGW

Required packages

```bash
  pacman -S mingw-w64-x86_64-clang mingw-w64-x86_64-make
```

Optional packages

```bash
  pacman -S mingw-w64-x86_64-lld
  pacman -S mingw-w64-x86_64-mold
```

#### MSVC

Required packages

```bash
  choco install llvm make
```

Optional packages

```bash
  choco install lld
  choco install mold
```

## Run Locally

Clone the project

```bash
  git clone https://link-to-project
```

Go to the project directory

```bash
  cd my-project
```

Build the project

```bash
  make
```

Use the project

```bash
  ./push_swap [numbers go here]
```

## Running Tests

To run tests, run the following command

```bash
  make test
```

## Licence

[MIT](https://choosealicense.com/licenses/mit/)
