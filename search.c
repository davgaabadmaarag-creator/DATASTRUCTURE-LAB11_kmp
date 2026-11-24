#include "search.h"

/* TODO 1: KMP-ийн DFA хүснэгтийг байгуул.
 *
 * Хүснэгт нь нэг хэмжээст массив: dfa[c*m+j]. Эхлээд 0 төлөвийн
 * шилжилтүүдийг тогтооно. Дараагийн төлөвүүдэд өмнөх мэдээллийг ашиглана.
 * Бүтэн match-ийн дараах restart төлөвийг мөн буцаах шаардлагатай.
 * Зорилт: O(256*m) хугацаа. Санах ойг дуудагч олгосон байна.
 */
void kmp_build_dfa(const unsigned char *pattern, size_t m, size_t *dfa,
                   size_t *restart)
{
    (void)pattern;
    for (size_t c = 0; c < KMP_ALPHABET; ++c)
        for (size_t j = 0; j < m; ++j)
            dfa[c * m + j] = 0;
    *restart = 0;
    /* TODO: дээрх эхлүүлэлтийг гүйцээ. */
}

/* TODO 2: DFA ашиглан бүх олдцыг хай.
 *
 * - search.h дахь оролт болон буцаах утгын гэрээг мөрдөнө.
 * - DFA-ийн хэмжээг тооцохдоо size_t overflow-ийг шалгана.
 * - Текстийг зүүнээс баруун тийш нэг удаа уншина.
 * - Бүтэн match бүрт emit(start, context) дуудна; дараа нь restart
 *   төлөвөөс үргэлжлүүлж, давхцсан match-ийг алгасахгүй.
 * - Бүх буцах зам дээр өөрийн олгосон санах ойг чөлөөлнө.
 *
 * Бэлтгэл + хайлт: O(256*m+n), emit-ийн өөрийн ажлыг оруулаагүй.
 * Нэмэлт санах ой: O(256*m).
 * main() аль хэдийн -i сонголтын нормчлолыг хийсэн байна.
 */
int search_all(const unsigned char *text, size_t n,
               const unsigned char *pattern, size_t m,
               match_fn emit, void *context)
{
    (void)text;
    (void)n;
    (void)pattern;
    (void)m;
    (void)emit;
    (void)context;
    return SEARCH_NOT_IMPLEMENTED;
}
