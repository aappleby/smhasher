
## Build instructions

_Tested on Ubuntu 20.04._

Install dependencies:
```bash
sudo apt update && sudo apt install cmake
```

Build with `cmake`:
```bash
cd build
cmake ../src     # run cmake to make the makefile
make             # run make to build the executable
time ./SMHasher  # run the executable, timing how long it takes
```

