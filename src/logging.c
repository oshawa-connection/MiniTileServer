#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "logging.h"

void log_fatal(char * message) {
    time_t rawtime;
    time ( &rawtime );
    struct tm * timeinfo = localtime ( &rawtime );
    fprintf(stderr,"%s: FATAL:%s",asctime (timeinfo),message); 
}


void log_error(char * message) {
    time_t rawtime;
    time ( &rawtime );
    struct tm * timeinfo = localtime ( &rawtime );
    fprintf(stderr,"%s: ERROR:%s",asctime (timeinfo),message); 
}

void log_warning(char * message) {
    time_t rawtime;
    time ( &rawtime );
    struct tm * timeinfo = localtime ( &rawtime );
    fprintf(stderr,"%s: WARNING:%s",asctime (timeinfo),message);  
    
}


void log_message(char * message)  {
    time_t rawtime;
    time ( &rawtime );
    struct tm * timeinfo = localtime ( &rawtime );
    fprintf(stdout,"%s: MESSAGE:%s",asctime (timeinfo),message);   
}