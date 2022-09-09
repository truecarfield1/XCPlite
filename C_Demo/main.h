#pragma once

/* main.h */
/*
| Code released into public domain, no attribution required
*/

// Windows or Linux ?
#if defined(_WIN32) || defined(_WIN64)
  #define _WIN
  #if defined(_WIN32) && defined(_WIN64)
    #undef _WIN32
  #endif
  #if defined(_LINUX) || defined(_LINUX64)|| defined(_LINUX32)
    #error
  #endif
#else
  #define _LINUX
  #if defined (_ix64_) || defined (__x86_64__) || defined (__aarch64__)
    #define _LINUX64
  #else
    #define _LINUX32
  #endif
  #if defined(_WIN) || defined(_WIN64)|| defined(_WIN32)
    #error
  #endif
#endif


#ifdef _WIN
  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
  #endif
  #ifndef _CRT_SECURE_NO_WARNINGS
    #define _CRT_SECURE_NO_WARNINGS
  #endif
#else
  #ifndef _DEFAULT_SOURCE
    #define _DEFAULT_SOURCE
  #endif
#endif


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#ifdef _WIN
#define M_PI 3.14159265358979323846
#endif
#define M_2PI (M_PI*2)

#include <assert.h>

#ifndef _WIN // Linux

#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/time.h>
#include <time.h>
#include <sys/stat.h>
#include <pthread.h>

#include <ifaddrs.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_PATH 256
#define BOOL int
#define FALSE 0
#define TRUE 1

#else // Windows

#include <windows.h>
#include <time.h>
#include <conio.h>

#define BOOL int
#define FALSE 0
#define TRUE 1

#endif

