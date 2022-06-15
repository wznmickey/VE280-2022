#ifndef IMAGE_H
#define IMAGE_H 
#include "constants.h"

/*
 * The type for a pixel in the image
 * use three values r g b to represent a 3D vector
 */
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Rgb;

/*
 * The type for a image in this project.
 * image is a WMAX * HMAX * 3 vector
 * w, h is the size of the image
 */
typedef struct {
    Rgb image[WMAX][HMAX];
    unsigned int w;
    unsigned int h;
} Image;


#endif // !IMAGE_H
