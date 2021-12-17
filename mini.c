#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct product{
	int id;
	char desc[53];
	char qty[18];
	char exp[18];
	char price[18];
}product;

void search()
{
    FILE *fpin;
    FILE *fpout;
    product p[500];
    char row[100];
    char *yes = "YES";
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int n;


    fpin    = fopen("Inventory.csv", "r");


    //read input
    while(feof(fpin) == 0)
    {
        fgets(row, 100, fpin);
        token = strtok(row, ",");

        while(token != NULL)
        {
          temp[i++] = token;
          token = strtok(NULL, ",");

        }
        if(strlen(temp[0]) == 7)
        {
            strncpy(temp2, temp[0], 7);
            x=0;
            while(x !=5)
            {
                temp3[x] = temp2[x+1];
                x++;
            }
            p[j].id = atoi(temp3);
        }
        else
        {
            p[j].id = atoi(temp[0]);
        }


        strcpy(p[j].desc,temp[1]);
        strcpy(p[j].qty,temp[2]);
        strcpy(p[j].exp,temp[3]);
        strcpy(p[j].price,temp[4]);
        printf("%s\n", temp[0]);
        j++;
        i = 0;
    }

    fpout = fopen("Inventory.csv", "a");
    fprintf(fpout, "\n%s\n", yes);



}

int main()
{

    search();


    return 0;
}
