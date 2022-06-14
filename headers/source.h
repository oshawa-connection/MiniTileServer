#include "point.h"

typedef enum source_type{
    SQL = 0,
    IN_MEMORY = 1
} source_type;

typedef struct source * sourcePtr;


point * get_next_point_from_source(sourcePtr src);