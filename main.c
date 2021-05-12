#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

FILE *fl;

typedef struct data{
	
	int elem;
	struct data* right;
	struct data* left;
	
};

typedef struct data Pack;
Pack* prim = NULL;

Pack* CreateNode(){
	
	Pack* x = (Pack*)malloc(sizeof(Pack));
	if(x != NULL){
		return x;
	}else{
		return NULL;
	}
}

int ListSize(){
	int i = 0, num;
	
	fl = fopen("Agenda.txt","r");
		
	while(fscanf(fl,"%d",&num) != EOF){
		i++;
	}
		
	fclose(fl);
	
	return i;
}

//done
InsertElement(){
	
	int element = NULL, i = 0,cont, num, elemt, pos;
	Pack* x;
	Pack* y;
	Pack* aux;
	
	printf("\n\n________________Inserting an element________________\n");
	
	printf("\nWich element shall be inserted?\nElement:  ");
	scanf("%d",&elemt);
	printf("\nWhat is its position?\nPostion: ");
	scanf("%d",&pos);
	
	if(pos<=0){
		printf("\nThere is no %d position. The list starts on 1° position, then 2° and so on...\n");
	}else{
		
		i = ListSize();
		
		if( i == 0){
		
			if(pos != 1){
				printf("The list is empty, there is no %d position. The list stars on 1st position, then 2nd and so on...",pos);
			}else{
				prim = CreateNode();
			
				prim->elem = elemt;
				prim->right = NULL;
				prim->left = NULL;
				
				fl = fopen("Agenda.txt", "a");
				
				if(fprintf(fl,"%d\n",prim->elem) == 2)
				{
					printf("\nElement %d inserted successfully! \n\n",elemt);
				}
				fclose(fl);
								
			}
	
		}else{
		
			//if the list is not empty
			if(pos > i+1){
				printf("\nThe list has only %d elements. You could only add this element up to the %d position\n",i,i+1);
			}else{
				if(pos == 1){ /* DONE */
					
					fl = fopen("Agenda.txt","r");
					x = CreateNode();
												
					x->elem = elemt;
					x->right = NULL;
					x->left = NULL;
					prim = x;
					y = x;
					
					while(fscanf(fl, "%d", &num) != EOF){
	
							x = CreateNode();
												
							x->elem = num;
							x->right = NULL;
							x->left = y;
							y->right = x;		
							y = x;			
												
					}
					
					fclose(fl);
					
					fl = fopen("Agenda.txt", "w");
					
					x = prim;
					y = prim;
					
					while(x->right !=  NULL){
						fprintf(fl,"%d\n",x->elem);
						x = x->right;
						free(y);
						y = x;
						
					}
					fprintf(fl,"%d\n",x->elem);
					free(x);

					
					fclose(fl);
				}
				if((pos > 1) && (pos < i+1)){ /* DONE */  
					
					fl = fopen("Agenda.txt","r");
					
					for(cont = 0; cont < i; cont++){
						
						if(prim == NULL){
							x = CreateNode();
							fscanf(fl, "%d", &x->elem);
							x->right = NULL;
							x->left = NULL;
							
							prim = x;
							y = x;
							cont++;
						}
						
						if(cont == (pos - 1)){
							x = CreateNode();
							x->elem = elemt;
							x->right = NULL;
							x->left = y;
						
							y->right = x;
							y = x;
						}
						
						x = CreateNode();
						fscanf(fl, "%d", &x->elem);
						x->right = NULL;
						x->left = y;
						
						y->right = x;
						y = x;
						
					}
					
					fclose(fl);
					
					x = prim;
					y = prim;
					
					fopen("Agenda.txt", "w");
					
					while(x->right !=  NULL){
						fprintf(fl,"%d\n",x->elem);
						x = x->right;
						free(y);
						y = x;
						
					}
					
					fprintf(fl,"%d\n",x->elem);
					free(x);

					
					fclose(fl);
					
					
				}
				if(pos == i+1){
					
					x = NULL;
					y = NULL;
					
					fl = fopen("Agenda.txt","r");
					
					if(prim == NULL){
							
							prim = CreateNode();
							fscanf(fl, "%d", &prim->elem);
							prim->right = NULL;
							prim->left = NULL;
							
							x = prim;
							y = prim;
							
						}
					
					while(fscanf(fl, "%d", &num) != EOF){
											
							x = CreateNode();
							x->elem = num;
							x->right = NULL;
							x->left = y;
							y->right = x;
							y = x;
								
					}
					
							x = CreateNode();
							x->elem = elemt;
							x->right = NULL;
							x->left = y;
							y->right = x;
							y = x;
					
					fclose(fl);
					
					fl = fopen("Agenda.txt", "w");
					
					x = prim;
					y = prim;
					
					while(x->right != NULL){
						fprintf(fl,"%d\n",x->elem);
						x = x->right;
						free(y);
						y = x;
						
					}
					
					fprintf(fl,"%d\n",x->elem);
					free(x);		
				}
		
				
			}	
	
		}
	}
	
	printf("___________________________________________________\n");
	
}

