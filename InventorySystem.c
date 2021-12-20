#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct product{
	int id;
	char desc[43];
	char qty[18];
	char exp[18];
	char price[18];
}product;

void add()
{
    FILE *fpin;
    FILE *fpout;
    product p[511];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int newid;
    int flag = 0;
    char newdesc[53];
    char newqty[18];
    char newexp[18];
    char newprice[18];

    fpin    = fopen("Inventory_ST_NoBOM.csv", "r");
    fpout   = fopen("Inventory_ST_NoBOM.csv", "a");

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
        strncpy(p[j].desc, p[j].desc+1, strlen(p[j].desc));
        p[j].desc[strlen(p[j].desc)-1]    = '\0';

        strcpy(p[j].qty,    temp[2]);
        strncpy(p[j].qty, p[j].qty+1, strlen(p[j].qty));
        p[j].qty[strlen(p[j].qty)-1]    = '\0';

        strcpy(p[j].exp,    temp[3]);
        strncpy(p[j].exp, p[j].exp+1, strlen(p[j].exp));
        p[j].exp[strlen(p[j].exp)-1]    = '\0';

        strcpy(p[j].price,  temp[4]);
        strncpy(p[j].price, p[j].price+1, strlen(p[j].price));
        if(p[j].price[strlen(p[j].price) - 1] == '\n')
        {
            p[j].price[strlen(p[j].price)-1]  = '\0';
            p[j].price[strlen(p[j].price)-2]  = '\0';
        }
        else
            p[j].price[strlen(p[j].price)-1]  = '\0';

        j++;
        i = 0;
    }

    printf("ADD MENU\n");
    if(j < 500)
    {
        printf("Product ID: ");
        scanf("%d", &newid);
        for(x = 0; x < j; x++)
        {
            if(newid == p[x].id)
            {
                printf("Product ID Exists");
                getch();
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("Product Description: ");
            scanf("%s", &newdesc);
            printf("Quantity: ");
            scanf("%s", &newqty);
            printf("Exp. Date(yyyy-mm-dd): ");
            scanf("%s", &newexp);
            printf("Price(PHP): ");
            scanf("%s", &newprice);
        }
    }
    else
    {
        printf("Max Inventory Limit Reached");
        flag = 1;
        getch();

    }

    if(flag == 0)
        fprintf(fpout, "\"%d\",\"%s\",\"%s\",\"%s\",\"%s\"\n", newid, newdesc,newqty,newexp,newprice);

    fclose(fpin);
    fclose(fpout);

}
void search()
{
    FILE *fpin;
    product p[511];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int n;
    int flag = 0;

    fpin    = fopen("Inventory_ST_NoBOM.csv", "r");

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
        strncpy(p[j].desc, p[j].desc+1, strlen(p[j].desc));
        p[j].desc[strlen(p[j].desc)-1]    = '\0';

        strcpy(p[j].qty,    temp[2]);
        strncpy(p[j].qty, p[j].qty+1, strlen(p[j].qty));
        p[j].qty[strlen(p[j].qty)-1]    = '\0';

        strcpy(p[j].exp,    temp[3]);
        strncpy(p[j].exp, p[j].exp+1, strlen(p[j].exp));
        p[j].exp[strlen(p[j].exp)-1]    = '\0';

        strcpy(p[j].price,  temp[4]);
        strncpy(p[j].price, p[j].price+1, strlen(p[j].price));
        if(p[j].price[strlen(p[j].price) - 1] == '\n')
        {
            p[j].price[strlen(p[j].price)-1]  = '\0';
            p[j].price[strlen(p[j].price)-2]  = '\0';
        }
        else
            p[j].price[strlen(p[j].price)-1]  = '\0';

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
			getch();
			flag = 1;
		}
    }

    if(flag == 0)
    {
        printf("ERROR! Product not on the list! \n");
        getch();
    }


