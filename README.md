# Coronet
An experimental grid-based 2D game framework made with SDL2.

This framework was made for a more specific project, but generalised to allow it to be reused.

## Requirements
* SDL2
* SDL2_image
* SDL2_ttf
* PhysicsFS

## Compiling
Tested under macOS 10.13.2.

`cd` to the root of the repository and do

```
cmake .
make
```

The library will output to `lib/`, and the `Tests` binary will be in `bin/`