# Data Processor

A C++20 toolkit for loading, processing, and writing subtitle and data files.
The project contains a data frame library (`libdf`) and an SRT subtitle
processing library (`libsrt`).

## Build

```powershell
cmake -S . -B build
cmake --build build
```

The test program expects a path to an input SRT file:

```powershell
./build/test_srt.exe ./data/notld.srt
```

The output files `native.srt` and `json.json` are generated in the current
working directory and are not project input files.
