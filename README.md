# Benchmarking Zig's SMP Allocator

## Building zig project

```sh
zig build --release=fast
```

## Changes needed in bench.sh

- Change path to shared library on line which mentions `alloc_lib_add "zsmp"`

## Setup build-bench-env.sh

```sh
./build-bench-env.sh
```

## Running benchmarks

```sh
../../bench.sh alla allt
```
