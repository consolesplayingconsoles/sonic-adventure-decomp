/* @unit 0CB860F8-0CB86F78 +rtflags +resff -macsave=1 +asmfunc=FUN_0cb869c8:0cb86e44 */
/* Ported from the Japanese release's events/shared/sdk/_fmtin.c (tools/jpport/mkunit_ov.py): its C rebuilds this range byte for byte. */
extern const unsigned char _ctype[];
int toupper(int c);
extern volatile int _errno;
typedef char *va_list;
typedef struct _iobuf {
    unsigned char *_bufptr;
    long _bufcnt;
    unsigned char *_bufbase;
    long _buflen;
    char _ioflag1;
} FILE;
int sprintf(char *s, const char *format, ...);
int vsprintf(char *s, const char *format, va_list args);
int sscanf(const char *s, const char *format, ...);
int FUN_0cb860f8(int string_mode, int (*read)(FILE *), const void *input,
           const char *format, va_list arguments);
enum {
    RANGE_ERRNO_FLOAT = 1,
    RANGE_ERRNO_DOUBLE,
    RANGE_ERRNO_LONG_DOUBLE,
    RANGE_ERRNO_RANGE
};
float _stf(int sign, const char *digits, int exponent, char range_errno);
void _calcint(unsigned char *integer, int digit, int count);
float _calcfpow(unsigned char *integer, int n, char range_errno);
float _packf(short exponent, unsigned char *fraction);
enum {
    SCAN_UNLIMITED = 1,
    SCAN_OVERFLOW = 2,
    SCAN_STREAM = 4,
    SCAN_STOP = 8,
    SCAN_STRING_END = 16
};
union input_cursor {
    const char *text;
    FILE *stream;
};
struct input_state {
    union {
        char signed_byte;
        unsigned char code;
    } current;
    char length;
    char conversion;
    char flags;
    union input_cursor cursor;
    unsigned int fetched_count;
    int width;
    int (*read)(FILE *);
};
int FUN_0cb8658c(int radix, void *destination,
                        struct input_state *state);
int FUN_0cb869c8(char conversion, void *destination,
                        struct input_state *state);
int FUN_0cb86e44(const char **format, char *destination,
                    struct input_state *state);
