#include <cairo.h>
#include <math.h>
#include "../headers/bbox.h"
#include <stdio.h>
#include "../headers/point.h"



double dinterpolate(double scale_min, double scale_max, double bbox_min,double bbox_max,double value) {
    return (scale_max - scale_min) /(bbox_max - bbox_min) * (value);
}

// // void * myWriterFunction(unsigned char* data, unsigned int length) {

// // }
void drawPoint(point * point, bbox * bbox,cairo_t *cr) {
    // Don't check that point is in bbox.
    // we might need to draw "off screen"
    double png_x = dinterpolate(255,0,bbox->max_x,bbox->min_x,point->x);
    double png_y = dinterpolate(255,0,bbox->max_y,bbox->min_y,point->y);

    cairo_arc (cr, png_x, png_y, 10, 0, M_PI * 2);

}

// We will need to store lots of points in memory rather than in DB.
// Otherwise we will have to query each time.
// Maybe with an RTree? ;-)
int main (int argc, char *argv[]) {

    bbox * bboxPtr = create_bbox_ptr(0,1000,0,1000);
    point point = {500,500};

    cairo_surface_t *surface =
        cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 255, 255);
    cairo_t *cr =
        cairo_create (surface);

    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_set_source_rgb (cr, 0, 0, 0);
    drawPoint(&point,bboxPtr,cr);
    cairo_set_line_width (cr, 1);
    cairo_fill (cr);
    
    
    cairo_destroy (cr);
    cairo_surface_write_to_png (surface, "hello.png");
    cairo_surface_destroy (surface);
    return 0;
}