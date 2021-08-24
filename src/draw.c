#include <cairo.h>
#include <math.h>
#include <stdio.h>
#include "../headers/point.h"

#define radius 2;
//return pointer to cairo surface
void cairoSetup() {

}

void draw_points(cairo_t *cr, point * points) {
    
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_arc (cr, 250, 250, 50, 0, M_PI * 2);
    cairo_arc (cr, 500, 500, 50, 0, M_PI * 2);
    cairo_set_line_width (cr, 1);
    cairo_fill (cr);
}