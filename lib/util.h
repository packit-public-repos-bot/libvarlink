#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _cleanup_(_x) __attribute__((__cleanup__(_x)))
#define _public_ __attribute__((__visibility__("default")))

static inline void freep(void *p) {
        free(*(void **)p);
}

static inline void closep(int *fd) {
        if (*fd >= 0)
                close(*fd);
}

static inline void fclosep(FILE **fp) {
        if (*fp)
                fclose(*fp);
}

int epoll_add(int epfd, int fd, int events, void *ptr);
int epoll_mod(int epfd, int fd, int events, void *ptr);
int epoll_del(int epfd, int fd);

#define MIN(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define MAX(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define ARRAY_SIZE(_x) (sizeof(_x) / sizeof((_x)[0]))
#define ALIGN_TO(_val, _to) (((_val) + (_to) - 1) & ~((_to) - 1))
