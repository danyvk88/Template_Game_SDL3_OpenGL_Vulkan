# Plantilla de juego 3D con SDL3 — OpenGL y Vulkan

[English](README.md) | **Español**

Plantilla educativa en C++23 para iniciar proyectos de videojuegos 3D con SDL3 y CMake.

> [!IMPORTANT]
> Este proyecto está en desarrollo y todavía no constituye una plantilla de juego compilable.
> La primera versión utilizable se alcanzará cuando esté terminada la fase de SDL3.

## Índice

- [Descripción general](#descripción-general)
- [Estado actual](#estado-actual)
- [Objetivo](#objetivo)
- [Plataforma inicial](#plataforma-inicial)
- [Hoja de ruta](#hoja-de-ruta)
- [Gestión de dependencias](#gestión-de-dependencias)
- [Uso de la plantilla](#uso-de-la-plantilla)
- [Seguridad](#seguridad)
- [Licencia](#licencia)

## Descripción general

Este repositorio proporcionará una base pequeña, comprensible y reutilizable para crear videojuegos 3D. Está pensado tanto como proyecto de aprendizaje como punto de partida para futuros juegos.

Este proyecto es una plantilla de inicio, no un motor de videojuegos completo.

## Estado actual

Actualmente, el repositorio solo contiene documentación. El sistema de compilación, la integración con SDL3 y la aplicación de ejemplo todavía no se han implementado.

Aunque GitHub ya muestra el botón **Use this template**, el repositorio generado no será útil para desarrollar juegos hasta que se complete la fase 1.

## Objetivo

La plantilla proporcionará inicialmente:

- Una estructura de proyecto organizada.
- Configuración y compilación mediante CMake.
- C++23 como estándar obligatorio del lenguaje.
- Una ventana y un bucle principal implementados con SDL3.
- Gestión básica de eventos y un cierre limpio de la aplicación.
- Una base preparada para backends de renderizado 3D.

## Plataforma inicial

La primera plataforma de desarrollo soportada será:

- Windows x64.
- MSVC con soporte para C++23.
- CMake como sistema de configuración y compilación.
- Visual Studio Code como editor recomendado.

Ninja no será necesario inicialmente. CMake podrá utilizar el generador de Visual Studio proporcionado por las herramientas de MSVC.

Más adelante se podrá evaluar la compatibilidad con macOS, Android e iOS. Actualmente, estas plataformas no están soportadas ni garantizadas.

## Hoja de ruta

### Fase 1 — SDL3

- [ ] Crear la estructura inicial del proyecto.
- [ ] Configurar CMake y exigir C++23.
- [ ] Descargar de forma segura una versión fija de SDL3.
- [ ] Crear una ventana con SDL3.
- [ ] Implementar el bucle principal y la gestión de eventos.
- [ ] Implementar el cierre limpio de la aplicación.
- [ ] Verificar la compilación y ejecución en Windows x64 desde una copia limpia.

### Fase 2 — OpenGL

- [ ] Crear un contexto OpenGL mediante SDL3.
- [ ] Inicializar la funcionalidad necesaria de OpenGL.
- [ ] Renderizar una escena 3D básica.

### Fase 3 — Vulkan

- [ ] Detectar la disponibilidad de Vulkan.
- [ ] Inicializar Vulkan mediante SDL3.
- [ ] Renderizar una escena 3D básica.
- [ ] Definir cómo se selecciona el backend gráfico.

### Fases futuras

- [ ] Añadir pruebas automáticas.
- [ ] Añadir integración continua.
- [ ] Evaluar la compatibilidad con macOS.
- [ ] Evaluar la compatibilidad con Android.
- [ ] Evaluar la compatibilidad con iOS.

## Gestión de dependencias

SDL3 se descargará durante la primera configuración de CMake mediante `FetchContent`.

Para que la obtención de dependencias sea reproducible y segura:

- Se utilizará una versión exacta de SDL3.
- El archivo descargado se verificará mediante SHA-256.
- Las descargas utilizarán la fuente HTTPS oficial.
- No se utilizarán ramas cambiantes como `main` para definir versiones de dependencias.
- No se almacenarán rutas absolutas de los ordenadores de desarrollo.
- No se incluirán binarios precompilados de SDL3 en el repositorio.

La primera configuración necesitará conexión a Internet. Después, CMake podrá reutilizar los archivos descargados localmente.

## Uso de la plantilla

Cuando se complete la fase 1, selecciona **Use this template** en GitHub para crear un repositorio independiente con la misma estructura de directorios y archivos.

GitHub solicitará información como el nombre, propietario, descripción y visibilidad del nuevo repositorio. No preguntará por el diseño del juego ni seleccionará automáticamente sus características.

## Seguridad

Antes de cada commit público o publicación se revisarán los cambios preparados y el historial relevante del repositorio para comprobar que:

- No se incluyan contraseñas, tokens, claves privadas, certificados ni otras credenciales.
- No se incluyan datos personales ni rutas absolutas específicas de un equipo.
- No se incluyan carpetas de compilación, cachés, ejecutables ni dependencias descargadas.
- Las dependencias externas procedan de fuentes conocidas y utilicen versiones fijas y comprobaciones de integridad.
- El commit contenga únicamente los archivos previstos.

Los secretos que puedan necesitarse en el futuro deberán almacenarse fuera del repositorio.

## Licencia

Todavía no se ha seleccionado una licencia. Se decidirá antes de la primera versión utilizable de la plantilla.
