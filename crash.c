/**
 *  @file
 *
 *  Handy little utility to generate a crash in Linux in various ways.
 *
 *  To compile:
 *  gcc -Wall crash.c -o crash
 *  
 *  MIT License
 *
 *  Copyright (c) 2015, Michael Becker (michael.f.becker@gmail.com)
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a 
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 *  and/or sell copies of the Software, and to permit persons to whom the 
 *  Software is furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included 
 *  in all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
 *  OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR 
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 *  How to use this program.
 */
void help(void)
{
    printf("crash [--help|--div0|--seg|--abt]\n");
    printf("Generates a user specified crash.\n");
    exit (0);
}


int main (int argc, char *argv[])
{
    if (argc == 1) {
        help();
    }
    else if (strcmp(argv[1], "--help") == 0){
        help();
    }
    else if (strcmp(argv[1], "--div0") == 0) {
        /*
         *  Need to be a little clever or the compiler complains.
         */
        int zero = 0;
        int x = 1 / zero;
        (void)x;
    }
    else if (strcmp(argv[1], "--seg") == 0) {
        int *p = NULL;
        *p = 1;
    }
    else if (strcmp(argv[1], "--abt") == 0) {
        abort();
    }
    else {
        printf("Unknown option\n");
        return 0;
    }

    /*
     *  We should never make it here, but some compilers 
     *  complain without this return.
     */
    return -1;
}


