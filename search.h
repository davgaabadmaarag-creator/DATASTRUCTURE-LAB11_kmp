#ifndef SUBSTRING_SEARCH_H
#define SUBSTRING_SEARCH_H

#include <stddef.h>
#include <stdint.h>

/* emit: амжилттай бол 0, зогсоох шаардлагатай бол 0-ээс ялгаатай утга. */
typedef int (*match_fn)(size_t position, void *context);

enum {
    SEARCH_OK = 0,
    SEARCH_NO_MEMORY = 1,
    SEARCH_BAD_ARGUMENT = 2,
    SEARCH_OUTPUT_ERROR = 3,
    SEARCH_NOT_IMPLEMENTED = 4
};

#define KMP_ALPHABET 256

/* m > 0; pattern, dfa, restart хүчинтэй байна.
 * Дуудагч dfa-д 256*m ширхэг size_t багтах санах ой олгосон байна.
 * dfa[c*m+j] нь j төлөвөөс c байт уншихад очих төлөв (0..m).
 * restart нь бүтэн pattern-ийн хамгийн урт proper border-ийн урт.
 */
void kmp_build_dfa(const unsigned char *pattern, size_t m, size_t *dfa,
                   size_t *restart);

/* Бүх олдцын эхлэх байт индексийг өсөх дарааллаар emit-д дамжуулна.
 * Давхцсан олдцыг мөн бүртгэнэ. n, m нь байтаар өгсөн урт; NUL байт
 * текст болон pattern-ийн дотор байж болно. m заавал эерэг байна.
 * n > 0 үед text, үргэлж pattern болон emit хүчинтэй байх ёстой.
 * emit алдаа буцаавал хайлтыг зогсоож SEARCH_OUTPUT_ERROR буцаана.
 */
int search_all(const unsigned char *text, size_t n,
               const unsigned char *pattern, size_t m,
               match_fn emit, void *context);

#endif
