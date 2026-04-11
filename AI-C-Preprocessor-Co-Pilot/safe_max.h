{\rtf1\ansi\ansicpg1252\cocoartf2868
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #ifndef SAFE_MAX_H\
#define SAFE_MAX_H\
\
#include <stdio.h>\
\
#ifdef DEBUG_MODE\
    #define DEBUG_LOG(msg, a, b) \\\
        fprintf(stderr, "[DEBUG] %s:%d: " msg " | a=%d, b=%d\\n", \\\
                __FILE__, __LINE__, (a), (b))\
#else\
    #define DEBUG_LOG(msg, a, b) ((void)0)\
#endif\
\
#ifdef DEBUG_MODE\
    #define SAFE_MAX(a, b) (\{ \\\
        __typeof__(a) _a = (a); \\\
        __typeof__(b) _b = (b); \\\
        DEBUG_LOG("SAFE_MAX comparison", _a, _b); \\\
        (_a > _b) ? _a : _b; \\\
    \})\
#else\
    #define SAFE_MAX(a, b) (\{ \\\
        __typeof__(a) _a = (a); \\\
        __typeof__(b) _b = (b); \\\
        (_a > _b) ? _a : _b; \\\
    \})\
#endif\
\
#endif /* SAFE_MAX_H */}