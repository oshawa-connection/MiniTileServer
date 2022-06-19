#pragma once
#include "./color.h"
#include "geometry.h"
#include "source.h"
#include "bbox.h"
#include <cairo.h>

typedef enum LAYER_TYPE {
    VECTOR_LAYER,
    RASTER_LAYER
} LAYER_TYPE;

/**
 * @brief Used during parsing.
 * 
 */
typedef struct layerConfig {
    char * layerType;
    char * geometryType;
    char * outline_color;
    char * fill_color;
    float thickness;
} layerConfig;

/**
 * @brief 
 * @details Something
 */
typedef struct layer {
    LAYER_TYPE layerType;
    GEOMETRY_TYPE geometryType;
    color * fill_color;
    color * outline_color;
    float strokeThickness;
    int size;
    source_ptr layer_source;
} layer;

int draw_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox);