#include<stdio.h>

int strLength(char *string){
	int len=0;
	while(string[len]!='\0'){
		len++;
	}
	return len;
}
void Encode(char *string){
	int length=strLength(string);
	int temp;
	for(int i=0; i<length/2; i++){
		temp=string[i];
		string[i]=string[length-i-1];
		string[length-i-1]=temp;
	}
	for(int i=0; i<length; i++){
		string[i]^=18;
	}
}
void Decode(char *string){
	int length=strLength(string);
	int temp;
	for(int i=0; i<length; i++){
		string[i]^=18;
	}
	for(int i=0; i<length/2; i++){
		temp=string[i];
		string[i]=string[length-i-1];
		string[length-i-1]=temp;
	}
}
int main(){
	char message[500];
	int choice;
	printf("\tTCS Dispatching Encryption System\n");
	do{
		printf("Menu:\n");
		printf("1. Encode\n2. Decode\n3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter your message: ");
				getchar();
				scanf("%[^\n]", message);
				Encode(message);
				printf("Encoded message: %s\n", message);
				break;
			case 2:
				printf("Enter the encoded message: ");
				getchar();
				scanf("%[^\n]", message);
				Decode(message);
				printf("Decoded message: %s\n", message);
				break;				
			case 3:
				printf("Thanks for using our TCS Service!");
				return 1;
			default:
				printf("Invalid Input! Try Again\n");
		}	
	}
	while(choice!=3);
	scanf("%[^\n]", message);
	Encode(message);
	printf("%s\n", message);	
	
	return 0;
}