fclose(fpin);
}
void view()
{
    FILE *fpin;
    product p[511];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;

    fpin    = fopen("Inventory_ST_NoBOM.csv", "r");

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
        strncpy(p[j].desc, p[j].desc+1, strlen(p[j].desc));
        p[j].desc[strlen(p[j].desc)-1]    = '\0';

        strcpy(p[j].qty,    temp[2]);
        strncpy(p[j].qty, p[j].qty+1, strlen(p[j].qty));
        p[j].qty[strlen(p[j].qty)-1]    = '\0';

        strcpy(p[j].exp,    temp[3]);
        strncpy(p[j].exp, p[j].exp+1, strlen(p[j].exp));
        p[j].exp[strlen(p[j].exp)-1]    = '\0';

        strcpy(p[j].price,  temp[4]);
        strncpy(p[j].price, p[j].price+1, strlen(p[j].price));
        if(p[j].price[strlen(p[j].price) - 1] == '\n')
        {
            p[j].price[strlen(p[j].price)-1]  = '\0';
            p[j].price[strlen(p[j].price)-2]  = '\0';
        }
        else
            p[j].price[strlen(p[j].price)-1]  = '\0';

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
            printf("|%s\n",   p[x].price);
        }
        printf("\n");
        printf("\n");
        printf("Press Any key to return to Main menu\n");

        getch();

    }

    fclose(fpin);
}
int checkDate(char date[])
{
	int digit = 0;
	int hyphen = 0;
	int i=0;
	int j = 0;
	int k;
	int l;
	int year =0;
	int month=0;
	int day=0;
	for (i = 0; date[i] != '\0'; i++)
    {
        if (isdigit(date[i]) != 0)
            digit++;
        else if (ispunct(date[i]) != 0 && date[i] == '-')
            hyphen++;
    }
    if((digit == 8 || digit == 7 || digit == 6) && hyphen == 2){
    	for(j = 0; j < 4; j++)
		{
			if (isdigit(date[j]) != 0)
            	year++;
		}
		for(k=5; k <= 6; k++)
		{
			if (isdigit(date[k]) != 0)
			month++;
		}
		if(year == 4)
		{
			char yearString[4] = {date[0], date[1], date[2], date[3]};
			int num1 = atoi(yearString);
			int yearChecker = checkYear(num1);
			if(month == 1)
			{
				char monthString[1] = {date[5]};
				int num2 = atoi(monthString);
				int monthChecker = checkMonth(num2);
				for(l=7; date[l] != '\0'; l++)
				{
					if (isdigit(date[l]) != 0)
	            	day++;
				}
				if(day == 1)
				{
					char dayString[1] = {date[7]};
					int num3 = atoi(dayString);
					int dayChecker = checkDay(num3, num2, num1);
					return dayChecker + monthChecker + yearChecker;
				} else
				{
					char dayString[2] = {date[7], date[8]};
					int num3 = atoi(dayString);
					int dayChecker = checkDay(num3, num2, num1);
					return dayChecker + monthChecker + yearChecker;
				}
				
			} else if(month == 2)
			{
				char monthString[2] = {date[5], date[6]};
				int num2 = atoi(monthString);
				int monthChecker = checkMonth(num2);
				for(l=8; date[l] != '\0'; l++)
				{
					if (isdigit(date[l]) != 0)
	            	day++;
				}
				if(day == 1)
				{
					char dayString[1] = {date[8]};
					int num3 = atoi(dayString);
					int dayChecker = checkDay(num3, num2, num1);
					return dayChecker + monthChecker + yearChecker;
				} else
				{
					char dayString[2] = {date[8], date[9]};
					int num3 = atoi(dayString);
					int dayChecker = checkDay(num3, num2, num1);
					return dayChecker + monthChecker + yearChecker;
				}
			} else {
				return 1;
			}
		} else {
			return 1;
		}
	}  else {
		return 1;
	}
}

