# fabrifs

Fast and Brilliant File System creator utility

## Overview

`fabrifs` is a lightweight command-line utility designed to quickly create files and directories with a simple and intuitive syntax.

## Features

- Create files with a simple command: `fabrifs filename`
- Create directories by adding a trailing slash: `fabrifs dirname/`
- Create nested directory structures automatically
- Create files inside directories in one command: `fabrifs dir/file`

## Installation

### From Binary Releases

Download the appropriate binary for your system from the [Releases](https://github.com/yourusername/fabrifs/releases) page.

### Build from Source

#### Prerequisites

- CMake 3.16 or higher
- C++ compiler with C++17 support

#### Build Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/fabrifs.git
cd fabrifs

# Create a build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Install (optional)
sudo make install
```

## Usage

```
fabrifs [options] path
```

### Options

- `-h, --help`: Display help information
- `-v, --version`: Display version information

### Examples

```bash
# Create a file named 'new'
fabrifs new

# Create a directory named 'new'
fabrifs new/

# Create a file named 'file' inside directory 'new'
# (creates 'new' directory if it doesn't exist)
fabrifs new/file

# Create directory 'dir' inside directory 'new'
# (creates 'new' directory if it doesn't exist)
fabrifs new/dir/

# Create nested directories and a file
fabrifs path/to/my/new/file.txt
```

## Version Control

This project uses semantic versioning. Version numbers follow the pattern MAJOR.MINOR.PATCH:

- MAJOR: Incompatible API changes
- MINOR: New functionality in a backward compatible manner
- PATCH: Backward compatible bug fixes

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.