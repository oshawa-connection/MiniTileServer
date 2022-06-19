// This probably needs a better name...
#include "color.h"
#include "layer.h"

typedef struct project {
    color * background_color;
    layer ** project_layers;
} project;