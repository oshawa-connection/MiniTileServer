#include <stdio.h>
#include "png.h" // Compile with flag -lpng


png_structp png_ptr;
png_infop info_ptr;

int readpng_init(FILE * pngFile, unsigned int * pWidth, unsigned int * pHeight) {
    unsigned char sig[8];

    fread(sig, 1, 8, pngFile);
    if (!png_check_sig(sig, 8))
        return 1;   /* bad signature */

    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL,
      NULL);
    if (!png_ptr)
        return 4;   /* out of memory */

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return 4;   /* out of memory */
    }
    
    png_init_io(png_ptr, pngFile);
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);

    int temp= 0;
    int temp2 = 0;
    png_get_IHDR(png_ptr, info_ptr, pWidth, pHeight, &temp,
      &temp2, NULL, NULL, NULL);

    return 0;
}

int main() {
    unsigned int pngWidth = 0;
    unsigned int pngHeight = 0;

    unsigned int * pWidth = &pngWidth;
    unsigned int * pHeight = &pngHeight;

    FILE * mypng = fopen("./topp-states.png","rb");
    if (mypng == NULL) {
        printf("Invalid file path\n");
        return 1;
    }

    int something = readpng_init(mypng, pWidth, pHeight);
    printf("status %d\n",something);
    printf("HEIGHT: %d WIDTH: %d\n",pngHeight,pngWidth);
    return 0;
}

