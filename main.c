#include "project_info.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void print_version(void) { printf("wifi_password %s\n", PROJECT_VERSION); }

void print_help(void) {
    printf("%s\n\n"
           "usage: wifi_password [options]\n\n"
           "arguments:\n"
           "-h, --help            show this help message and exit\n"
           "-v, --version         show version number and exit\n",
           PROJECT_DESCRIPTION);
}

int main(int argc, char **argv) {
    static struct option long_options[] = {
        {"version", no_argument, NULL, 'v'},
        {"help", no_argument, NULL, 'h'},
    };
    int opt_char = 0;
    int option_index = 0;
    while ((opt_char = getopt_long(argc, argv, "hv", long_options,
                                   &option_index)) != -1) {
        switch (opt_char) {
        case 'h':
            print_help();
            exit(0);
        case 'v':
            print_version();
            exit(0);
        }
    }
    return 0;
}
