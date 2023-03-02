#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int e = 0, c = 0, l = 0, error = 0;
    FILE* file;
    file = fopen("test.txt", "r");
	 while (1) {
        e = fgetc(file);
        if (e == EOF) {
            if (feof(file) != 0) {
                break;
            }
        }
        c++;
    }
    l = c;
    fclose(file);
    int i, bracket1 = 0, bracket2 = 0,num1 = 0, num2 = 0, lastnum = 0;
    char a[l], b[6] = "circle";
    file = fopen("test.txt", "r");
    while (fgets(a, l + 1, file)) {
        printf("%s", a);
        for (i = 0; i < 7; i++) {
            if (a[i] != b[i] && i < 6) {
                printf("Error at column %d: expected 'circle'\n", i);
                error = 1;
                break;
            }
            bracket1 = i;
        }
        for (i = 0; i < l; i++) {
            if (a[i] == ')') {
                bracket2 = i;
            } else {
                bracket2 = l - 1;
            }
        }
        for (i = bracket1 + 1; a[i] != ' '; i++) {
            if (error == 0) {
                if (a[i] == ',') {
                    error = 1;
                    printf("Error at column %d: expected '<space>' and "
                           "'<double>'\n",
                           i);
                    break;
                }
                if (isdigit(a[i]) == 0 && a[i] != '.') {
                    error = 1;
                    printf("Error at column %d: expected '<double>'\n", i);
                    break;
                }
                num1 = i;
            } else {
                break;
            }
        }
        for (i = num1 + 2; a[i] != ','; i++) {
            if (error == 0) {
                if (a[i] == ')') {
                    error = 1;
                    printf("Error at column %d: expected ',' and '<double>'\n",
                           i);
                    break;
                }
                if (isdigit(a[i]) == 0 && a[i] != '.') {
                    error = 1;
                    printf("Error at column %d: expected '<double>'\n", i);
                    break;
                }
                num2 = i;
            } else {
                break;
            }
        }
        for (i = num2 + 3; i < bracket2; i++) {
            if (error == 0) {
                if ((isdigit(a[i]) == 0 && a[i] != '.') || a[i]=='0') {
                    if (a[i] == ')' || a[i] == '(' || a[i] == ' ') {
                        break;
                    }
                    error = 1;
                    printf("Error at column %d: expected '<double>'\n", i);
                    break;
                }
                lastnum = i;
            } else {
                break;
            }
        }
        for (i = lastnum + 1; i < l; i++) {
            if (error == 0) {
                if (a[i] != ')') {
                    error = 1;
                    printf("Error at column %d: expected ')'\n", i);
                    break;
                } else {
                    bracket2 = i;
                    break;
                }
            } else {
                break;
            }
        }
        for (i = bracket2 + 1; i < l; i++) {
            if (error == 0) {
                if (a[i] == '\n') {
                    break;
                }
                if (a[i] != ' ') {
                    error = 1;
                    printf("Error at column %d: unexpected token\n", i);
                    break;
                }
            } else {
                break;
            }
        }
        if (error == 0) {
            printf("No Errors\n");
        }
        error = 0;
    }
    return 0;
}