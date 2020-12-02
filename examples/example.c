#define OGG_IMPL
#define VORBIS_IMPL
#include "../minivorbis.h"

int main(int argc, char** argv)
{
    if(argc < 2) {
        printf("No input file.\n");
        return -1;
    }
    /* Open sound file. */
    FILE* fp = fopen(argv[1], "rb");
    if(!fp) {
        printf("Failed to open file '%s'.", argv[1]);
        return -1;
    }
    /* Open sound stream. */
    OggVorbis_File vorbis;
    if(ov_open_callbacks(fp, &vorbis, NULL, 0, OV_CALLBACKS_DEFAULT) != 0) {
        printf("Invalid Ogg file '%s'.", argv[1]);
        return -1;
    }
    /* Print sound information. */
    vorbis_info* info = ov_info(&vorbis, -1);
    printf("Ogg file %d Hz, %d channels, %d kbit/s.\n", info->rate, info->channels, info->bitrate_nominal / 1024);
    /* Read the entire sound stream. */
    unsigned char buf[4096];
    while(1) {
        int section = 0;
        long bytes = ov_read(&vorbis, buf, sizeof(buf), 0, 2, 1, &section);
        if(bytes <= 0) /* end of file or error */
            break;
    }
    /* Close sound file */
    ov_clear(&vorbis);
    return 0;
}
