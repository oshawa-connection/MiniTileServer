#pragma once
#include "./color.h"
#include "geometry.h"
#include "source.h"

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
    char * outlineColor;
    char * fillColor;
    float thickness;
};

/**
 * @brief 
 * @details Something
 */
typedef struct layer {
    LAYER_TYPE layerType;
    GEOMETRY_TYPE geometryType;
    color * outlineColor;
    color * fillColor;
    float strokeThickness;
    int size;
    source_ptr layer_source;
} layer;