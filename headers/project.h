// This probably needs a better name...
#include "color.h"
#include "layer.h"

typedef struct project {
    char ** spatialite_file_path;
    color * background_color;
    layer ** project_layers;
} project;