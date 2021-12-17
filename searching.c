#include<stdio.h>
#include<stdlib.h>

	typedef struct Product{
	int id;
	char name[30];
	float qty;
	char exp[20];
	float price;


}Product;


void create(){


	FILE *fp = fopen("Products.txt", "w");

	struct Product p1 = {101,"Nat.Spring",10,"10-23-2015",12.70};
	struct Product p2 = {102,"Datu Puti Vinegar",15,"11-01-2028",15.25};
	struct Product p3 = {103,"Nivea",25,"08-29-2025",20.50};

	fwrite(&p1,sizeof(struct Product),1,fp);
	fwrite(&p2,sizeof(struct Product),1,fp);
	fwrite(&p3,sizeof(struct Product),1,fp);


	fclose(fp);
}

void View(){


	FILE *fp = fopen("Products.txt", "r");

	struct Product p1;
	while(fread(&p1,sizeof(struct Product),1,fp))
	{
		printf("%d,%s,%f,%s,%f\n", p1.id,p1.name,p1.qty,p1.exp,p1.price);

	}

	fclose(fp);

}

void search() {

	int n;
	FILE *fp = fopen("Products.txt", "r");
	struct Product p1;

	printf("Enter the ID number of Product you want to search: \n");
	scanf("%d", &n);

	while(fread(&p1,sizeof(struct Product),1,fp))
	{
		if(p1.id == n && n >= 1 &&n <= 500)
		{
			printf("Product found! \n");
			printf("%d,%s,%f,%s,%f\n", p1.id,p1.name,p1.qty,p1.exp,p1.price);
			break;
		}
	}

if(p1.id != n )
	{
		printf("ERROR! Product not found! \n");
	}

	fclose(fp);

}

int main() {

char choice;


	printf("MAIN MENU \n");
    printf("[A] Create Inventory Item \n");
    printf("[B] Update Inventory Item \n");
    printf("[C] View Inventory List \n");
    printf("[D] Search Inventory List \n");
    printf("[E] Delete Inventory Item \n");
    printf("[X] Exit Program \n");

    printf("\nPlease input your choice: \n");
    scanf("%c", &choice);


	switch(choice)
	{
		case 'A':
		printf("Adding..........: \n");
		create();
		break;

		case 'B':
		printf("Updating..............: \n");
		break;

		case 'C':
		printf("View...........: \n");
		View();
		break;

		case 'D':
		printf("Searching........: \n");
		search();
		getch();

		break;

		case 'E':
		printf("Delete............: \n");
		View();
		break;

		default: printf("Wrong info. \n");
			break;

	}

	return 0;
}


