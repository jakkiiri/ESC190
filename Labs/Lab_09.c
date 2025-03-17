#include "c_img.h"
#include "c_img.c"


// Adjust Brightness Function
void adjust_brightness(struct rgb_img *im, float factor, struct rgb_img **result) {
    size_t height = im->height;
    size_t width = im->width;
    create_img(result, height, width);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = get_pixel(im, y, x, 0);
            int g = get_pixel(im, y, x, 1);
            int b = get_pixel(im, y, x, 2);

            r = (int)(r * factor);
            g = (int)(g * factor);
            b = (int)(b * factor);

            // check between 0 - 255
            if (r > 255) {
                r = 255;
            } else if (r < 0) {
                r = 0;
            }

            if (g > 255) {
                g = 255;
            } else if (g < 0) {
                g = 0;
            }

            if (b > 255) {
                b = 255;
            } else if (b < 0) {
                b = 0;
            }

            set_pixel(*result, y, x, r, g, b);
        }
    }
}

int main() {
    struct rgb_img *original_img;
    struct rgb_img *brightness_imgs[5];
    float brightness_factors[5] = {0.5, 0.75, 1.0, 1.25, 1.5};

    // read image
    read_in_img(&original_img, "cannon.bin");

    // 5 brightness levels
    for (int i = 0; i < 5; i++) {
        adjust_brightness(original_img, brightness_factors[i], &brightness_imgs[i]);
        char filename[20];
        sprintf(filename, "output_image%d.bin", i);
        write_img(brightness_imgs[i], filename);
    }

    // free memory
    destroy_image(original_img);
    for (int i = 0; i < 5; i++) {
        destroy_image(brightness_imgs[i]);
    }

    return 0;
}
