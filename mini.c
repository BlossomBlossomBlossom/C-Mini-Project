#include<stdio.h>
#include<stdlib.h>
typedef struct product{
	int id;
	char description[20];
	float quantity;
	char expiration[10];
	float price;
}product;

void create(){
	FILE *fp;
	product *p; 
	int n, i;
	printf("Enter how many students you want : ");
	scanf("%d", &n);
	
	p = (product*)calloc(n, sizeof(product));
	fp = fopen("Inventory.txt", "w");
	
	for(i=0; i<n; i++){
		printf("Enter ID No: ");
		scanf("%d,", &p[i].id);
		fflush(stdin);
		printf("Enter Product Description: ");
		scanf("%[^\n]s,", p[i].description);
		printf("Enter Quantity: ");
		scanf("%f,", &p[i].quantity);
		fflush(stdin);
		printf("Enter Expiration Date (dd/mm/yyyy): ");
		scanf("%[^\n]s,", p[i].expiration);
		fflush(stdin);
		printf("Enter Price (Php): ");
		scanf("%f,\n", &p[i].price);
		fflush(stdin);
		
		fwrite(&p[i],sizeof(product),1,fp);
	}
	fclose(fp);
}
void display(){
	product p1;
	FILE *fp;
	fp = fopen("Inventory.txt", "r");
	
	while(fread(&p1, sizeof(product),1,fp)){
		printf("\n%-20d%-20s%-20.2f%-20s%-20.2f",p1.id,p1.description,p1.quantity,p1.expiration,p1.price);
	}
	fclose(fp);
}
void update(){
	product p1;
	char ch;
	FILE *fp, *fp1;
	int id, found = 0;
	fp = fopen("Inventory.txt", "r");
	fp1 = fopen("temp.txt", "w");
	printf("Enter ID no. to Update : ");
	scanf("%d", &id);
	
	while(fread(&p1, sizeof(product),1,fp)){
		
		if(p1.id == id){
			found=1;
			fflush(stdin);
			printf("Would you like to update product ID [Y/N]?");
			scanf("%c", &ch);
			if(ch == 'y' || ch == 'Y'){
				fflush(stdin);
				printf("Enter New ID: ");
				scanf("%d", &p1.id);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
				main();
			}
			fflush(stdin);
			printf("Would you like to update product Description [Y/N]?");
			scanf("%c", &ch);
			fflush(stdin);
			if(ch == 'y' || ch == 'Y'){
				fflush(stdin);
				printf("Enter New Product Description: ");
				scanf("%[^\n]s,", p1.description);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
				main();
			}
			fflush(stdin);
			printf("Would you like to update product quantity [Y/N]?");
			scanf("%c", &ch);
			if(ch == 'y' || ch == 'Y'){
				printf("Enter New Quantity: ");
				scanf("%f,", &p1.quantity);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
				main();
			}
			fflush(stdin);
			printf("Would you like to update product date [Y/N]?");
			scanf("%c", &ch);
			if(ch == 'y' || ch == 'Y'){
				printf("Enter New Expiration Date (dd/mm/yyyy): ");
				fflush(stdin);
				scanf("%[^\n]s,", p1.expiration);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
				main();
			}
			fflush(stdin);
			printf("Would you like to update product price [Y/N]?");
			scanf("%c", &ch);
			if(ch == 'y' || ch == 'Y'){
				fflush(stdin);
				printf("Enter New Price (Php): ");
				scanf("%f,\n", &p1.price);
			} else if (ch == 'n' || ch == 'N'){
			} else {
				printf("Invalid Selection!");
				main();
			}
		}
		fwrite(&p1,sizeof(product),1,fp1);
		
	}
	fclose(fp);
	fclose(fp1);
	if(found){
		fp1 = fopen("temp.txt", "r");
		fp = fopen("Inventory.txt", "w");
		
		while(fread(&p1,sizeof(product),1,fp1)){
			fwrite(&p1,sizeof(product),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		printf("Product succesfully updated!");
	} else {
		printf("\nRecord Not Found\n");
	}
}

int main(){
	int ch;
	do{
		printf("\n1.CREATE");
		printf("\n2.DISPLAY");
		printf("\n3.UPDATE");
		
		printf("\nEnter Your Choice : ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				update();
				break;
		}
	} while(ch!=0);
	
	return 0;
}
