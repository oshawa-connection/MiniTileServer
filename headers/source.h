#include "point.h"

typedef enum{
    SQL = 0,
    IN_MEMORY = 1
} source_type;

typedef struct source * source_ptr;

point * get_next_point_from_source(source_ptr src);