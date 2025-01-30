# Push Swap

A terrible sorting algorithm, because, you can't stop me Tynen, I am, TOO POWERFUL.

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
