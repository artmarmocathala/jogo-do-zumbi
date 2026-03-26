## Como compilar a primeira entrega (Windows):

- Tenha as bibliotecas do SDL instaladas
- Insira Background.png em Recursos/img
- Insira BGM.wav em Recursos/audio
- execute:
    ```bash
    g++ ./src/main.cpp ./src/Game.cpp ./src/State.cpp ./src/Sprite.cpp ./src/Music.cpp -o ./bin/Trabalho1 -I"Caminho/para/include/SDL2" -L"Caminho/para/lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
    ```
    Onde:
    - "Caminho/para/include/SDL2" é o caminho onde se encontram os headers das bibliotecas SDL
    - "Caminho/para/lib" é o caminho da pasta lib do SDL

## Como executar (Windows):
- Insira as dlls SDL2, SDL2_image, SDL2_mixer e SDL2_ttf na mesma pasta onde o executável se encontra.
- Abra o arquivo clicando no executável ou navegando até a pasta pelo terminal e executando pelo terminal. 