#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct product{
	int id;
	char *desc;
	char *qty;
	char *exp;
	char *price;
}product;

void add()
{
    FILE *fpin;
    FILE *fpout;
    product p[500];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int newid;
    char newdesc[30];
    char newqty[10];
    char newexp[10];
    char newprice[10];

    fpin    = fopen("Inventory.csv", "r");
    fpout   = fopen("Inventory.csv", "a");

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


        p[j].desc   = temp[1];
        p[j].qty    = temp[2];
        p[j].exp    = temp[3];
        p[j].price  = temp[4];
        j++;
        i = 0;
    }

    printf("ADD MENU\n");
    if(j < 500)
    {
        printf("Product ID: ");
        scanf("%d", &newid);
        printf("Product Description: ");
        scanf("%s", &newdesc);
        printf("Quantity: ");
        scanf("%s", &newqty);
        printf("Exp. Date: ");
        scanf("%s", &newexp);
        printf("Price(PHP): ");
        scanf("%s", &newprice);
    }
    else
    {
        printf("Max Inventory Limit Reached");
    }

    fprintf(fpout, "\n%d,%s,%s,%s,%s", newid, newdesc,newqty,newexp,newprice);

}
void search()
{
FILE *fpin;
    FILE *fpout;
    product p[500];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int n;
    int newid;
    char newdesc[30];
    char newqty[10];
    char newexp[10];
    char newprice[10];

    fpin    = fopen("Inventory.csv", "r");
    fpout   = fopen("Inventory.csv", "a");

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


        p[j].desc   = temp[1];
        p[j].qty    = temp[2];
        p[j].exp    = temp[3];
        p[j].price  = temp[4];
        j++;
        i = 0;
    }
    printf("SEARCH MENU\n");
    printf("Enter the ID number of Product you want to search: \n");
	scanf("%d", &n);

    for(x = 0; x < j ; x++)
    {
        if(p[x].id == n)
		{
			printf("Product found! \n");
			printf("Product ID: %d\nProduct Description: %s\nQuantity: %s\nExp.date: %s\nPrice: %s\n", p[x].id,p[x].desc,p[x].qty,p[x].exp,p[x].price);
			break;
		}
    }

    printf("ERROR! Product not on the list! \n");


}
void view()
{
FILE *fpin;
    FILE *fpout;
    product p[500];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int newid;
    char newdesc[30];
    char newqty[10];
    char newexp[10];
    char newprice[10];

    fpin    = fopen("Inventory.csv", "r");
    fpout   = fopen("Inventory.csv", "a");

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


        p[j].desc   = temp[1];
        p[j].qty    = temp[2];
        p[j].exp    = temp[3];
        p[j].price  = temp[4];
        j++;
        i = 0;
    }
}
void update()
{
FILE *fpin;
    FILE *fpout;
    product p[500];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int newid;
    char newdesc[30];
    char newqty[10];
    char newexp[10];
    char newprice[10];

    fpin    = fopen("Inventory.csv", "r");
    fpout   = fopen("Inventory.csv", "w");

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


        p[j].desc   = temp[1];
        p[j].qty    = temp[2];
        p[j].exp    = temp[3];
        p[j].price  = temp[4];
        j++;
        i = 0;
    }


}
int main()
{
char choice;


	printf("MAIN MENU \n");
    printf("[A] Create Inventory Item \n");
    printf("[B] Update Inventory Item \n");
    printf("[C] View Inventory List \n");
    printf("[D] Search Inventory List \n");
    printf("[X] Exit Program \n");

    printf("\nPlease input your choice: \n");
    scanf("%c", &choice);


	switch(choice)
	{
		case 'A':
		system("cls");
		add();
		break;

		case 'B':
		system("cls");
		update();
		break;

		case 'C':
		system("cls");
		view();
		break;

		case 'D':
		system("cls");
		search();
		break;

		case 'X':
		printf("Exiting Program \n");
		break;

		default: printf("Wrong info. \n");
        break;

	}

    return 0;
}
