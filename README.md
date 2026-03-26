## Como compilar a primeira entrega:

- Tenha as bibliotecas do SDL instaladas
- Execute (Windows):
    ```bash
    g++ ./src/main.cpp ./src/Game.cpp ./src/State.cpp ./src/Sprite.cpp ./src/Music.cpp -o ./bin/Trabalho1 -I"Caminho/para/include/SDL2" -L"Caminho/para/lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
    ```
    Onde:
    - "Caminho/para/include/SDL2" é o caminho onde se encontram os headers das bibliotecas SDL
    - "Caminho/para/lib" é o caminho da pasta lib do SDL
- Execute (Arch Linux):
    ```bash
    g++ src/main.cpp src/Game.cpp src/State.cpp src/Sprite.cpp src/Music.cpp -o bin/Trabalho1 $(pkg-config --cflags --libs sdl2 SDL2_image SDL2_mixer)
    ```

## Como executar:
- Abra o arquivo clicando no executável ou navegando até a pasta bin pelo terminal e executando pelo terminal. 