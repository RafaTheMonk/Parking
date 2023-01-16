#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RegisterID{
	int register_number, phone_number, age;
	char name[20]; 
	char genre[10];
};
struct RegisterID personal_register[12][31];

int check_memory(int m, int d){
    if (m >=1 && m <=12){
    	if(d >=1 && d <=31){
    		if(personal_register[m][d].register_number==0){
    			return 0;
			}
       }else{
       		return 2;
	   }
    }else{
    	return 1;
	}
}

void consult_reservation(){
int mo, da, c;
	do{
		printf("\nConsult an specifically reservation:\nDo you want to continue?\n(1 to Y / 0 to N)\n");
		scanf("%d", &c);
		fflush(stdin);
		system("cls");
	if(c==1){
		printf("what's the month you want to consult?\n");
		scanf("%d", &mo);
		fflush(stdin);
	
		printf("what's the day you want to consult?\n");
		scanf("%d", &da);
		fflush(stdin);	
		
		if(personal_register[mo][da].register_number!=0){
			printf("\nData this day %d/%d\n",mo,da);
			
			printf("\nRegister number:\n%d\n", personal_register[mo][da].register_number);
						
			printf("\nName\n%s\n", personal_register[mo][da].name);
			
			printf("\nGenre:\n%s\n", personal_register[mo][da].genre);
			
			printf("\nPhone number:\n%d\n", personal_register[mo][da].phone_number);
			
			printf("\nAge:\n%d\n", personal_register[mo][da].age);
		}else{
			printf("Don't has data this day\n");
		}
	}else if(c==0){
		printf("\nReturning to main menu\n\n");
	}else{
		printf("Invalid comand!\n");
	}
	}while(c!=0);
}

void make_reservations(){
int day, month, c, result;
	
	do{
		printf("\nMake a reservation:\nDo you want to continue?\n(1 to Y / 0 to N)\n");
		scanf("%d", &c);
		fflush(stdin);
		system("cls");
		
		if(c==1){
			printf("what's the month you wish?\n");
			scanf("%d", &month);
			fflush(stdin);
		
			printf("\nwhat's the day you wish?\n");
			scanf("%d", &day);
			fflush(stdin);
		
		result = check_memory(month,day);	
			
			if(result == 0){
				printf("\nWhat's your register number?\n");
				scanf("%d", &personal_register[month][day].register_number);
				fflush(stdin);
				
				printf("\nWhat's your name?\n");
				fgets(personal_register[month][day].name, 20, stdin);
				fflush(stdin);
				
				printf("\nWhat's your genre?\nEx:(male)\n");
				fgets(personal_register[month][day].genre, 10, stdin);
				fflush(stdin);
				
				printf("\nWhat's your phone number?\nEx:(xxxxxxxx)\n");
				scanf("%d", &personal_register[month][day].phone_number);
				fflush(stdin);
				
				printf("\nhow old are you?\n");
				scanf("%d", &personal_register[month][day].age);
				fflush(stdin);
				
				printf("\nReservation concluded\n\n");
			}
			else if(result == 1){
				printf("\nInvalid month\n\n");
			}else if(result == 2){
				printf("\nInvalid day\n\n");
			}else{
				printf("\nDate Sold out\n\n");
			}
		}else if(c==0){
			printf("\nReturning to main menu\n\n");
		}
		else{
			printf("\nInvalid comand\n\n");
		}
	}while(c!=0);
}

void initializing_vector(){
	int d, m;
	for (m=0;m<12;m++){
		for(d=0;d<31;d++){
			personal_register[m][d].register_number=0;
		}
	}
}

int main(){
	initializing_vector();
    int op;

do{
	system("cls");
    printf("Main menu:\n");
    printf("1 - Make reservations\n");
    printf("2 - Consult an specifically reservation\n");
    printf("3 - List all reservations\n");
    printf("4 - Exit\n");
    scanf("%d", &op);

    switch(op){
        case 1:
        make_reservations();
        break;
        case 2:
        consult_reservation();
        break;
        case 3:
        printf("Consult reservations in this month\n");
        break;
        case 4:
        printf("Thanks for your access\n");
        break;
        default:
        printf("Invalid option");
        break;
    }
    system("pause");
}while(op!=4);
return 0;
}

