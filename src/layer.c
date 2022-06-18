#include "layer.h"
#include "logging.h"
#include "bbox.h"
#include <cairo.h>
#include <math.h>

int draw_point_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox) { 
    puts("52");
    cairo_save(cr);
    color * stroke_color = layer_to_draw->stroke_color;
    puts("52.5");
    cairo_set_source_rgba(cr, stroke_color->red,stroke_color->green,stroke_color->blue,stroke_color->alpha);
    // cairo_set_source_rgba(cr, 1,1,1,1);
    source_ptr layer_source = layer_to_draw->layer_source;
    puts("52.7");
    point * next_point;
    puts("53");
    uint32_t current_point_index = 0;
    while((next_point = get_point_from_source(layer_source,current_point_index)) != NULL) {
        double png_x = dinterpolateX(0,255,bbox,next_point);
        double png_y = dinterpolateY(0,255,bbox,next_point);
        printf("PLOTTING AT: %f, %f\n",png_x,png_y);

        if (layer_to_draw->fill_color != NULL) {
            color * fill_color = layer_to_draw->fill_color;
            cairo_arc (cr, png_x, png_y, 10, 0, M_PI * 2);
            cairo_set_source_rgba(cr, fill_color->red,fill_color->green,fill_color->blue,fill_color->alpha);
            cairo_fill (cr);
        }

        // cairo_arc(cr, png_x, png_y, 50, 0, 2 * M_PI);
        cairo_arc (cr, png_x, png_y, 10, 0, M_PI * 2);
        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_stroke(cr);



        // Don't know if this is needed here or before.
        // cairo_set_line_width (cr, 1);
        
        // cairo_fill (cr);
        current_point_index++;
    }

    cairo_restore(cr);
}

int draw_vector_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox) {
    puts("51");
    if (layer_to_draw->geometryType == POINT) {
        return draw_point_layer(cr,layer_to_draw, bbox);
    } else {
        log_error("Only point layers are currently supported");
    }
}

int draw_layer(cairo_t *cr, layer * layer_to_draw, bbox * bbox) {
    if (layer_to_draw->layerType == VECTOR_LAYER) {
        return draw_vector_layer(cr,layer_to_draw, bbox);
    } else {
        log_error("Only vector layers are currently supported");
        return 1;
    }
}