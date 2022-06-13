#pragma once


enum LAYER_TYPE {
    first,
    second
};


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
    
};