#include "point.h"
#include "source.h"
#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include "logging.h"


struct source {
    GEOMETRY_TYPE source_geometry_type;
    source_type * type;
    long numberOfFeatures;
    void * features;
} source;


point * get_next_point_from_source(sourcePtr src) {
    if (src->source_geometry_type != POINT) {
        
        
        return 0;
    }
    if (src->type == IN_MEMORY) {

    } else {
        log_error("Only in memory sources are currently supported.");
        return 0;
    }
}


point * get_next_random_point() {

}