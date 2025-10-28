#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define  MAX_UZUNLUK 1024


int main() 
{
	FILE* fptr;
	char data[MAX_UZUNLUK];
	int i = 1;
	char menu_choice[MAX_UZUNLUK];


	do
	{
		if(i == 1) {
			printf("\n**Basic Text Editor**\n");
			printf("1-Writing\n2-Reading\n3-Append\n4-Exit");
			printf("\nPlease select an option from the menu:");
			fgets(menu_choice, MAX_UZUNLUK, stdin);
		}



		if (strcmp(menu_choice, "4\n") == 0)
		{
			printf("Exiting...");
			i = 0;
		}

		else if (strcmp(menu_choice, "1\n") == 0)
		{
			char filename[MAX_UZUNLUK];
			printf("You selected Writing option.\n");
			printf("Enter the filename (without .txt): ");
			fgets(filename, MAX_UZUNLUK, stdin);
			filename[strcspn(filename, "\n")] = 0; 
			strcat(filename, ".txt");

			printf("Enter the text to write to the file:\n");
			fgets(data, MAX_UZUNLUK, stdin);
			
			fptr = fopen(filename, "w");
			if(fptr == NULL) {
				printf("Error creating file!\n");
			} else {
				fputs(data, fptr);
				printf("Text written to file successfully!\n");
				fclose(fptr);
			}
			i=1;
		}

		else if (strcmp(menu_choice, "2\n") == 0)
		{
			char filename[MAX_UZUNLUK];
			printf("You selected Reading option.");
			printf("Enter the filename (without .txt): ");
			fgets(filename, MAX_UZUNLUK, stdin);
			filename[strcspn(filename, "\n")] = 0;
			strcat(filename, ".txt");

			fptr = fopen(filename, "r");
			if (fptr == NULL) {
				printf("Error opening file!\n");
			} else {
				printf("File contents:\n");
				while (fgets(data, MAX_UZUNLUK, fptr) != NULL) {
					printf("%s", data);
				}
				fclose(fptr);
			}
			i=1;
		}

		else if (strcmp(menu_choice, "3\n") == 0)
		{
			char filename[MAX_UZUNLUK];
			printf("You selected Append option.");
			printf("Enter the filename (without .txt): ");
			fgets(filename, MAX_UZUNLUK, stdin);
			filename[strcspn(filename, "\n")] = 0;
			strcat(filename, ".txt");
			printf("Enter the text to append to the file:\n");
			fgets(data, MAX_UZUNLUK, stdin);
			fptr = fopen(filename, "a");
			if(fptr == NULL) {
				printf("Error opening file!\n");
			} else {
				fputs(data, fptr);
				printf("Text appended to file successfully!\n");
				fclose(fptr);
			}
			i=1;
		}

		else
		{
			printf("Invalid option selected.");
			i=1;
		}

	} while (i);

	return 0;
}
