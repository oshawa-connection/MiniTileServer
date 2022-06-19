#include "layer.h"
#include "logging.h"
#include "bbox.h"
#include <cairo.h>
#include <math.h>

int draw_point_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox) { 
    cairo_save(cr);
    color * outline_color = layer_to_draw->outline_color;
    cairo_set_line_width (cr, layer_to_draw->strokeThickness);
    // cairo_set_source_rgba(cr, 1,1,1,1);
    source_ptr layer_source = layer_to_draw->layer_source;
    point * next_point;
    uint32_t current_point_index = 0;
    while((next_point = get_point_from_source(layer_source,current_point_index)) != NULL) {
        double png_x = dinterpolateX(0,255,bbox,next_point);
        double png_y = dinterpolateY(0,255,bbox,next_point);
        
        printf("PLOTTING AT: %f, %f\n",png_x,png_y);

        // If there is a fill, draw it first, then draw the stroke on top of it.
        if (layer_to_draw->fill_color != NULL) {
            color * fill_color = layer_to_draw->fill_color;
            cairo_arc (cr, png_x, png_y, layer_to_draw->size, 0, M_PI * 2);
            cairo_set_source_rgba(cr, fill_color->red,fill_color->green,fill_color->blue,fill_color->alpha);
            cairo_fill (cr);
        }

        // cairo_arc(cr, png_x, png_y, 50, 0, 2 * M_PI);
        
        cairo_arc (cr, png_x, png_y, layer_to_draw->size, 0, M_PI * 2);
        cairo_set_source_rgba(cr, outline_color->red,outline_color->green,outline_color->blue,outline_color->alpha);
        cairo_stroke(cr);



        // Don't know if this is needed here or before.
        
        
        // cairo_fill (cr);
        current_point_index++;
    }

    cairo_restore(cr);
    return 0;
}

int draw_vector_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox) {
    if (layer_to_draw->geometryType == POINT) {
        return draw_point_layer(cr,layer_to_draw, bbox);
    } else {
        log_error("Only point layers are currently supported");
    }
    return 1;
}

int draw_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox) {
    if (layer_to_draw->layerType == VECTOR_LAYER) {
        return draw_vector_layer(cr,layer_to_draw, bbox);
    } else {
        log_error("Only vector layers are currently supported");
        return 1;
    }
}

/**
 * @brief Calculates point at which features will saturate the tile.
 * This would only work assuming a normal distribtion of points and otherwise might result in weird behaviour that the
 * user might get annoyed by.
 * @param layer_to_calc 
 * @return uint32_t 
 */
uint32_t calc_max_number_features_per_tile(layer * layer_to_calc) {
    // layer_to_calc->size
    return 0;
}