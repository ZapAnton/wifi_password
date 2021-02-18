#include "project_info.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SSID_LENGTH 32

void print_version(void) { printf("wifi_password %s\n", PROJECT_VERSION); }

void print_help(void) {
    printf("%s\n\n"
           "usage: wifi_password [options]\n\n"
           "arguments:\n"
           "-h, --help            show this help message and exit\n"
           "-v, --version         show version number and exit\n",
           PROJECT_DESCRIPTION);
}

void get_ssid(char *ssid_str) {
    FILE *nmcli_process = popen(
        "nmcli -t -f active,ssid dev wifi | grep yes | sed 's/yes://'", "r");
    if (nmcli_process == NULL) {
        fprintf(stderr, "Failed to open nmcli process");
        exit(1);
    }
    const char *const fgets_result =
        fgets(ssid_str, MAX_SSID_LENGTH, nmcli_process);
    // TODO: Remove the newline from fgets
    if (fgets_result == NULL) {
        fprintf(stderr, "Failed to read from nmcli process");
        exit(1);
    }
    pclose(nmcli_process);
}

void fetch_wifi(void) {
    char ssid[MAX_SSID_LENGTH] = {0};
    get_ssid(ssid);
    puts(ssid);
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
    fetch_wifi();
    return 0;
}
