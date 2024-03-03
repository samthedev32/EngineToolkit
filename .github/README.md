# EngineToolkit - Toolkit for Game Engines

## About

> [!IMPORTANT]
> This library is **still under development**, and is not ready *just yet*

> [!NOTE]
> This library may be transformed into a github organization with every component as a standalone repo

This library is a core platform for Game Engines

It is designed to contain every essential tool that a Game Engine needs

It aims to replace libraries, like:
- [GLM](https://glm.g-truc.net/0.9.9) (mathematics)
- [GLFW](https://www.glfw.org) (windowing)
- [STB libraries](https://github.com/nothings/stb) (asset loading)
- [Assimp](https://assimp.org) (asset loading)
- [Dear ImGui](https://www.dearimgui.com) (UI Building / Rendering(sortof))

> [!NOTE]
> In the [ideas.txt](ideas.txt) file, you can find some concepts in mind for different parts of the library
> They may be dumb, but also you may find some good ideas there; you are free to use any of them!

### Features

* - [ ] [Debug](../include/EngineToolkit/debug)
  * - [x] [Log](../include/EngineToolkit/debug/log.hpp)
  * - [ ] Profiler
* - [ ] [Math](../include/EngineToolkit/math)
  * - [x] [Vectors](../include/EngineToolkit/math/vec.hpp)
  * - [x] [Matrices](../include/EngineToolkit/math/mat.hpp)
  * - [-] [Quaternions](../include/EngineToolkit/math/quat.hpp)
  * - [ ] [Noise Generator](../include/EngineToolkit/math/noise)
  * - [ ] [Random Number Generator](../include/EngineToolkit/math/random)
  * - [ ] Physics
    * - [ ] Collision Detection
* - [ ] [Media](../include/EngineToolkit/media)
  * - [ ] [Image](../include/EngineToolkit/media/image.hpp)
  * - [ ] Audio
  * - [ ] Video (?)
  * - [ ] Font

  * - [ ] Image Stream (?)
  * - [ ] Audio Stream
  * - [ ] Video Stream
* - [ ] Scene
  * - [ ] Scene
  * - [ ] Transform
  * - [ ] Spacial Partitioning
  * - [ ] Entity Component System
  * - [ ] [Material](../include/EngineToolkit/model/material.hpp)
  * - [ ] [Model](../include/EngineToolkit/model/model.hpp)
* - [ ] Misc
  * - [ ] [Window](../include/EngineToolkit/window/window.hpp)
  * - [ ] Scripting Engine
  * - [ ] Clock / Timer
  * - [ ] [UI Builder](../include/EngineToolkit/UI)

<!-- TODO: README-s in feature folders, added into `.gitignore` -->

## Documentation

### Usage

Project-Level namespace: `EngineToolkit`

Sub-Namespaces
| Namespace       | Description            |
| --------------- | ---------------------- |
| `UI`            | UI Builder             |

<!-- TODO: more namespaces -->

Types
| Type Name               | Description                                 |
| ----------------------- | ------------------------------------------- |
| `vec`, `mat` & `quat`   | Vectors, Matrices & Quaternions             |

<!-- TODO: more types -->

## License

This library is licensed under the [Apache 2.0 License](LICENSE) - see the [LICENSE](LICENSE) file for details.
