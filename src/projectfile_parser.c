#include "toml.h"
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE * fp = fopen("sample.toml", "r");
    printf("ERROR NO: %d\n",errno);
    if (!fp) {
        error("cannot open sample.toml - ", strerror(errno));
    }
    return EXIT_SUCCESS;
}
