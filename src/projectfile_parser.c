#include "toml.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const char * project_file_path = "example_projects/first_project/project.toml";
#define PATH_MAX 1000

int main(int argc, char *argv[]) {
    FILE * fp = fopen(project_file_path, "r");
    char errbuf[255];
    if (!fp) {
        printf("ERROR NO: %d\n",errno);
        fprintf(stderr,"Cannot open %s - %s",project_file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    toml_table_t * project_configuration = toml_parse_file(fp, errbuf,sizeof(errbuf));
    if (0 == project_configuration) {
        fprintf(stderr,"Invalid toml file.");
        exit(EXIT_FAILURE);

    }

    toml_table_t* background = toml_table_in(project_configuration, "background");
    if (0 != background) {
        toml_datum_t background_color = toml_string_in(background, "color");
        if (background_color.ok) {
            printf("Background color was: %s\n",background_color.u.s);
            int lineno = toml_key_lineno(project_configuration,"background");
            printf("Line number was: %d\n",lineno);
        }
    }

    
    toml_array_t* layer = toml_array_in(project_configuration, "layer");
    if (0 != layer) {
        puts("Found layer table");
        int number_of_layers = toml_array_nelem(layer);
        for(int layer_index = 0; layer_index < number_of_layers; layer_index++ ) {
            toml_table_t* current_layer = toml_table_at(layer,layer_index);
            
            toml_datum_t layer_name = toml_string_in(current_layer, "name");
            if (layer_name.ok) {
                printf("Layer name is: %s at line %d\n",layer_name.u.s,toml_key_lineno(current_layer,"name"));
                
            } else {
                printf("Layer at line %d did not have a name\n",toml_key_lineno(current_layer,"name"));
                break;
            }
            
            toml_table_t * current_layer_source = toml_table_in(current_layer,"source");
            if (0 == current_layer_source) {
                fprintf(stderr,"");
            }
        }
    }

    return EXIT_SUCCESS;
}
