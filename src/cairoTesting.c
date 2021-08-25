#include <cairo.h>
#include <math.h>
#include "../headers/bbox.h"
#include <stdio.h>
#include "../headers/point.h"
#include <stdlib.h>
#include <time.h>

#define DEBUG

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
    cairo_arc (cr, png_x, png_y, 5, 0, M_PI * 2);

    cairo_set_line_width (cr, 1);
    cairo_fill (cr);
}

// We will need to store lots of points in memory rather than in DB.
// Otherwise we will have to query each time.
// Maybe with an RTree? ;-)
int main (int argc, char *argv[]) {

    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    bbox * bboxPtr = create_bbox_ptr(0,1000,0,1000);
    point some_point = {234.0,500};

    cairo_surface_t *surface =
        cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 255, 255);
    cairo_t *cr =
        cairo_create (surface);

#ifdef DEBUG
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_paint(cr);
#endif
    cairo_set_source_rgb (cr, 0, 0, 0);
    
    pointCollection * some_collection = create_point_collection();
    
    struct point * new_point = NULL;

    for(int i =0; i<100;i++) {
        
        double rand_x = (double)(rand() % 1001);
        double rand_y = (double)(rand() % 1001);
        new_point = create_new_point(rand_x,rand_y);
        add_point_to_collection(some_collection,new_point);
    }

    point * found_point = NULL;
    for (int i = 0;i<10;i++) {
        found_point = get_point_from_collection(some_collection,i);
        drawPoint(found_point,bboxPtr,cr);
    }
    


    cairo_destroy (cr);
    cairo_surface_write_to_png (surface, "hello.png");
    cairo_surface_destroy (surface);
    printf("GOODBYE\n");
    return 0;
}