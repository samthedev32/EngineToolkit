# EngineToolkit - Toolkit for Game Engines

## About

> [!IMPORTANT]
> This project is **still under development**, and is not ready just yet

This library is a core platform for Game Engines

It is designed to contain every essential tool that a Game Engine would require

It aims to replace libraries, like:
- [GLM](https://glm.g-truc.net/0.9.9/) (mathematics)
- [GLFW](https://www.glfw.org/) (windowing)
- [STB libraries](https://github.com/nothings/stb/) (asset loading)
- [Assimp](https://assimp.org/) (asset loading)
- [ImGui](https://www.dearimgui.com/) (GUI rendering, sort-of)

### Features

* - [ ] Debug
  * - [x] [Logger](../include/EngineToolkit/debug/log.hpp)
  * - [ ] Profiler
* - [ ] Math
  * - [x] [Vectors](../include/EngineToolkit/math/vector)
  * - [x] [Matrices](../include/EngineToolkit/math/matrix)
  * - [ ] [Quaternions](../include/EngineToolkit/math/quaternion.hpp)
  * - [ ] Perlin Noise
  * - [ ] Random Number
  * - [ ] Collision Detection
* - [ ] Media I/O
  * - [ ] [Image](../include/EngineToolkit/media/image.hpp)
  * - [ ] [Audio](../include/EngineToolkit/media/audio.hpp)
  * - [ ] [Video](../include/EngineToolkit/media/video.hpp)
  * - [ ] Font
  * - [ ] Vector Image
* - [ ] Model I/O
  * - [ ] [Material](../include/EngineToolkit/model/material.hpp)
  * - [ ] [Model](../include/EngineToolkit/model/model.hpp)

* - [ ] [UI Builder](../include/EngineToolkit/UI/ui.hpp)
* - [ ] Scripting Engine

> [!NOTE]
> and a lot more!

## Documentation

### Setup

<details>
<summary>Linux (Debian Based)</summary>

> TODO

</details>

<details>
<summary>Linux (Arch Based)</summary>

> TODO

</details>

<details>
<summary>Windows</summary>

> TODO

</details>

### Usage

| Namespace       | Description            |
| --------------- | ---------------------- |
| `EngineToolkit` | Main Project Namespace |

| Type Name               | Description                                 |
| ----------------------- | ------------------------------------------- |
| `vec2`, `vec3` & `vec4` | Fast (`float`) Vectors     (recommended)    |
| `mat3` & `mat4`         | Fast (`float`) Matrices    (recommended)    |
| `vec`                   | Slower, more convenient & flexible Vectors  |
| `mat`                   | Slower, more convenient & flexible Matrices |
| `vec`                   | Slower, more convenient & flexible Vectors  |
| `Quaternion`            | Quaternions                                 |

## License

This project is licensed under the [Apache 2.0 License](LICENSE) - see the [LICENSE](LICENSE) file for details.