void FUN_0cb86f14(struct input_state *state);
void FUN_0cb86f56(struct input_state *state);
int FUN_0cb860f8(int string_mode, int (*read)(FILE *), const void *input,
           const char *format_input, va_list arguments)
{
    struct input_state storage;
    struct input_state *state = &storage;
    int saved_width;
    const char *format;
    int radix;
    int assignments;
    char *destination;
    saved_width = 0;
    format = 0;
    state->current.signed_byte = 0;
    state->flags = 0;
    state->length = 0;
    state->conversion = 0;
    state->cursor.text = 0;
    state->fetched_count = 0;
    if (!string_mode) {
        if (!input) {
            _errno = 1106;
            return -1;
        }
        if (!(((const FILE *)input)->_ioflag1 & (1 | 2 | 4))) {
            _errno = 1300;
            return -1;
        }
        if (!(((const FILE *)input)->_ioflag1 & 4) &&
            (((const FILE *)input)->_ioflag1 & 2)) {
            _errno = 1302;
            return -1;
        }
        state->read = read;
    }
    state->current.signed_byte = 0;
    state->cursor.text = input;
    format = format_input;
    state->flags = 0;
    state->fetched_count = 0;
    assignments = 0;
    if (!string_mode) {
        state->flags |= SCAN_STREAM;
    }
    FUN_0cb86f14(state);
    if (state->current.signed_byte == -1) {
        assignments = -1;
    }
    while (*format && state->current.signed_byte != -1 &&
           !(state->flags & SCAN_STOP)) {
        if (*format == ' ' || *format == '\t' || *format == '\n') {
            while (*format == ' ' || *format == '\t' || *format == '\n') {
                ++format;
            }
            while (_ctype[state->current.code] & 0x40) {
                FUN_0cb86f14(state);
            }
        } else if (*format != '%') {
            if (*format != state->current.signed_byte) {
                state->flags |= SCAN_STOP;
                _errno = 1304;
            } else {
                ++format;
                FUN_0cb86f14(state);
            }
        } else {
            ++format;
            switch (*format) {
            case '*':
                ++format;
            case '%':
                destination = 0;
                break;
            default:
                destination = ((arguments) = (int)((arguments) + sizeof(char *)) % 4U ? (arguments) + (((sizeof(char *) / 4U) + 1U) * 4U) : (arguments) + sizeof(char *), *(char * *)((int)((arguments) - sizeof(char *)) % 4U ? (arguments) - (((sizeof(char *) / 4U) + 1U) * 4U) : (arguments) - sizeof(char *)));
                break;
            }
            state->width = 0;
            if (_ctype[(unsigned char)*format] & 0x04) {
                state->flags &= ~SCAN_UNLIMITED;
                while (_ctype[(unsigned char)*format] & 0x04) {
                    int digit = *format - '0';
                    if ((512 - digit) / 10 >= state->width) {
                        state->width = (state->width * 10) + digit;
                    } else {
                        state->flags |= SCAN_STOP;
                        _errno = 1304;
                    }
                    ++format;
                }
                saved_width = state->width;
            } else {
                state->flags |= SCAN_UNLIMITED;
            }
            state->length = *format;
            if (state->length == 'h' || state->length == 'l' ||
                state->length == 'L') {
                ++format;
            } else {
                state->length = ' ';
            }
            if (*format != 'c' && *format != '[' && *format != 'n') {
                while (_ctype[state->current.code] & 0x40) {
                    FUN_0cb86f14(state);
                }
            }
            state->width = saved_width;
            switch (*format) {
            case 'd':
            case 'u':
            case 'i':
            case 'o':
            case 'x':
            case 'X':
                state->conversion = *format;
                if (*format == 'd' || *format == 'u') {
                    radix = 10;
                }
                if (*format == 'i') {
                    radix = 0;
                }
                if (*format == 'o') {
                    radix = 8;
                }
                if (*format == 'x' || *format == 'X') {
                    radix = 16;
                }
                if (FUN_0cb8658c(radix, destination, state)) {
                    state->flags |= SCAN_STOP;
                }
                break;
            case 's':
                state->flags &= ~SCAN_STRING_END;
                if (state->current.signed_byte == -1) {
                    state->flags |= SCAN_STOP;
                }
                while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                       state->current.signed_byte != -1 &&
                       !(state->flags & SCAN_STRING_END)) {
                    if (!(state->flags & SCAN_UNLIMITED)) {
                        while (state->width > 0 &&
                               state->current.signed_byte != -1) {
                            if (destination) {
                                *destination++ = state->current.signed_byte;
                            }
                            FUN_0cb86f14(state);
                        }
                    } else {
                        while (state->current.signed_byte != -1 &&
                               state->current.signed_byte != ' ' &&
                               state->current.signed_byte != '\n' &&
                               state->current.signed_byte != '\t') {
                            if (destination) {
                                *destination++ = state->current.signed_byte;
                            }
                            FUN_0cb86f14(state);
                        }
                        state->flags |= SCAN_STRING_END;
                    }
                }
                if (destination) {
                    *destination = 0;
                }
                break;
            case 'c':
                if (state->flags & SCAN_UNLIMITED) {
                    state->width = 1;
                }
                if (state->current.signed_byte == -1) {
                    state->flags |= SCAN_STOP;
                }
                while (state->width > 0 && state->current.signed_byte != -1) {
                    if (destination) {
                        *destination++ = state->current.signed_byte;
                    }
                    FUN_0cb86f14(state);
                }
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                if (FUN_0cb869c8(*format, destination, state)) {
                    state->flags |= SCAN_STOP;
                }
                break;
            case 'p':
                if (FUN_0cb8658c(16, destination, state)) {
                    state->flags |= SCAN_STOP;
                }
                break;
            case 'n':
                if (destination) {
                    *(int *)destination = state->fetched_count;
                }
                break;
            case '[':
                if (FUN_0cb86e44(&format, destination, state)) {
                    state->flags |= SCAN_STOP;
                }
                break;
            case '%':
                if (state->current.signed_byte != '%') {
                    state->flags |= SCAN_STOP;
                    _errno = 1304;
                } else {
                    FUN_0cb86f14(state);
                }
                break;
            default:
                _errno = 1304;
                state->flags |= SCAN_STOP;
                break;
            }
            if (!(state->flags & SCAN_STOP) && *format != 'n' && destination) {
                ++assignments;
            }
            ++format;
        }
    }
    if (state->current.signed_byte != -1) {
        FUN_0cb86f56(state);
    }
    return assignments;
}
int FUN_0cb8658c(int radix, void *destination, struct input_state *state)
{
    unsigned long result;
    unsigned long accumulator;
    unsigned char digit;
    char last_digit;
    int sign = 1;
    int matched;
    matched = result = 0;
    if (state->length == 'L') {
        _errno = 1304;
        return -1;
    }
    if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
        (state->current.signed_byte == '+' ||
         state->current.signed_byte == '-')) {
        if (state->current.signed_byte == '-') {
            sign = -1;
        }
        FUN_0cb86f14(state);
    }
    if (!radix) {
        if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
            state->current.signed_byte == '0') {
            FUN_0cb86f14(state);
            if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                ((_ctype[state->current.code] & 0x01)
                     ? state->current.signed_byte + 32
                     : state->current.signed_byte) == 'x') {
                FUN_0cb86f14(state);
                radix = 16;
            } else {
                radix = 8;
                matched = 1;
            }
        } else {
            radix = 10;
        }
    } else if (radix == 16) {
        if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
            state->current.signed_byte == '0') {
            FUN_0cb86f14(state);
            if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                ((_ctype[state->current.code] & 0x01)
                     ? state->current.signed_byte + 32
                     : state->current.signed_byte) == 'x') {
                FUN_0cb86f14(state);
            } else {
                matched = 1;
            }
        }
    }
    last_digit = radix > 10 ? 'a' - 11 + radix : '0' - 1 + radix;
    if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
        (_ctype[state->current.code] & (0x01 | 0x02 | 0x04)) &&
        ((_ctype[state->current.code] & 0x01)
             ? state->current.signed_byte + 32
             : state->current.signed_byte) <= last_digit) {
        matched = 1;
        while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
               state->current.signed_byte == '0') {
            FUN_0cb86f14(state);
        }
        state->flags &= ~SCAN_OVERFLOW;
        accumulator = 0;
        while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
               (_ctype[state->current.code] & (0x01 | 0x02 | 0x04)) &&
               ((_ctype[state->current.code] & 0x01)
                    ? state->current.signed_byte + 32
                    : state->current.signed_byte) <= last_digit) {
            if (!(state->flags & SCAN_OVERFLOW)) {
                if (_ctype[state->current.code] & 0x04) {
                    digit = state->current.signed_byte - '0';
                } else {
                    digit =
                        ((_ctype[state->current.signed_byte & 0xff] & 0x01)
                             ? state->current.signed_byte + 32
                             : state->current.signed_byte) -
                        'a' + 10;
                }
                switch (state->length) {
                case 'h':
                    if (accumulator > (65535UL - digit) / radix) {
                        state->flags |= SCAN_OVERFLOW;
                        switch (state->conversion) {
                        case 'd':
                        case 'i':
                            if (sign == 1) {
                                result = 32767;
                            } else {
                                result = (unsigned long)-32768;
                            }
                            break;
                        case 'x':
                        case 'X':
                        case 'o':
                        case 'u':
                            result = 65535;
                        }
                    } else {
                        accumulator = (accumulator * radix) + digit;
                    }
                    break;
                case 'l':
                    if (accumulator > (0xffffffffUL - digit) / radix) {
                        state->flags |= SCAN_OVERFLOW;
                        switch (state->conversion) {
                        case 'd':
                        case 'i':
                            if (sign == 1) {
                                result = 0x7fffffffUL;
                            } else {
                                result = 0x80000000UL;
                            }
                            break;
                        case 'x':
                        case 'X':
                        case 'o':
                        case 'u':
                            result = 0xffffffffUL;
                        }
                    } else {
                        accumulator = (accumulator * radix) + digit;
                    }
                    break;
                case ' ':
                    if (accumulator > (0xffffffffU - digit) / radix) {
                        state->flags |= SCAN_OVERFLOW;
                        switch (state->conversion) {
                        case 'd':
                        case 'i':
                            if (sign == 1) {
                                result = 0x7fffffffUL;
                            } else {
                                result = 0x80000000UL;
                            }
                            break;
                        case 'x':
                        case 'X':
                        case 'o':
                        case 'u':
                            result = 0xffffffffU;
                        }
                    } else {
                        accumulator = (accumulator * radix) + digit;
                    }
                    break;
                }
            }
            FUN_0cb86f14(state);
        }
        if (!(state->flags & SCAN_OVERFLOW)) {
            if (sign == 1) {
                result = accumulator;
            } else {
                result = -accumulator;
            }
        } else {
            _errno = 1100;
        }
    }
    if (matched == 1) {
        if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
            ((_ctype[state->current.code] & 0x01)
                 ? state->current.signed_byte + 32
                 : state->current.signed_byte) == 'u') {
            FUN_0cb86f14(state);
            if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                ((_ctype[state->current.code] & 0x01)
                     ? state->current.signed_byte + 32
                     : state->current.signed_byte) == 'l') {
                FUN_0cb86f14(state);
            }
        } else if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                   ((_ctype[state->current.code] & 0x01)
                        ? state->current.signed_byte + 32
                        : state->current.signed_byte) == 'l') {
            FUN_0cb86f14(state);
            if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                ((_ctype[state->current.code] & 0x01)
                     ? state->current.signed_byte + 32
                     : state->current.signed_byte) == 'u') {
                FUN_0cb86f14(state);
            }
        }
    }
    if (destination) {
        switch (state->length) {
        case 'h':
            *(short *)destination = result;
            break;
        case 'l':
            *(long *)destination = result;
            break;
        default:
            *(int *)destination = result;
        }
    }
    if (matched) {
        return 0;
    }
    return 1;
}
union decimal_value {
    float value;
    unsigned char bytes[8];
};
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int FUN_0cb869c8(char conversion, void *destination,
                        struct input_state *state)
{
    char digits[17];
    char exponent_digits[3];
    union decimal_value zero;
    union {
        unsigned long words[2];
        struct {
            unsigned long pad;
            char range_errno;
        } suffix;
    } wide_limit;
    struct decimal_limit {
        union {
            unsigned long encoding;
            float value;
        } narrow;
        int range;
    } limit;
    float converted;
    char *result;
    int digit_count;
    unsigned int before_point;
    int exponent_digit_count;
    int sign;
    int exponent_sign;
    int matched;
    int exponent;
    int index;
    unsigned char *clear;
    unsigned long *word;
    for (index = 0, clear = zero.bytes;;) {
        *clear = 0;
        clear = clear + 1;
        ++index;
        if (index < 8) {
            continue;
        }
        break;
    }
    word = wide_limit.words;
    word[0] = 0;
    word[1] = 2047UL << 20;
    word = &limit.narrow.encoding;
    *word = 255UL << 23;
    digit_count = 0;
    exponent_digit_count = 0;
    sign = 1;
    exponent_sign = 1;
    before_point = 0;
    limit.range = 0;
    matched = 0;
    if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
        (state->current.signed_byte == '+' ||
         state->current.signed_byte == '-')) {
        if (state->current.signed_byte == '-') {
            sign = -1;
        }
        FUN_0cb86f14(state);
    }
    while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
           state->current.signed_byte == '0') {
        matched = 1;
        FUN_0cb86f14(state);
    }
    while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
           (_ctype[state->current.code] & 0x04)) {
        matched = 1;
        if (digit_count < 17) {
            digits[digit_count++] = state->current.signed_byte;
        } else {
            _errno = 1202;
        }
        FUN_0cb86f14(state);
        ++before_point;
    }
    if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
        state->current.signed_byte == '.') {
        FUN_0cb86f14(state);
        if (!digit_count) {
            while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                   state->current.signed_byte == '0') {
                matched = 1;
                FUN_0cb86f14(state);
                --before_point;
            }
        }
        while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
               (_ctype[state->current.code] & 0x04)) {
            matched = 1;
            if (digit_count < 17) {
                digits[digit_count++] = state->current.signed_byte;
            } else {
                _errno = 1202;
            }
            FUN_0cb86f14(state);
        }
    }
    if (!digit_count) {
        result = (char *)zero.bytes;
        if (matched == 1) {
            if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                ((_ctype[state->current.code] & 0x01)
                     ? state->current.signed_byte + 32
                     : state->current.signed_byte) == 'e') {
                FUN_0cb86f14(state);
                if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                    (state->current.signed_byte == '+' ||
                     state->current.signed_byte == '-')) {
                    FUN_0cb86f14(state);
                }
                while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
                       (_ctype[state->current.code] & 0x04)) {
                    FUN_0cb86f14(state);
                }
            }
        }
        if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
            (((_ctype[state->current.code] & 0x01)
                  ? state->current.signed_byte + 32
                  : state->current.signed_byte) == 'f' ||
             ((_ctype[state->current.code] & 0x01)
                  ? state->current.signed_byte + 32
                  : state->current.signed_byte) == 'l')) {
            FUN_0cb86f14(state);
        }
        goto store_decimal;
    }
    if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
        ((_ctype[state->current.code] & 0x01)
             ? state->current.signed_byte + 32
             : state->current.signed_byte) == 'e') {
        FUN_0cb86f14(state);
        if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
            (state->current.signed_byte == '+' ||
             state->current.signed_byte == '-')) {
            if (state->current.signed_byte == '-') {
                exponent_sign = -1;
            }
            FUN_0cb86f14(state);
        }
        while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
               state->current.signed_byte == '0') {
            FUN_0cb86f14(state);
        }
        while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
               (_ctype[state->current.code] & 0x04)) {
            if (exponent_digit_count < 3) {
                exponent_digits[exponent_digit_count++] =
                    state->current.signed_byte;
            } else {
                _errno = 1204;
                limit.range = exponent_sign;
            }
            FUN_0cb86f14(state);
        }
    }
    if (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
        (((_ctype[state->current.code] & 0x01)
              ? state->current.signed_byte + 32
              : state->current.signed_byte) == 'f' ||
         ((_ctype[state->current.code] & 0x01)
              ? state->current.signed_byte + 32
              : state->current.signed_byte) == 'l')) {
        if (((_ctype[state->current.signed_byte & 0xff] & 0x01)
                 ? state->current.signed_byte + 32
                 : state->current.signed_byte) == 'l') {
            wide_limit.suffix.range_errno = RANGE_ERRNO_LONG_DOUBLE;
        } else {
            wide_limit.suffix.range_errno = RANGE_ERRNO_FLOAT;
        }
        FUN_0cb86f14(state);
    } else {
        wide_limit.suffix.range_errno = RANGE_ERRNO_DOUBLE;
    }
    if (!limit.range) {
        while (digit_count < 17) {
            digits[digit_count++] = '0';
        }
        exponent = 0;
        for (index = 0; index < exponent_digit_count; ++index) {
            exponent = (exponent * 10) + exponent_digits[index] - '0';
        }
        if (exponent_sign == -1) {
            exponent = -exponent;
        }
        exponent += before_point - 1;
        if (exponent >= 1000) {
            _errno = 1206;
            limit.range = 1;
        } else if (exponent <= -1000) {
            _errno = 1206;
            limit.range = -1;
        }
    }
    switch (limit.range) {
    case 1:
        switch (state->length) {
        default:
            result = (char *)&limit;
            break;
        }
        if (sign == -1) {
            result[7] |= 0x80;
        }
        break;
    case -1:
        result = (char *)zero.bytes;
        if (sign == -1) {
            result[7] |= 0x80;
        }
        break;
    case 0:
        switch (state->length) {
        default:
            converted =
                _stf(sign, digits, exponent, wide_limit.suffix.range_errno);
            result = (char *)&converted;
            break;
        }
        break;
    }
