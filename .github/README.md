# EngineToolkit - Toolkit for Game Engines

## About

> [!IMPORTANT]
> This project is **still under development**, and is not ready *just yet*

This library is a core platform for Game Engines

It is designed to contain every essential tool that a Game Engine would require

It aims to replace libraries, like:
- [GLM](https://glm.g-truc.net/0.9.9) (mathematics)
- [GLFW](https://www.glfw.org) (windowing)
- [STB libraries](https://github.com/nothings/stb) (asset loading)
- [Assimp](https://assimp.org) (asset loading)

### Features

* - [ ] [Debug](../include/EngineToolkit/debug)
  * - [x] [Log](../include/EngineToolkit/debug/log.hpp)
  * - [ ] Profiler
* - [ ] [Math](../include/EngineToolkit/math)
  * - [x] [Vectors](../include/EngineToolkit/math/vector)
  * - [x] [Matrices](../include/EngineToolkit/math/matrix)
  * - [x] [Quaternions](../include/EngineToolkit/math/quaternion)
  * - [ ] [Noise Generator](../include/EngineToolkit/math/noise)
  * - [ ] [Random Number Generator](../include/EngineToolkit/math/random)
  * - [ ] Collision Detection
* - [ ] [Media](../include/EngineToolkit/media)
  * - [ ] [Image](../include/EngineToolkit/media/image.hpp)
  * - [ ] [Audio](../include/EngineToolkit/media/audio.hpp)
  * - [ ] [Video](../include/EngineToolkit/media/video.hpp)
  * - [ ] Font
  * - [ ] Vector Image (?)
* - [ ] Scene
  * - [ ] Scene
  * - [ ] Transform
  * - [ ] Spacial Partitioning
  * - [ ] [Material](../include/EngineToolkit/model/material.hpp)
  * - [ ] [Model](../include/EngineToolkit/model/model.hpp)
* - [ ] [UI](../include/EngineToolkit/UI)
  * - [ ] [UI Builder](../include/EngineToolkit/UI/ui.hpp)
* - [ ] Misc
  * - [ ] Scripting Engine
  * - [ ] Clock

## Documentation

### Usage

Namespaces
| Namespace       | Description            |
| --------------- | ---------------------- |
| `EngineToolkit` | Main Project Namespace |

Types
| Type Name               | Description                                 |
| ----------------------- | ------------------------------------------- |
| `vec2`, `vec3` & `vec4` | Fast (`float`) Vectors                      |
| `mat3` & `mat4`         | Fast (`float`) Matrices                     |
| `vec` & `mat`           | Vector & Matrix Templates                   |
| `quat`                  | Quaternions                                 |

## License

This project is licensed under the [Apache 2.0 License](LICENSE) - see the [LICENSE](LICENSE) file for details.