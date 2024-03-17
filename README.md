# uSh

uSh (Micro Shell), is a small interpreter with a syntax similar to Tcl/Tk. Is
written in pure ANSI C and can be easily extended. I wrote this program to
improve my skills programming in C.

## Changelog.

- 2018 - Wrote the program.
- 2024 - Cleanup and published.

## Features

uSh has a very simple syntax. You can check it's syntax reading the
example files here [test1](./ush_test.ush).

- It supports flow control; `if,else,elif,while,foreach,for`
- Basic arithmetic;         +,-,...
- Custom functions;         `proc,exec`
- Variables;                `set`

### Building

Build as any other `cmake` project.

### Running

```
> ushc
> ushc <filename>
```

## Authors

* Harkaitz Agirre Ezama.

## License

Read [LICENSE](LICENSE) file for details

