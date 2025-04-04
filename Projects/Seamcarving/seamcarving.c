#include "seamcarving.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    // Allocate memory for the gradient image
    int height = im->height;
    int width = im->width;
    create_img(grad, height, width);
    // Calculate the energy of each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int x_left = (x == 0) ? width - 1 : x - 1;
            int x_right = (x == width - 1) ? 0 : x + 1;
            int y_up = (y == 0) ? height - 1 : y - 1;
            int y_down = (y == height - 1) ? 0 : y + 1;

            int rx = get_pixel(im, y, x_right, 0) - get_pixel(im, y, x_left, 0);
            int gx = get_pixel(im, y, x_right, 1) - get_pixel(im, y, x_left, 1);
            int bx = get_pixel(im, y, x_right, 2) - get_pixel(im, y, x_left, 2);

            int ry = get_pixel(im, y_down, x, 0) - get_pixel(im, y_up, x, 0);
            int gy = get_pixel(im, y_down, x, 1) - get_pixel(im, y_up, x, 1);
            int by = get_pixel(im, y_down, x, 2) - get_pixel(im, y_up, x, 2);

            double energy = sqrt((double)(rx * rx + gx * gx + bx * bx + ry * ry + gy * gy + by * by));
            uint8_t scaled_energy = (uint8_t)(energy / 10);
            set_pixel(*grad, y, x, scaled_energy, scaled_energy, scaled_energy);
        }
    }
}  

void dynamic_seam(struct rgb_img *grad, double **best_arr) {

}

void recover_path(double *best, int height, int width, int **path) {

}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {

}
