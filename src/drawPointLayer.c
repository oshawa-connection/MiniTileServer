#include "../headers/layer.h"
#include "../headers/bbox.h"
#include <cairo.h>

int drawPointLayer(layer * layerToDraw) {
    if (layerToDraw->layerType == LAYER_TYPE.vector) {
        return drawVectorLayer(layerToDraw);
    } else {
        
        return 1;
    }
}


int drawVectorLayer(cairo_t *cr,bbox * bbox,layer * layerToDraw) {
    cairo_save(cr);
    cairo_set_source_rgba()
    layerToDraw->fillColor->red
    // cairo_
    cairo_restore(cr);
}