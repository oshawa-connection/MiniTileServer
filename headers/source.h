#pragma once
#include "point.h"
#include "bbox.h"
#include <stdint.h>
#include "geometry.h"

typedef enum{
    SQL = 0,
    IN_MEMORY = 1
} source_type;

typedef struct source * source_ptr;

point * get_point_from_source(source_ptr src, uint32_t index);

int source_apply_bbox(source_ptr src, bbox * bboxPtr);

source_ptr create_source(GEOMETRY_TYPE source_geometry_type, source_type store_type);