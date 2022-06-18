// #include "../headers/layer.h"
// #include "../headers/bbox.h"
// #include <cairo.h>

// int draw_layer(layer * layerToDraw) {
//     if (layerToDraw->layerType == VECTOR_LAYER) {
//         return draw_vector_layer(layerToDraw);
//     } else {
        
//         return 1;
//     }
// }


// int draw_vector_layer(cairo_t *cr,layer * layer_to_draw) {
//     cairo_save(cr);
//     color * fill_color = layer_to_draw->fill_color;

//     cairo_set_source_rgba(cr, fill_color->red,fill_color->green,fill_color->blue,fill_color->alpha);
    
//     source_ptr layer_source = layer_to_draw->layer_source;
//     point * next_point;
    
//     while((next_point = get_point_from_source(layer_source)) != NULL) {
//         next_point->x;
//     }
    
//     cairo_restore(cr);
// }