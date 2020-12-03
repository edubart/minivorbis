#if 1
#include "../miniaudio.h"
#include "../miniaudio_vorbis.h"
#include "../miniaudio_engine.h"
#define MINIAUDIO_IMPLEMENTATION
#include "../miniaudio.h"
#include "../miniaudio_vorbis.h"
#include "../miniaudio_engine.h"
#else
#define STB_VORBIS_HEADER_ONLY
#include "../stb_vorbis.h"
#define MINIAUDIO_IMPLEMENTATION
#include "../miniaudio.h"
#include "../miniaudio_engine.h"
#undef STB_VORBIS_HEADER_ONLY
#include "../stb_vorbis.h"
#endif

int main(int argc, char** argv)
{
    ma_result result;
    ma_engine engine;

    if (argc < 2) {
        printf("No input file.");
        return -1;
    }

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.");
        return -1;
    }

    ma_engine_play_sound(&engine, argv[1], NULL);

    printf("Press Enter to quit...");
    getchar();

    ma_engine_uninit(&engine);

    return 0;
}
