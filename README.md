# <p align="center"> **_Doppler Effect Simulator._** </p>

### Overview.
This projects serves as a practice for C's [raylib](https://www.raylib.com/) and using [CMake](https://cmake.org/documentation/).

### My setup.
1. NixOS 25.06.
2. Neovim v0.12.3 (via Nixvim).
2. [Nix Shell via `flake.nix`.](./flake.nix)

### Compile using `gcc`.
```
gcc -Wall -Wextra -o doppler doppler.c -lraylib
```

> alternatively, using `CMake`,
>
>
>

### To do.

- [x] tidy up code.
- [x] revisit variable/struct naming.
- [x] try out different appearance for drawing (ember-theme based).
- [ ] `cmake` instead of `gcc`.