int checkYear(int year)
{
	if(year < 2022 || year > 2500)
	{
		return year;
	} else
	{
		return 0;
	}
}
int checkMonth(int month)
{
	if(month <1 || month > 12)
	{
		return month;
	} else {
		return 0;
	}
}
int checkDay(int day, int month, int year)
{
	if(day >31 && (month ==1 || month ==3 || month ==5 || month ==7 || month ==8 || month ==10 || month ==12))
	{
		return day;
	} else if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		return day;
	} else if (day > 29 && month == 2 && year %4 == 0)
	{
		return day;
	} else if(day > 28 && month == 2 && year %4 != 0)
	{
		return day;
	} else	
	{
		return 0;
	}
}
int check(char input[])
{
	int alpha = 0;
	int punct = 0;
	int period = 0;
	int i=0;
	int total;
	for (i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]) != 0)
            alpha++;
        else if (ispunct(input[i]) != 0 && input[i] != '.')
            punct++;
        else if (input[i] == '.')
        	period++;
    }
    total = alpha + punct;
    if(total > 0){
    	return total;
	} else if(period > 1){
		return period;
	} else {
		return 0;
	}
}
int checkIdInput(char input[])
{
	int alpha = 0;
	int punct = 0;
	int digit = 0;
	int i=0;
	int total;
	for (i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]) != 0)
            alpha++;
        else if (ispunct(input[i]) != 0)
            punct++;
        else if (isdigit(input[i]) != 0)
        	digit++;
    }
    total = alpha + punct;
    if(total > 0){
    	return total;
	} else if(digit != 5){
		return digit;
	} else {
		return 0;
	}
}
int checkId (int n)
{
    FILE *fpin;
    product p[511];
    char row[100];
    char *token;
    char *temp[5];
    char temp2[7];
    char temp3[5];
    int i = 0;
    int j = 0;
    int x = 0;
    int flag = 0;

    fpin    = fopen("Inventory_ST_NoBOM.csv", "r");

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
        strncpy(p[j].desc, p[j].desc+1, strlen(p[j].desc));
        p[j].desc[strlen(p[j].desc)-1]    = '\0';

        strcpy(p[j].qty,    temp[2]);
        strncpy(p[j].qty, p[j].qty+1, strlen(p[j].qty));
        p[j].qty[strlen(p[j].qty)-1]    = '\0';

        strcpy(p[j].exp,    temp[3]);
        strncpy(p[j].exp, p[j].exp+1, strlen(p[j].exp));
        p[j].exp[strlen(p[j].exp)-1]    = '\0';

        strcpy(p[j].price,  temp[4]);
        strncpy(p[j].price, p[j].price+1, strlen(p[j].price));
        if(p[j].price[strlen(p[j].price) - 1] == '\n')
        {
            p[j].price[strlen(p[j].price)-1]  = '\0';
            p[j].price[strlen(p[j].price)-2]  = '\0';
        }
        else
            p[j].price[strlen(p[j].price)-1]  = '\0';

        j++;
        i = 0;
    }
    for(x = 0; x < j ; x++)
    {
        if(p[x].id == n)
		{
			flag = 1;
		}
    }
