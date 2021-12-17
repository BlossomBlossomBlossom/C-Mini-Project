#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct product{
	int id;
	char desc[53];
	char qty[18];
	char exp[18];
	char price[18];
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
    char newdesc[53];
    char newqty[18];
    char newexp[18];
    char newprice[18];

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


        strcpy(p[j].desc,   temp[1]);
        strcpy(p[j].qty,    temp[2]);
        strcpy(p[j].exp,    temp[3]);
        strcpy(p[j].price,  temp[4]);
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
    char newdesc[53];
    char newqty[18];
    char newexp[18];
    char newprice[18];

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


        strcpy(p[j].desc,temp[1]);
        strcpy(p[j].qty,temp[2]);
        strcpy(p[j].exp,temp[3]);
        strcpy(p[j].price,temp[4]);
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
    char newdesc[53];
    char newqty[18];
    char newexp[18];
    char newprice[18];

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


        strcpy(p[j].desc,   temp[1]);
        strcpy(p[j].qty,    temp[2]);
        strcpy(p[j].exp,    temp[3]);
        strcpy(p[j].price,  temp[4]);
        j++;
        i = 0;
    }

    if (j <= 0)
    {
        printf("\n");
        printf("\n");
        printf("\t\t\t     --Inventory List empty--\n");
        printf("\t\t\t  --Please add products first--");
        printf("\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("\t  ===============================================\n");
        printf("\t ||            -- INVENTORY LIST --             ||\n");
        printf("\t  ===============================================\n");
        printf("--------------------------------------------------------------\n");
        printf("|#|Prod_ID|                Prod_Name               |Quantity          |Exp_Date          |Price\n");
        printf("--------------------------------------------------------------\n");
        i=1;
        for(x = 0; x < j; x++)
        {
            printf("|%d", i++);
            printf("|%d  ", p[x].id);
            printf("|%s",   p[x].desc);
            for(int y = 0; y< 40-strlen(p[x].desc);y++)
                printf(" ");
            printf("|%s",   p[x].qty);
            for(int y = 0; y< 18-strlen(p[x].qty);y++)
                printf(" ");
            printf("|%s",   p[x].exp);
            for(int y = 0; y< 18-strlen(p[x].exp);y++)
                printf(" ");
            printf("|%s",   p[x].price);
        }
        printf("\n");
        printf("\n");
        printf("[1] Main Menu\n");
        printf("[2] Exit Program\n");
        printf("\n");

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
    char ch;
    int i = 0;
    int j = 0;
    int x = 0;
    int id = 0;
    int newid;
    char newdesc[53];
    char newqty[18];
    char newexp[18];
    char newprice[18];

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

        strcpy(p[j].desc,   temp[1]);
        strcpy(p[j].qty,    temp[2]);
        strcpy(p[j].exp,    temp[3]);
        strcpy(p[j].price,  temp[4]);
        j++;
        i = 0;
    }

    printf("Enter ID no. to Update : ");
	scanf("%d", &id);

	for(x = 0; x < j ; x++)
    {
        if(p[x].id == id)
		{

			printf("Would you like to update product ID [Y/N]?");
			scanf(" %c", &ch);
			if(ch == 'y' || ch == 'Y'){

				printf("Enter New ID: ");
				scanf("%d", &p[x].id);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
			}

			printf("Would you like to update product Description [Y/N]?");
			scanf(" %c", &ch);

			if(ch == 'y' || ch == 'Y'){

				printf("Enter New Product Description: ");
				scanf("%s", &p[x].desc);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
			}

			printf("Would you like to update product quantity [Y/N]?");
			scanf(" %c", &ch);
			if(ch == 'y' || ch == 'Y'){
				printf("Enter New Quantity: ");
				scanf("%s,", &p[x].qty);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
			}

			printf("Would you like to update product date [Y/N]?");
			scanf(" %c", &ch);
			if(ch == 'y' || ch == 'Y'){
				printf("Enter New Expiration Date (yyyy-mm-dd): ");

				scanf("%s", &p[x].exp);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
			}

			printf("Would you like to update product price [Y/N]?");
			scanf(" %c", &ch);
			if(ch == 'y' || ch == 'Y'){

				printf("Enter New Price (Php): ");
				scanf("%s,\n", &p[x].price);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
			}
		}
    }

    fpout   = fopen("Inventory.csv", "w");
    for(x = 0; x < j ; x++)
    {
        fprintf(fpout, "%d,%s,%s,%s,%s",p[x].id, p[x].desc, p[x].qty, p[x].exp, p[x].price );
    }

    printf("Updated!");



}
int main()
{
char choice;

    do
    {
   // system("cls");
	printf("MAIN MENU \n");
    printf("[A] Create Inventory Item \n");
    printf("[B] Update Inventory Item \n");
    printf("[C] View Inventory List \n");
    printf("[D] Search Inventory List \n");
    printf("[X] Exit Program \n");

    printf("\nPlease input your choice: \n");
    scanf(" %c", &choice);

    if(toupper(choice) == 'A')
    {
        system("cls");
        add();
    }
    else if(toupper(choice) == 'B')
    {
        system("cls");
        update();
    }
    else if(toupper(choice) == 'C')
    {
        system("cls");
        view();
    }
    else if(toupper(choice) == 'D')
    {
        system("cls");
        search();
    }
    else if(toupper(choice) == 'X')
    {
        system("cls");
        printf("\t===============================================\n");
        printf("\t||          -- End of Program --             ||\n");
        printf("\t||             -- Thank You --               ||\n");
        printf("\t===============================================\n");
        getch();
        choice = 'X';
    }
    else
    {
        printf("Wrong Input. Please select valid inputs only");
        getch();
    }

	}while(choice != 'X');

    return 0;
}
