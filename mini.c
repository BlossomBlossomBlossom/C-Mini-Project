#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	printf("Enter how many products you want to add : ");
	scanf("%d", &n);
	fflush(stdin);
	
	p = (product*)calloc(n, sizeof(product));
	fp = fopen("Products.csv", "w");
	
	for(i=0; i<n; i++){
		printf("Enter ID No: ");
		scanf("%d,", &p[i].id);
		fflush(stdin);
		printf("Enter Product Description: ");
		scanf("%[^\n]s,", &p[i].description);
		printf("Enter Quantity: ");
		scanf("%f,", &p[i].quantity);
		fflush(stdin);
		printf("Enter Expiration Date: (dd/mm/yyyy)");
		scanf("%[^\n]s,", &p[i].expiration);
		fflush(stdin);
		printf("Enter Price: (Php)");
		scanf("%f,\n", &p[i].price);
		fflush(stdin);
		
		fprintf(fp,"\n%d,%s,%f,%s,%f",p[i].id,p[i].description,p[i].quantity,p[i].expiration,p[i].price);
	}
	fclose(fp);
}
void update(){
	product p1;
	FILE *fp, *fp1;
	int id, found = 0;
	fp = fopen("Products.csv", "r");
	fp1 = fopen("temp.csv", "w");
	printf("Enter product ID to Update : ");
	scanf("%d", &id);
	
	while(fread(&p1, sizeof(product),1,fp)){
		
		if(p1.id == id){
			found=1;
			fflush(stdin);
			printf("Enter new ID: ");
			scanf("%d", p1.id);
			printf("Enter new Decsription: ");
			scanf("%[^\n]s", p1.description);
			printf("Enter new Decsription: ");
			scanf("%lf", p1.quantity);
			printf("Enter new Expiration Date (dd/mm/yyyy): \n");
			scanf("%[^\n]s", p1.expiration);
			printf("Enter new Price (Php): \n");
			scanf("%f", p1.price);
		}
		fwrite(&p1,sizeof(product),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found){
		fp1 = fopen("Products.csv", "r");
		fp = fopen("temp.csv", "w");
		
		while(fread(&p1,sizeof(product),1,fp1)){
			fwrite(&p1,sizeof(product),1,fp);
		}
		fclose(fp);
		fclose(fp1);
	} else {
		printf("\nProduct ID does not exist\n");	
	}
}

int main(){
	int ch;
	do{
		printf("\n1.CREATE");
		printf("\n2.UPDATE");
		
		printf("\nEnter Your Choice : ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				update();
				break;

		}
	} while(ch!=0);
	
	return 0;
}
