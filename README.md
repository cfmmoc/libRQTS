# ![libRQTS LOGO](https://github.com/cfmmoc/libRQTS/blob/master/libRQTS.png) is an implementation of Restricted QuadTreeS

Licensed under The GNU General Public License v3.0 (GPLv3)

Any modification, re-utilization or copy of the source or binary format in other software or publications should mention a CITATION of this library.

Copyright (c) 2016-2018 by Authors (Jin Yan, Guanghong Gong, Ni Li and Luhao Xiao)

## Overview

libRQTS implements an algorithm of Restricted QuadTreeS for cfMMOC (https://github.com/cfmmoc/cfmmoc) terrain rendering library.

cfMMOC library is a planet-scale out-of-core terrain rendering framework on top of OGRE v1.9.

Letters R, Q, T, and S in libRQTS logo also mirror the names of four sibling quads, Q, R, S, and T.

| Build | Status |
|-------|--------|
| Fedora 27 64-bit | ![Building Pass](https://github.com/cfmmoc/cfmmoc-mics/blob/master/build-passing.png) |
| Ubuntu 17.10 64-bit | ![Building Pass](https://github.com/cfmmoc/cfmmoc-mics/blob/master/build-passing.png) |

## Dependencies

The dependency for libRQTS is GNU C Library (I/O stream, shared memory, container such as vector and map, string. etc). 

## Compilation

On Fedora, first install building tool by using `yum insatll gcc-c++`. On Ubuntu, first run `apt install make g++`.

Then run `make all`, and manually copy `libRQTS.so` to `bin/` directory of cfMMOC (https://github.com/cfmmoc/cfmmoc) project.
