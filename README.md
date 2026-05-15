# Cryo Zip

A little huffman enconder/decoder

## Building the project

To compile the encoder/decoder:

```
make
```

Then execute the project:

```
./cryo-zip
```

## Running the Project

To run the program with the default test file:

```
make run
```

Equivalent to:

```
./cryo-zip example-data/test.txt
```

## Debug Build

To compile with debug symbols enabled:

```
make debug
```

This enables:

- debug symbols (-g)
- debug macro (-DDEBUG)

Useful for tools like:

- gdb
- valgrind

## Cleaning Build Files

To remove generated object files and binaries:

```
make clean
```

## Rebuilding the Project

To clean and rebuild everything:

```
make rebuild
```

## Compiler Flags

The project is compiled with:

```
-Wall -Wextra -O2 -std=c11
```

**Meaning:**

- -Wall → enable common warnings
- -Wextra → enable additional warnings
- -O2 → optimization level 2
- -std=c11 → use the C11 standard
