# SDL3 3D Game Template — OpenGL and Vulkan

**English** | [Español](README.es.md)

An educational C++23 template for starting 3D game projects with SDL3 and CMake.

> [!IMPORTANT]
> This project is under development and is not yet a buildable game template.
> The first usable version will be reached when the SDL3 phase is complete.

## Table of contents

- [Overview](#overview)
- [Current status](#current-status)
- [Goal](#goal)
- [Initial platform](#initial-platform)
- [Roadmap](#roadmap)
- [Dependency management](#dependency-management)
- [Using the template](#using-the-template)
- [Security](#security)
- [License](#license)

## Overview

This repository will provide a small, understandable, and reusable foundation for creating 3D games. It is intended both as a learning project and as the starting point for future games.

This project is a starter template, not a complete game engine.

## Current status

The repository currently contains documentation only. The build system, SDL3 integration, and example application have not been implemented yet.

Although GitHub already shows the **Use this template** button, the generated repository will not become useful for game development until Phase 1 is complete.

## Goal

The template will initially provide:

- An organized project structure.
- CMake-based configuration and builds.
- C++23 as the required language standard.
- A window and main loop implemented with SDL3.
- Basic event handling and a clean shutdown path.
- A foundation prepared for 3D rendering backends.

## Initial platform

The first supported development platform will be:

- Windows x64.
- MSVC with C++23 support.
- CMake as the configuration and build system.
- Visual Studio Code as the recommended editor.

Ninja will not be required initially. CMake can use the Visual Studio generator already provided by the MSVC toolchain.

Support for macOS, Android, and iOS may be evaluated later. These platforms are not currently supported or guaranteed.

## Roadmap

### Phase 1 — SDL3

- [ ] Create the initial project structure.
- [ ] Configure CMake and enforce C++23.
- [ ] Download a pinned SDL3 release securely.
- [ ] Create a window with SDL3.
- [ ] Implement the main loop and event handling.
- [ ] Implement clean application shutdown.
- [ ] Verify compilation and execution on Windows x64 from a clean checkout.

### Phase 2 — OpenGL

- [ ] Create an OpenGL context through SDL3.
- [ ] Initialize the required OpenGL functionality.
- [ ] Render a basic 3D scene.

### Phase 3 — Vulkan

- [ ] Detect Vulkan availability.
- [ ] Initialize Vulkan through SDL3.
- [ ] Render a basic 3D scene.
- [ ] Define how the graphics backend is selected.

### Future phases

- [ ] Add automated tests.
- [ ] Add continuous integration.
- [ ] Evaluate macOS support.
- [ ] Evaluate Android support.
- [ ] Evaluate iOS support.

## Dependency management

SDL3 will be downloaded during the first CMake configuration with `FetchContent`.

To keep dependency retrieval reproducible and secure:

- An exact SDL3 release will be used.
- The downloaded archive will be verified with SHA-256.
- Downloads will use the official HTTPS source.
- Moving branches such as `main` will not be used as dependency versions.
- Absolute paths from a developer's computer will not be stored.
- Precompiled SDL3 binaries will not be committed to the repository.

The first configuration will require an Internet connection. CMake will then be able to reuse the locally downloaded files.

## Using the template

Once Phase 1 is complete, select **Use this template** on GitHub to create an independent repository with the same directory structure and files.

GitHub will ask for repository information such as its name, owner, description, and visibility. It will not ask questions about the game design or automatically select game features.

## Security

Before every public commit or release, the staged changes and relevant repository history will be reviewed to ensure that:

- Passwords, tokens, private keys, certificates, and other credentials are not included.
- Personal data and machine-specific absolute paths are not included.
- Build directories, caches, executables, and downloaded dependencies are not committed.
- External dependencies come from known sources and use pinned versions and integrity checks.
- The commit contains only the intended files.

Secrets required in the future must be stored outside the repository.

## License

A license has not been selected yet. It will be decided before the first usable release of the template.
