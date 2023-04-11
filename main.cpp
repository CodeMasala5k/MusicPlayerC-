#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

int main() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        cout << "Failed to initialize SDL: " << SDL_GetError() << endl;
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout << "Failed to initialize audio: " << Mix_GetError() << endl;
        SDL_Quit();
        return 1;
    }
    cout << "Enter the file path of the WAV file: ";
    string filePath;
    cin >> filePath;
    Mix_Chunk* audio = Mix_LoadWAV(filePath.c_str());
    if (audio == nullptr) {
        cout << "Failed to load audio: " << Mix_GetError() << endl;
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }
    Mix_PlayChannel(-1, audio, 0);
    while (Mix_Playing(-1)) {
        SDL_Delay(100);
    }
    Mix_FreeChunk(audio);
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
