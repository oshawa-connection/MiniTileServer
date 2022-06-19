#include "point.h"
#include "source.h"
#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include "logging.h"
#include "bbox.h"
#include <stdint.h>


static u_int16_t source_id = 0;

struct source {
    u_int16_t id;
    GEOMETRY_TYPE source_geometry_type;
    source_type store_type;
    long number_of_points;
    point ** points;
} source;


source_ptr create_source(GEOMETRY_TYPE source_geometry_type, source_type store_type) {
    source_ptr new_source = (source_ptr) malloc(sizeof(source));
    if (new_source == NULL) {
        log_fatal("FAILED TO ALLOCATE SUFFICIENT MEMORY FOR SOURCE");
        return 0;
    }
    new_source->id = source_id += 1;
    new_source->source_geometry_type = source_geometry_type;
    new_source->store_type = store_type;
    new_source->number_of_points = 0;
    return new_source;
}

void destroy_source(source_ptr src) {
    if(src->number_of_points != 0) {
        // Todo: loop over and destroy each point
        // destroy_point
        // free(src->points);
    }
    free(src);
    src = NULL;
}

point * get_point_from_source(source_ptr src, uint32_t index) {
    if (src->source_geometry_type != POINT) {
        return 0;
    }
    

    if (src->store_type == IN_MEMORY) {
        if (index >= src->number_of_points) {
            return NULL;
        }
        return src->points[index];
    } else {
        log_error("Only in memory sources are currently supported.");
        return 0;
    }
}


point * get_next_random_point() {

}





int initialise_in_memory_store(source_ptr src, bbox * bboxPtr) {
    if (src->source_geometry_type == POINT) {
        const uint32_t NUMBER_OF_FEATURES = 10;
        src->points = malloc(sizeof(point) * NUMBER_OF_FEATURES);
        
        point * new_point = NULL;

        for(int i = 0; i<NUMBER_OF_FEATURES;i++) {
            double rand_x = (double)(rand()%((int)bboxPtr->max_x - (int)bboxPtr->min_x) + (int)bboxPtr->min_x);
            double rand_y = (double)(rand()%((int)bboxPtr->max_y - (int)bboxPtr->min_y) + (int)bboxPtr->min_y);
            new_point = create_new_point(rand_x,rand_y);
            src->points[i] = new_point;
        }
        src->number_of_points=NUMBER_OF_FEATURES;
    } else {
        log_error("Only point geometries are currently implemented");
        return 1;
    }

    return 0;
}


int source_apply_bbox(source_ptr src, bbox * bboxPtr) {
    if (src->store_type == IN_MEMORY) {
        int result = initialise_in_memory_store(src,bboxPtr);
        return result;

    } else {
        log_error("Only in memory stores are implemented");
        return EXIT_FAILURE;
    }
}