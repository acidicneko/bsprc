#ifndef __WM_H__
#define __WM_H__

#include <stdbool.h>
#include <stdint.h>

#define DEBUG 0
#define NORMAL 1

typedef struct config {
    char* name;
    char* value;
} config_t;


typedef struct window_rule {
    char* name;
    char* desktop;
    char* state;
    char* follow;
} window_rule_t;

typedef struct desktop {
    char* name;
} desktop_t;

void init_bspwm(int mode);

#endif