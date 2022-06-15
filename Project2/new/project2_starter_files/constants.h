//
// Created by boqun on 2022/5/22.
//

#ifndef PROJECT2_CONSTANTS_H
#define PROJECT2_CONSTANTS_H

/*
 *  Image related constants
 */
#define WMAX 800
#define HMAX 800
#define M 255
#define KERNEL_SIZE 3


/* 
 * Project related message
 */
#define HELP_MESSAGE "Usage: mip [-i input file] [-o output file] -t transformation"
#define TRANSFORM_ERROR "Error: The specified transformation does not correspond to any accepted transformations."
#define FILE_NOT_EXIST_ERROR "Error: The specified input file does not exist."
#define FILE_TYPE_ERROR "Error: The specified input file exists, but is not a PPM file."

#endif //PROJECT2_CONSTANTS_H
