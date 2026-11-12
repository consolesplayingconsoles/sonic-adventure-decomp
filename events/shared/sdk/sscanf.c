/* @unit 0CB85300-0CB8533C +rtflags +resff */
#include <stdarg.h>
#include <stdio.h>

#include "shared/sdk/scan.h"
int FUN_0cb85358(int string_mode, int (*read)(FILE *), const void *input,
                 const char *format, va_list arguments);

int sscanf(const char *s, const char *format, ...)
{
    va_list args;
    int count;
    (void)((args) =
               (int)((char *)&(format) + sizeof(format)) % 4U
                   ? (char *)&(format) + (((sizeof(format) / 4U) + 1U) * 4U)
                   : (char *)&(format) + sizeof(format));
    count = FUN_0cb85358(1, ((void *)0), s, format, args);
    ;
    return count;
}
