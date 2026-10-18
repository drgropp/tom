# tom

A small `cat` clone written in C, named after my cat Tom.

`tom` reads a file and prints its contents to the terminal. The goal of making it fast and efficient.

## Building

You need a C compiler (gcc or clang). No libraries are required beyond the C standard library.

### Windows

Install [w64devkit](https://github.com/skeeto/w64devkit), open `w64devkit.exe`, then:

```
git clone https://github.com/drgropp/tom.git
cd tom
gcc -std=c17 -Wall -Wextra tom.c -o tom.exe
```

### Linux / macOS

```
git clone https://github.com/drgropp/tom.git
cd tom
gcc -std=c17 -Wall -Wextra tom.c -o tom
```

(Use `clang` in place of `gcc` if you prefer.)

## Usage

```
tom <file>
```

Example:

```
./tom.exe tom.c
```

This prints `tom.c`'s own source code.

| Situation | Output | Exit code |
|---|---|---|
| File printed successfully | The file's contents | 0 |
| No file given | `usage: tom <file>` | 1 |
| File can't be opened | `tom: cannot open <file>` | 1 |

Error messages go to stderr, so they won't end up in a file if you redirect output (`./tom.exe notes.txt > copy.txt`).

## How it works

`tom` opens the file with `fopen`, reads it one character at a time with `fgetc`, and writes each character with `putchar` until it reaches `EOF`, then closes the file.

The character variable is an `int`, not a `char`, because `fgetc` can return any of the 256 byte values *plus* `EOF`, and a `char` can't hold all 257.

## License

MIT. See [LICENSE](LICENSE).
