#include <stdio.h>
#include <stdlib.h>
#include "layer.h"
#include "source.h"
#include <cairo.h>
#include <time.h>
#include "bbox.h"
#include "color.h"
#include "geometry.h"

const char * output_file_name = "myexample.png";

int main(int argc, char *argv[]) {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    bbox * bboxPtr = create_bbox_ptr(0,1000,0,1000);
    cairo_surface_t *surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 255, 255);
    cairo_t *cr = cairo_create (surface);
    // Set background to white 
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_paint(cr);

    
    source_ptr some_source = create_source(POINT,IN_MEMORY);
    source_apply_bbox(some_source,bboxPtr);
    
    layer some_layer = {
        .fill_color=create_color(0,0,255,1),
        .geometryType=POINT,
        .layer_source=some_source,
        .layerType=VECTOR_LAYER,
        .outline_color=create_color(245, 245, 66,1),
        .size=10,
        .strokeThickness=1
    };
    
    int x = draw_layer(cr, &some_layer, bboxPtr);

    cairo_fill(cr);
    cairo_surface_write_to_png(surface,output_file_name);
    cairo_destroy (cr);
    cairo_surface_destroy(surface);
    printf("Wrote output png to %s",output_file_name);
    return EXIT_SUCCESS;
}


// #include <math.h>

// #define WIDTH 700
// #define HEIGHT 500

// int main() {
//   // Initialize cairo.
//   cairo_surface_t *surface =
//     cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
// 				WIDTH, HEIGHT);
//   cairo_t *cr = cairo_create (surface);

//   // Fill the entire surface with red.
//   cairo_set_source_rgb(cr, 1, 0, 0);
//   cairo_rectangle(cr, 0, 0, WIDTH, HEIGHT);
//   cairo_fill(cr);
  
//   // Make a green rectangle.
//   cairo_rectangle(cr, 100, 100, 100, 100);
//   cairo_set_source_rgb(cr, 0, 1, 0);
//   cairo_fill(cr);

//   // Put a yellow border on the rectangle.
//   cairo_rectangle(cr, 100, 100, 100, 100);
//   cairo_set_source_rgb(cr, 1, 1, 0);
//   cairo_stroke(cr);

//   // Draw a blue triangle.
//   cairo_move_to(cr, 300, 100);
//   cairo_line_to(cr, 400, 100);
//   cairo_line_to(cr, 400, 200);
//   cairo_close_path(cr);
//   cairo_set_source_rgb(cr, 0, 0, 1);
//   cairo_stroke(cr);

//   // Draw a black circle.
//   cairo_arc(cr, 150, 350, 50, 0, 2 * M_PI);
//   cairo_set_source_rgb(cr, 0, 0, 0);
//   cairo_stroke(cr);

//   // Draw a thick magenta line.
//   cairo_set_line_width(cr, 15);
//   cairo_move_to(cr, 300, 350);
//   cairo_rel_line_to(cr, 100, 0);
//   cairo_set_source_rgb(cr, 0.54, 0, 0.54);
//   cairo_stroke(cr);

//   // Write some text in white, blending with the background.
//   cairo_set_font_size(cr, 48);
//   cairo_move_to(cr, 500, 150);
//   cairo_set_source_rgba(cr, 1, 1, 1, 0.5);
//   cairo_show_text(cr, "Cairo");
  
//   cairo_surface_write_to_png(surface, "cairo.png");
//       cairo_destroy (cr);
//     cairo_surface_destroy(surface);
// }