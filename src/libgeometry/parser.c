#include <libgeometry/parser.h>
#define M_PI 3.14

float pcircle(float rad)
{
    return 2 * M_PI * rad;
}

float acircle(float rad)
{
    return M_PI * rad * rad;
}

void Exception(char* string)
{
    int length = strlen(string);
    char* end;
    char* start;
    for (int i = 0; i < length; i++) {
        if (string[i] == ')') {
            end = &string[i];
        }
        if (string[i] == '(') {
            start = &string[i];
        }
    }
    if (end == NULL) {
        printf("Error at column %d: expected ')' \n", length - 1);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < strlen(end); i++) {
        if (!(end[i + 1] == ' ' || end[i + 1] == '\000')) {
            printf("Error at column %d: unexpected token\n", length);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < end - start; i++) {
        if (!(start[i + 1] == ' ' || start[i + 1] == ',' || start[i + 1] == '.'
              || start[i + 1] == ')'
              || ((int)start[i + 1] >= (int)'0'
                  && (int)start[i + 1] <= (int)'9'))) {
            printf("Error at column %d: expected '<double>'\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }
}
void parse_start()
{
    char string[64];
    do {
        gets(string);
        if ((strstr(string, "circle(") != NULL)) {
            point a;
            double rad = 0;
            Exception(string);
            sscanf(string, "circle(%lf %lf, %lf)", &a.x, &a.y, &rad);

            if (rad < 0) {
                puts("Radius cannot be negative\n");
            }
            printf("Perimetr: %.3f, Area: %.3f\n", pcircle(rad), acircle(rad));
        } else {
            if (strcmp(string, "q")) {
                printf("Error at column 0: expected 'circle', 'triangle' or "
                       "'polygon' \n");
            }
        }
    } while (strcmp(string, "q"));
}