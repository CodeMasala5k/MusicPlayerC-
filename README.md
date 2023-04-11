# MusicPlayerC-
This is a simple audio player program in C++ using the SDL_mixer library. This program loads and plays a WAV file specified by the user.
Explanation:

The program first initializes the SDL audio subsystem using SDL_Init().

Then it initializes the SDL_mixer library using Mix_OpenAudio() with the desired audio parameters (44100 Hz, 16-bit stereo) and a buffer size of 2048 samples.

The user is prompted to enter the file path of the WAV file to play.

The WAV file is loaded into a Mix_Chunk object using Mix_LoadWAV().

If the audio file fails to load, the program prints an error message and exits.

If the audio file is loaded successfully, it is played using Mix_PlayChannel() on an available audio channel (-1 means use any available channel) with a single loop (0 means no loop).

The program waits for the audio to finish playing using a busy wait loop with a small delay of 100 ms.

After the audio is done playing, the Mix_Chunk object is freed using Mix_FreeChunk() and the SDL audio subsystem and SDL_mixer library are shut down using Mix_CloseAudio() and SDL_Quit(), respectively.
