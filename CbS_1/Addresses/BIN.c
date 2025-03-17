#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 35

void calculation(int count, char *ip[], char* fin);
void writing(char *ip);

int main(int argc, char *argv[])
{
    char *fin = malloc(35*sizeof(char));

    if(fin) {
        calculation(argc, argv, fin);
        writing(fin);

        free(fin);
    }

    return 0;
}

void calculation(int count, char *ip[], char* fin) {
    int isError = 0;
    int k=0;

    if (count == 2)
    {
        long mas[4];
        char *buf = strtok(ip[1], ".");

        for (int i = 0; i < 4 && buf != NULL && isError == 0; i++, buf = strtok(NULL, "."))
        {
            char *time;
            mas[i] = strtol(buf, &time, 10);
            if (strlen(time) != 0 || mas[i] > 255)
                isError = 1;
        }

        if (isError == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                char res[8] = {0};
                for (int j = 7; j >= 0 && mas[i] > 0; j--)
                {
                    res[j] = mas[i] % 2;
                    mas[i] /= 2;
                }
                for (int j = 0; j < 8; j++) {
                    fin[k++]=res[j];
                }
                if (i != 3)
                    fin[k++]='.';
            }
        }
    }
    else
    {
        isError = 1;
    }
}

void writing(char *ip) {
    char *filename = "res.txt";
    FILE *fp = fopen(filename, "a");
    if(fp) {
        for(int i=0;i<MAX;i++) {
            if(ip[i]=='.') {
                fprintf(fp,".");
            }
            else{
                fprintf(fp,"%d",ip[i]);
            }
        }
        fprintf(fp,"\n");
        fclose(fp);
    }
}