//done
BiggestElemet(){
	
	int big_one, i = 0,cont,num;
	Pack* x;
	Pack* y;
	
	
	printf("\n\n________________Biggest Element________________\n");
	
	
	fl = fopen("Agenda.txt", "r");
	
	if(prim == NULL){
			
			prim = CreateNode();
			fscanf(fl,"%d",&prim->elem);
			prim->right = NULL;
			prim->left = NULL;
			
			big_one = prim->elem;
			
			x = prim;
			y = prim;
			
		}
	
	while(fscanf(fl,"%d",&num) != EOF){
	
		x = CreateNode();
		x->elem = num;
		x->right = NULL;
		x->left = y;
		y->right = x;
		y = x;
		
		if(x->elem > big_one){
			big_one = x->elem;
		}
		
	}
	
	x = prim;
	y = prim;
	
	while(x->right != NULL){
		x = x->right;
		free(y);
		y = x;
	}
	
	free(x);
	
	fclose(fl);
	
	printf("\nThe biggest element is: %d\n",big_one);
	printf("______________________________________________\n\n");
	
}


MeanValue(){
	
	int i = 0, num;
	float plus = 0.0;
	Pack* x;
	Pack* y;
	
	fl = fopen("Agenda.txt", "r");
	
	if(prim == NULL){
			
			prim = CreateNode();
			fscanf(fl,"%d",&prim->elem);
			prim->right = NULL;
			prim->left = NULL;

			plus += prim->elem;
			
			x = prim;
			y = prim;
			i++;
			
		}
	
	while(fscanf(fl,"%d",&num) != EOF){
	
		x = CreateNode();
		x->elem = num;
		x->right = NULL;
		x->left = y;
		y->right = x;
		y = x;
		
		i++;
		
		plus += x->elem;
		
	}
	
	x = prim;
	y = prim;
	
	while(x->right != NULL){
		x = x->right;
		free(y);
		y = x;
	}
	
	free(x);
	
	fclose(fl);
	
	
	printf("\n___________________Mean Value___________________\n");
	
	printf("\nThe mean velue is: %2.2f\n", plus/i);
	
	printf("________________________________________________\n");
	
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int menu = 0;
	
	printf(" ______________________MENU______________________\n");
	printf("|                                                |\n");
	printf("|   [1] Insert a elemnt after a given one        |\n");
	printf("|   [2] Search the greatest elemnt in the list   |\n");
	printf("|   [3] Mean value in the list                   |\n");
	printf("|________________________________________________|\n\n");
	printf("\nChoice: ");
	if(scanf("%d",&menu) != 1){
		printf("\nError: action caption.\n");
	}else{
		if((menu != 1) && (menu != 2) && (menu != 3) && (menu != 4)){
			printf("\nThere is no such option, type one of these above.\n");
		}else{
			switch(menu){
		
		case 1:InsertElement();				
			break;
		case 2: BiggestElemet();
			break;
		case 3: MeanValue();
			break;
		
	}
		}
	}
		
	return 0;
}
