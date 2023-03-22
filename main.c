#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE* file;
    file = fopen("test.txt", "r");

    int i, ind_open_bracket = 0, ind_close_bracket = 0, ind_last_num_elm = 0,
           ind_first_num_elm = 0, ind_second_num_elm = 0;
    int l = 0, c = 0, e = 0, error = 0;
int newflag=0;
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

    char a[l], b[6] = "circle";
    file = fopen("test.txt", "r");
    while (fgets(a, l + 1, file)) {
        printf("%s", a);

        for (i = 0; i < 7; i++) {
            if (a[i] != b[i] && i < 6) {
                printf("Error at column %d: expected 'circle'\n", i);
                error = 1;
                break;
                ;
            }
            ind_open_bracket = i;
        }

        for (i = 0; i < l; i++) {
            if (a[i] == ')') {
                ind_close_bracket = i;
            } else {
                ind_close_bracket = l - 1;
            }
        }

        for (i = ind_open_bracket + 1; a[i] != ' '; i++) {
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
                ind_first_num_elm = i;
            } else {
                break;
            }
        }
	for(i=ind_first_num_elm+2;i<20;i++){
		if(a[i]=='.'){
			if(newflag==0){
				newflag=1;

				}
			else{
				printf("Error at column %d",a[i]-32);
				error=1;
				printf("\n");
				break; 
				}}}
        for (i = ind_first_num_elm + 2; a[i] != ','; i++) {
	    
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
                ind_second_num_elm = i;
            } else {
                break;
            }
        }

        for (i = ind_second_num_elm + 3; i < ind_close_bracket; i++) {
            if (error == 0) {
                if ((isdigit(a[i]) == 0 && a[i] != '.') || a[i]=='0') {
                    if (a[i] == ')' || a[i] == '(' || a[i] == ' ') {
                        break;
                    }
                    error = 1;
                    printf("Error at column %d: expected '<double>'\n", i);
                    break;
                }
                ind_last_num_elm = i;
            } else {
                break;
            }
        }

        for (i = ind_last_num_elm + 1; i < l; i++) {
            if (error == 0) {
                if (a[i] != ')') {
                    error = 1;
                    printf("Error at column %d: expected ')'\n", i);
                    break;
                } else {
                    ind_close_bracket = i;
                    break;
                }
            } else {
                break;
            }
        }

        for (i = ind_close_bracket + 1; i < l; i++) {
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