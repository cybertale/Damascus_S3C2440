#ifndef __VSPRINTF_H
#define __VSPRINTF_H

#include <stdarg.h>

int vsprintf(char *buf, const char *fmt, va_list args);
int strlen(const char *s);

#endif
