#include <cairo.h>
#include <math.h>
#include "../headers/bbox.h"
#include <stdio.h>
#include "../headers/point.h"
#include  <sys/socket.h> 
#include <arpa/inet.h>

// void * myWriterFunction(unsigned char* data, unsigned int length) {

// }


int main (int argc, char *argv[]) {

    int socket_desc;
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	

	return 0;

    // (cairo_write_func_t) myFunction;
    // bbox * bboxPtr = create_bbox_ptr(0,2,0,2);
    // point point = {1,1};

    // destroy_bbox_ptr(bboxPtr);
    // cairo_surface_t *surface =
    //     cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1000, 1000);
    // cairo_t *cr =
    //     cairo_create (surface);

    // cairo_set_source_rgb (cr, 1, 1, 1);
    // cairo_paint(cr);
    // cairo_set_source_rgb (cr, 0, 0, 0);
    // cairo_arc (cr, 250, 250, 50, 0, M_PI * 2);
    // cairo_arc (cr, 500, 500, 50, 0, M_PI * 2);
    // cairo_set_line_width (cr, 1);
    // cairo_fill (cr);
    
    
    // cairo_destroy (cr);
    // cairo_surface_write_to_png (surface, "hello.png");
    // cairo_surface_destroy (surface);
    
}