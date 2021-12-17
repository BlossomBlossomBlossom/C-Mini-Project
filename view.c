#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 0
#define false 1

FILE *f;  // file pointer
struct Product
{
    int ID;
    char description[30];
    float quantity;
    char exp_date[15];
    float price;

};

struct Product prod[500]; //maximum array elements.
int count = 0;


int write_file()
{
    int i;
    f = fopen("inventory.csv","w");
    if (f == NULL)
        return -1;
    fprintf(f,"%d\n", count);
    for(i = 0; 1 < count; ++i)
    {
        fprintf(f, "%d",prod[i].ID);
        fputs(prod[i].description, f);
        fprintf(f, "%f", prod[i].quantity);
        fputs(prod[i].exp_date, f);
        fprintf(f, "%f", prod[i].price);
    }
    fclose(f);
    return 0;
}

int read_file()
{
    int n = 0;
    int i;
    fopen("inventory.csv","r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; ++i)
    {
        fscanf(f, "%d", &prod[i].ID);
        fgets(prod[i].description, 30, f);
        fscanf(f, "%f", &prod[i].quantity);
        fgets(prod[i].exp_date, 15, f);
        fscanf(f, "%f", &prod[i].price);
    }
    fclose(f);
    return n;
}

void view()
{
    system("clear");
    int i;
    char choice;
    count = read_file();
    if (count < 0)
    {
        printf("\n");
        printf("\n");
        printf("\t\t\t     --Inventory List empty--\n");
        printf("\t\t\t  --Please add products first--");
        printf("\n");
        printf("\n");
        printf("[1] Main Menu\n");
        printf("[2] Exit Program\n");
        printf("\n");
        b:
        printf("\t Please input choice: ");
        scanf("%s", &choice);
        if (choice == '1')
        {
            menu(); // function for main menu
        }
        else if(choice == '2')
        {
            Exit(); // function for exit program
        }
        else
        {
            printf("\t\t       Invalid Input!\n");
            printf("\t\t Please choose 1 or 2 only\n");
            goto b;
        }
    }
    else
    {
        printf("\n");
        printf("\t  ===============================================\n");
        printf("\t ||            -- INVENTORY LIST --             ||\n");
        printf("\t  ===============================================\n");
        printf("  --------------------------------------------------------------\n");
        printf("  |# |Prod_ID|     Prod_Name    |Prod_Quant|Exp_Date|Prod_Price|\n");
        printf("  --------------------------------------------------------------\n");
        for(i = 0; i < count; i++)
        {
            printf("%d   %d    %-30s   %f    %-15s   %f", i+1, prod[i].ID,
            prod[i].description, prod[i].quantity, prod[i].exp_date, prod[i].price);
        }
        printf("\n");
        printf("\n");
        printf("[1] Main Menu\n");
        printf("[2] Exit Program\n");
        printf("\n");
        c:
        printf("\t Please input choice: ");
        scanf("%s", &choice);
        if (choice == '1')
        {
            menu(); // function for main menu
        }
        else if(choice == '2')
        {
            Exit(); // function for exit program
        }
        else
        {
            printf("\t\t       Invalid Input!\n");
            printf("\t\t Please choose 1 or 2 only\n");
            goto c;
        }
    }
    return 0;
}

void Exit()
{
    system("clear");
    printf("\n");
    printf("\n");
    printf("\t ===============================================\n");
    printf("\t |            -- End of Program --             |\n");
    printf("\t |               -- Thank You --               |\n");
    printf("\t ===============================================\n");
    return 0;
}

int main()
{
    system("clear");
    int choice;
    view();

    return 0;
}
