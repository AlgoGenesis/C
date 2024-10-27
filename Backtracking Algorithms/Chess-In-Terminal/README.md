# Chess In Terminal

Chess in the terminal, written in C99.


The project is only capable of player vs. player play in the same terminal; though there are future plans for human vs. computer support.

## Build

The only dependency is `ncurses`. To build the package with GCC 12.2.1, execute the following:

```bash
make clean && make
```
## Contributing
The dependencies are `clang-format`, `clang-tidy`, and `include-what-you-use`. To install the pre-commit hooks, execute the following:
```bash
pre-commit install
```
