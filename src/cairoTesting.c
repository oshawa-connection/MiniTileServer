#include <cairo.h>
#include <math.h>
#include "../headers/bbox.h"
#include <stdio.h>
#include "../headers/point.h"

int main (int argc, char *argv[]) {

    bbox * bboxPtr = create_bbox_ptr(0,2,0,2);
    point point = {1,1};

    destroy_bbox_ptr(bboxPtr);
    // cairo_surface_t *surface =
    //     cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1000, 1000);
    // cairo_t *cr =
    //     cairo_create (surface);

    // // cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    // // cairo_set_font_size (cr, 32.0);
    // // cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
    // // cairo_move_to (cr, 10.0, 50.0);
    // // cairo_show_text (cr, "Hello, world");
    // cairo_set_source_rgb (cr, 1, 1, 1);
    // cairo_paint(cr);
    // cairo_set_source_rgb (cr, 0, 0, 0);
    // // cairo_move_to (cr, 500, 500);
    // cairo_arc (cr, 250, 250, 50, 0, M_PI * 2);
    // cairo_arc (cr, 500, 500, 50, 0, M_PI * 2);
    // // cairo_line_to (cr, 100, 100);
    // // cairo_move_to (cr, 1, 0);
    // // cairo_line_to (cr, 0, 1);
    // cairo_set_line_width (cr, 1);
    // cairo_fill (cr);
    

    // cairo_destroy (cr);
    // cairo_surface_write_to_png (surface, "hello.png");
    // cairo_surface_destroy (surface);
    return 0;
}