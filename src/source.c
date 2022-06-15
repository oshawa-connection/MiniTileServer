#include "point.h"
#include "source.h"
#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include "logging.h"
#include "bbox.h"
#include <stddef.h>

static u_int16_t source_id = 0;

struct source {
    u_int16_t id;
    GEOMETRY_TYPE source_geometry_type;
    source_type * store_type;
    long number_of_points;
    point ** points;
} source;


source_ptr create_source(GEOMETRY_TYPE source_geometry_type, source_type * store_type) {
    source_ptr new_source = (source_ptr) malloc(sizeof(source));
    if (new_source == NULL) {
        log_fatal("FAILED TO ALLOCATE SUFFICIENT MEMORY FOR SOURCE");
        return 0;
    }
    new_source->id = source_id += 1;
    new_source->source_geometry_type = source_geometry_type;
    new_source->store_type = store_type;
    new_source->number_of_points = 0;
    
}

void destroy_source(source_ptr src) {
    if(src->number_of_points != 0) {
        free(src->points);
    }
    free(src);
    src = NULL;
}

point * get_next_point_from_source(source_ptr src) {
    if (src->source_geometry_type != POINT) {
        
        
        return 0;
    }
    if (src->store_type == IN_MEMORY) {

    } else {
        log_error("Only in memory sources are currently supported.");
        return 0;
    }
}


point * get_next_random_point() {

}

int apply_bbox(bbox * bboxPtr) {

}

int initialise_source_store(source_ptr src) {

    if (src->store_type == IN_MEMORY) {
        initialise_in_memory_store(src);

    } else {
        log_error("Only in memory stores are implemented");
        return EXIT_FAILURE;
    }
}

int initialise_in_memory_store(source_ptr src) {
    if (src->source_geometry_type == POINT) {
        const uint32_t NUMBER_OF_FEATURES = 1000;
        src->points = malloc(sizeof(point) * NUMBER_OF_FEATURES);
        
        point * new_point = NULL;

        for(int i =0; i<100;i++) {
            
            double rand_x = (double)(rand() % 1001);
            double rand_y = (double)(rand() % 1001);
            new_point = create_new_point(rand_x,rand_y);
            src->points[i] = new_point;
        }
    } else {
        log_error("Only point geometries are currently implemented");
    }
}