fclose(fpin);
return flag;
}
void update()
{
    FILE *fpin;
    FILE *fpout;
    product p[511];
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
    int found = 0;
    char newdesc[53];
    char newqty[18];
    char newexp[18];
    char newprice[18];
    char tempId[20];

    fpin    = fopen("Inventory_ST_NoBOM.csv", "r");

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
        strncpy(p[j].desc, p[j].desc+1, strlen(p[j].desc));
        p[j].desc[strlen(p[j].desc)-1]    = '\0';

        strcpy(p[j].qty,    temp[2]);
        strncpy(p[j].qty, p[j].qty+1, strlen(p[j].qty));
        p[j].qty[strlen(p[j].qty)-1]    = '\0';

        strcpy(p[j].exp,    temp[3]);
        strncpy(p[j].exp, p[j].exp+1, strlen(p[j].exp));
        p[j].exp[strlen(p[j].exp)-1]    = '\0';

        strcpy(p[j].price,  temp[4]);
        strncpy(p[j].price, p[j].price+1, strlen(p[j].price));
        if(p[j].price[strlen(p[j].price) - 1] == '\n')
        {
            p[j].price[strlen(p[j].price)-1]  = '\0';
            p[j].price[strlen(p[j].price)-2]  = '\0';
        }
        else
            p[j].price[strlen(p[j].price)-1]  = '\0';

        j++;
        i = 0;
    }

    printf("Enter ID no. to Update : ");
	scanf("%d", &id);

	for(x = 0; x < j ; x++)
    {
        if(p[x].id == id)
		{

			found=1;
			printf("\nWould you like to update product ID [Y/N]? ");
			scanf(" %c", &ch);
			while (ch != 'y' && ch != 'Y' && ch !='n' && ch != 'N'){
				printf("Invalid Selection. Please try again. ");
				scanf(" %c", &ch);
			}
			if(ch == 'y' || ch == 'Y'){

				printf("Enter New ID: ");
				scanf("%d", &p[x].id);
				sprintf(tempId, "%d", p[x].id);
				while(checkIdInput(tempId) !=0)
				{
					printf("Invalid. Must be 5 digit integer. ");
					scanf("%d", &p[x].id);
					sprintf(tempId, "%d", p[x].id);
				}
				while(checkId(p[x].id) != 0)
				{
					printf("ID already taken. Please try again. ");
					scanf("%d", &p[x].id);
				}
			}
			printf("\nWould you like to update product Description [Y/N]? ");
			scanf(" %c", &ch);
			while (ch != 'y' && ch != 'Y' && ch !='n' && ch != 'N'){
				printf("Invalid Selection. Please try again. ");
				scanf(" %c", &ch);
			}
			if(ch == 'y' || ch == 'Y'){

				printf("Enter New Product Description: ");
				scanf("%s", &p[x].desc);
			}
			
			printf("\nWould you like to update product quantity [Y/N]? ");
			scanf(" %c", &ch);
			while (ch != 'y' && ch != 'Y' && ch !='n' && ch != 'N'){
				printf("Invalid Selection. Please try again. ");
				scanf(" %c", &ch);
			}
			if(ch == 'y' || ch == 'Y'){
				printf("Enter New Quantity: ");
				scanf("%s,", &p[x].qty);
				while(check(p[x].qty) != 0)
				{
					printf("Invalid input. Must be greater than or equal to 0. ");
					scanf("%s,", &p[x].qty);
				}
			}
			printf("\nWould you like to update product expiration date [Y/N]?");
			scanf(" %c", &ch);
			while (ch != 'y' && ch != 'Y' && ch !='n' && ch != 'N'){
				printf("Invalid Selection. Please try again. ");
				scanf(" %c", &ch);
			}
			if(ch == 'y' || ch == 'Y'){
				printf("Enter New Expiration Date (yyyy-mm-dd). \n");
				scanf("%s", &p[x].exp);
				while(checkDate(p[x].exp) != 0)
				{
					printf("Invalid input. Please try again (yyyy-mm-dd). ");
					scanf("%s", &p[x].exp);
				}
			}

			printf("\nWould you like to update product price [Y/N]?");
			scanf(" %c", &ch);
			while (ch != 'y' && ch != 'Y' && ch !='n' && ch != 'N'){
				printf("Invalid Selection. Please try again. ");
				scanf(" %c", &ch);
			}
			if(ch == 'y' || ch == 'Y'){

				printf("Enter New Price (Php): ");
				scanf("%s", &p[x].price);
				while(check(p[x].price) != 0 || strcmp(&p[x].price, "0") == 0)
				{
					printf("Invalid input. Must be greater than 0. ");
					scanf("%s,\n", &p[x].price);
				}
			}
		}
    }

    fclose(fpin);
    if(!found)
	{
		printf("Product not on the list!\n");
		getch();
		main();
	} else
	{
		fpout   = fopen("Inventory_ST_NoBOM.csv", "w");
	    for(x = 0; x < j ; x++)
	    {
	        fprintf(fpout, "\"%d\",\"%s\",\"%s\",\"%s\",\"%s\"\n",p[x].id, p[x].desc, p[x].qty, p[x].exp, p[x].price );
	    }
	
	    printf("Updated!");
	    getch();
	    fclose(fpout);
	}
}
int main()
{
char choice;

    do
    {
    system("cls");
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
