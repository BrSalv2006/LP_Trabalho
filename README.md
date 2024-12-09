# LP_Trabalho #
**Table of contents**
- [Features](#features)
- [Requirements](#requirements)
- [Download](#download)
- [Compatibility](#compatibility)
- [How to Build](#how-to-build)
- [License](#license)

## Features ##
All of these features are currently implemented with a 20 element vector with elements between 8 and 29.
- Sort vector in ascending order;
- Sum of the first half of the elements in the vector with those in the second half;
- 20x20 matrix with the original vector and some of its permutations;
- Cosine of the second half of the elements in the vector;
- Random vector element;
- Elements in positions multiples of 3;
- Mix half of each vector;
- Least common multiple of every two followed numbers by the vector;
- 20x20 matrix of the product of a 1x20 random vector and the original vector;
- Transposed 20x20 matrix of the product of a 1x20 random vector and the original vector.

## Requirements ##
- Linux/UNIX based Operating System

## Compatibility ##
`LP_Trabalho` has only been tested on Ubuntu 24.04.1 LTS on WSL.

At this time there are no plans to support Windows or another operating system.

## Download ##
`LP_Trabalho` is available for [download in compiled form](https://github.com/BrSalv2006/LP_Trabalho/releases) ready to use in Linux or in [source code form](https://github.com/BrSalv2006/LP_Trabalho), which you can [build yourself](#how-to-build).

## How to Build ##
**Requirements**
  - [GCC](https://gcc.gnu.org/)
  - [MAKE](https://www.gnu.org/software/make/) (OPTIONAL)

**Build**
1. Clone the repository:
    ```bash
    git clone https://github.com/BrSalv2006/LP_Trabalho.git && cd LP_Trabalho
    ```
2. Build binaries:
  -  Option 1 (Make):
      ```bash
      make
      ```
  -  Option 2 (Manually):
      ```bash
      cc ./src/*.c -lm -o ./main.exe
      ```

## License ##
Licensed under the [EUPL](https://eupl.eu/1.2/en/).