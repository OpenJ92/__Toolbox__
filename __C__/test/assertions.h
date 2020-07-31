#ifndef ASSERT_H
#define ASSERT_H

#include <assert.h>
#define EQ(a, b, msg) assert((a) == (b) && msg)
#define LEQ(a, b, msg) assert((a) <= (b) && msg)
#define GEQ(a, b, msg) assert((a) >= (b) && msg)

#endif