store_decimal:
    if (destination) {
        if (state->length == 'L') {
            *(long double *)destination = *(float *)result;
        } else if (state->length == 'l') {
            *(double *)destination = *(float *)result;
        } else {
            *(float *)destination = *(float *)result;
        }
    }
    return !matched;
}
int FUN_0cb86e44(const char **format, char *destination,
                    struct input_state *state)
{
    const char *begin;
    const char *scan;
    char invert;
    ++*format;
    if (**format == '^') {
        invert = 1;
        ++*format;
    } else {
        invert = 0;
    }
    begin = *format;
    while (**format != ']' && **format != '\0') {
        ++*format;
    }
    if (**format == '\0') {
        _errno = 1304;
        return 1;
    }
    if (state->current.signed_byte == -1) {
        return 1;
    }
    while (((state->flags & SCAN_UNLIMITED) || state->width > 0) &&
           state->current.signed_byte != -1) {
        for (scan = begin; scan < *format; ++scan) {
            if (state->current.signed_byte == *scan) {
                break;
            }
        }
        if (invert == 0) {
            if (scan >= *format) {
                break;
            }
        } else if (scan < *format) {
            break;
        }
        if (destination) {
            *destination++ = state->current.signed_byte;
        }
        FUN_0cb86f14(state);
    }
    if (destination) {
        *destination = 0;
    }
    return 0;
}
void FUN_0cb86f14(struct input_state *state)
{
    if (!(state->flags & SCAN_STREAM)) {
        if (!(state->current.signed_byte = *state->cursor.text++)) {
            state->current.signed_byte = -1;
        }
    } else {
        state->current.signed_byte = state->read(state->cursor.stream);
    }
    if (state->current.signed_byte != -1) {
        ++state->fetched_count;
        state->width = (unsigned int)state->width - 1;
    }
}
void FUN_0cb86f56(struct input_state *state)
{
    if (!(state->flags & SCAN_STREAM)) {
        --state->cursor.text;
    } else {
        ++state->cursor.stream->_bufcnt;
        --state->cursor.stream->_bufptr;
    }
}
