/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void readData(const char* fileName, struct corona data[], int* lenght);
void showData(const char countryName[], struct corona data[], int* size);
void insertData(struct corona data[], int* size);
void removeData(struct corona data[], int* size);
void updateData(struct corona data[], int* size);
void sortCasesTest(struct corona data[], int* size);
void sortCasesDeaths(struct corona data[], int* size);
struct corona {
	char countryName[53];
	int totalCase, totalDeaths, totalRecovered, totalTestnum, countryPopulation;
};
int main(void) {
	int choice = 0, error, i = 0, j = 0, lenght_inf, display = 0;
	int store_totalTestNum, store_totalDeaths, store_totalRecovered, store_countryPopulation,store_totalCase;                   //for choice 8
	double cases_per_person[150], cases_store;                                                                  //for choice 8
	FILE* writingData;
	struct corona information[150];
	char  country[25],store_name[25];
	const char* file_name[] = { "C:\\Users\\VOLKAN MAZLUM\\Desktop\\covid.txt" };                              //to be able to send address of file,store that to pointer array
	do {
		printf("0. Read data from file\n1. Show Country data\n2. Insert Country data\n3. Remove Country Data\n4. Update Country data\n5. Sort Covid data based on total cases\n6. Sort Covid data based on total deaths\n7. Find and display the top 5 countries with largest number of cases per person\n8. Write recent data to file 'recent.txt'\n9. Exit\nChoose the task(0 - 9) :");
		scanf_s("%d", &choice);
		switch (choice) {
		case 0: {

			readData(*file_name, information, &lenght_inf);
			break;
		}
		case 1: {
			printf("Enter country name: ");
			getchar();                                               //I used that because while user entered some data ,end of that data has as \n ,so that gets_s is skipped.
			gets_s(country);
			showData(country, information, &lenght_inf);
			break;
		}
		case 2: {
			insertData(information, &lenght_inf);
			break;
		}
		case 3: {
			removeData(information, &lenght_inf);
			break;
		}
		case 4: {
			updateData(information, &lenght_inf);
			break;
		}
		case 5: {
			sortCasesTest(information, &lenght_inf);
			break;
		}
		case 6: {
			sortCasesDeaths(information, &lenght_inf);
			break;
		}
		case 7: {
			for (i = 0; i < lenght_inf; i++) {
				cases_per_person[i] = (double)information[i].totalCase / (double)information[i].countryPopulation;    //to take information of cases per person every country without ordering

			}
			for (i = 0; i < lenght_inf; i++) {
				for (j = 0; j < lenght_inf; j++) {
					if (cases_per_person[i] > cases_per_person[j]) {                                                  //while compering each of them, also ordering according to condition

						strcpy_s(store_name, information[i].countryName);                                            //to be able to change name of country while ordering
						store_name[strlen(store_name)] = '\0';
						strcpy_s(information[i].countryName, information[j].countryName);
						information[i].countryName[strlen(information[i].countryName)] = '\0';
						strcpy_s(information[j].countryName, store_name);
						information[j].countryName[strlen(information[j].countryName)] = '\0';

						cases_store = cases_per_person[i];                                                          //to order value of cases per person
						cases_per_person[i] = cases_per_person[j];
						cases_per_person[j] = cases_store;

						store_totalDeaths = information[i].totalDeaths;                                             //to order,change total deaths for every countries
						information[i].totalDeaths = information[j].totalDeaths;
						information[j].totalDeaths = store_totalDeaths;

						store_totalCase = information[i].totalCase;                                             //to order,change total deaths for every countries
						information[i].totalCase = information[j].totalCase;
						information[j].totalCase = store_totalCase;

						store_totalTestNum = information[i].totalTestnum;                                          //to order total tests numbers
						information[i].totalTestnum = information[j].totalTestnum;
						information[j].totalTestnum = store_totalTestNum;

						store_totalRecovered = information[i].totalRecovered;                                     //to order total recovered numbers
						information[i].totalRecovered = information[j].totalRecovered;
						information[j].totalRecovered = store_totalRecovered;

						store_countryPopulation = information[i].countryPopulation;                              //to order country population
						information[i].countryPopulation = information[j].countryPopulation;
						information[j].countryPopulation = store_countryPopulation;
						//I designed this process because while I was compering value of cases per person , the information(total deaths etc.) is wanted to not lost for every country.
					}
				}
			}
			for (display = 0; display < 5; display++) {
				printf("%s", information[display].countryName);
				printf(" is top of% d.cases per person have %.5lf .\n\n", display + 1, cases_per_person[display]);
			}
			break;
		}
		case 8: {
			error = fopen_s(&writingData, "C:\\Users\\VOLKAN MAZLUM\\Desktop\\recent.txt", "w");                     //open file for writing
			if (error == 0) {
				for (i = 0; i < lenght_inf; i++) {
					fprintf(writingData, "%s %d %d %d %d %d\n", information[i].countryName, information[i].totalCase, information[i].totalDeaths, information[i].totalRecovered, information[i].totalTestnum, information[i].countryPopulation);
				}
				fclose(writingData);
			}
			else
				printf("The file is not opened.\n");

			break;
		}
		case 9: {
			printf("Exit!!!\n");
			break;
		}
		default: {
			printf("Wrong choice!!!");
			break;
		}
		}
	} while (choice != 9);
	return(0);
}
void readData(const char* fileName, struct corona data[], int* lenght) {

	int i = 0, error;
	FILE* reading;
	char* next_token1 = NULL;
	error = fopen_s(&reading, fileName, "r");
	char* store[150][10], line[53], * value;

	while (fgets(line, sizeof(line), reading)) {                                //for taking every line until end of the line,and according to '/' (delimiters) seperate every string and change the some strings to number with atoi
		//load country name
		value = strtok_s(line, "/", &next_token1);
		store[i][0] = value;
		strcpy_s(data[i].countryName, store[i][0]);
		//load total case
		value = strtok_s(NULL, "/", &next_token1);
		data[i].totalCase = atoi(value);
		// load total deaths
		value = strtok_s(NULL, "/", &next_token1);
		data[i].totalDeaths = atoi(value);
		// load total recovered
		value = strtok_s(NULL, "/", &next_token1);
		data[i].totalRecovered = atoi(value);
		//total testnum
		value = strtok_s(NULL, "/", &next_token1);
		data[i].totalTestnum = atoi(value);
		value = strtok_s(NULL, "/", &next_token1);
		data[i].countryPopulation = atoi(value);
		//go to next line
		i++;
	}
	*lenght = i;
	fclose(reading);                                       //for closing file
}
void showData(const char countryName[], struct corona data[], int* size) {

	char country_name[25], counter_failed = 0;
	int control, i = 0;
	strcpy_s(country_name, countryName);                                                //for taking country number from main
	for (i = 0; i < *size; i++) {
		control = strcmp(country_name, data[i].countryName);                         //for comparing it is equal or not
		if (control == 0) {                                                         //if equal, do it process
			printf("Country name : %s\n", data[i].countryName);
			printf("Total Case : %d\n", data[i].totalCase);
			printf("Total Death : %d\n", data[i].totalDeaths);
			printf("Total Recovered : %d\n", data[i].totalRecovered);
			printf("Total Tes Number: %d\n", data[i].totalTestnum);
			printf("Population : %d\n", data[i].countryPopulation);
			printf("The task is completed.\n");
			counter_failed++;                                                            //for controling this procces is happened or not
			break;
		}
	}
	if (counter_failed == 0) {
		printf("You entered wrong name or there is no country you entered.\n");
	}
}
void insertData(struct corona data[], int* size) {
	char country_Name[25];
	int i, control = 0;
	printf("Enter country name : ");
	getchar();
	gets_s(country_Name);
	for (i = 0; i < *size; i++) {
		control = strcmp(country_Name, data[i].countryName);                                    //for comparing names
		if (control == 0) {                                                                     //if equal, not need to do something
			printf("This country's data is in the data set. You don't need to add again.\n");
			break;
		}
	}
	if (control != 0) {                                                              //if not equal, do it this process (taking country's information).
		strcpy_s(data[*size].countryName, country_Name);
		printf("%s\n", data[*size].countryName);
		printf("Enter total case : ");
		scanf_s("%d", &data[*size].totalCase);
		printf("Enter total deaths : ");
		scanf_s("%d", &data[*size].totalDeaths);
		printf("Enter total recovered : ");
		scanf_s("%d", &data[*size].totalRecovered);
		printf("Enter total test number : ");
		scanf_s("%d", &data[*size].totalTestnum);
		printf("Enter country population : ");
		scanf_s("%d", &data[*size].countryPopulation);
		*size = *size + 1;                                                         //while in main ,don't loose any data adding from user.
	}
}
void removeData(struct corona data[], int* size) {
	char country_Name[25];
	int i, control = 0;
	printf("Enter country name : ");
	getchar();
	gets_s(country_Name);
	for (i = 0; i < *size; i++) {
		control = strcmp(country_Name, data[i].countryName);
		if (control == 0) {
			for (; i < *size; i++) {
				strncpy_s(data[i].countryName, data[i + 1].countryName, strlen(data[i].countryName));
				data[i].countryName[strlen(data[i].countryName)] = '\0';
				data[i].totalCase = data[i + 1].totalCase;
				data[i].totalDeaths = data[i + 1].totalDeaths;
				data[i].totalRecovered = data[i + 1].totalRecovered;
				data[i].totalTestnum = data[i + 1].totalTestnum;
				data[i].countryPopulation = data[i + 1].countryPopulation;
			}
			printf("The task is completed.\n");
			(*size)--;                                                                        //while in main, not print information higher than lenght of array
			break;
		}
	}
	if (control != 0) {                                                                      //for entering wrong country name
		printf("There is no country like that.\n");
	}
}
void updateData(struct corona data[], int* size) {
	char country_Name[25];
	int i, control = 0;
	int totalCase, totalDeaths, totalRecovered, totalTestnum, countryPopulation;
	printf("Enter country name : ");
	getchar();
	gets_s(country_Name);
	for (i = 0; i < *size; i++) {
		control = strcmp(country_Name, data[i].countryName);
		if (control == 0) {
			printf("%s\n", data[i].countryName);
			printf("Enter total case : ");
			scanf_s("%d", &totalCase);
			data[i].totalCase = data[i].totalCase + totalCase;
			printf("Enter total deaths : ");
			scanf_s("%d", &totalDeaths);
			data[i].totalDeaths = data[i].totalDeaths + totalDeaths;
			printf("Enter total recovered : ");
			scanf_s("%d", &totalRecovered);
			data[i].totalRecovered = data[i].totalRecovered + totalRecovered;
			printf("Enter total test number : ");
			scanf_s("%d", &totalTestnum);
			data[i].totalTestnum = data[i].totalTestnum + totalTestnum;
			printf("Enter country population : ");
			scanf_s("%d", &countryPopulation);
			data[i].countryPopulation = data[i].countryPopulation + countryPopulation;
			break;
		}
	}
}
void sortCasesTest(struct corona data[], int* size) {                                                           //for sorting according to total case's number
	int i = 0, j = 0;
	char store_name[25];
	int store_totalCase, store_totalDeaths, store_totalTestNum, store_totalRecovered, store_countryPopulation;             //store some value to them for not loosing
	for (i = 0; i < *size; i++) {
		for (j = 0; j < *size; j++) {
			if (data[i].totalCase > data[j].totalCase) {
				strcpy_s(store_name, data[i].countryName);                                       //taking string name
				store_name[strlen(store_name)] = '\0';
				strcpy_s(data[i].countryName, data[j].countryName);
				data[i].countryName[strlen(data[i].countryName)] = '\0';
				strcpy_s(data[j].countryName, store_name);
				data[j].countryName[strlen(data[j].countryName)] = '\0';

				store_totalCase = data[i].totalCase;
				data[i].totalCase = data[j].totalCase;
				data[j].totalCase = store_totalCase;

				store_totalDeaths = data[i].totalDeaths;
				data[i].totalDeaths = data[j].totalDeaths;
				data[j].totalDeaths = store_totalDeaths;

				store_totalTestNum = data[i].totalTestnum;
				data[i].totalTestnum = data[j].totalTestnum;
				data[j].totalTestnum = store_totalTestNum;

				store_totalRecovered = data[i].totalRecovered;
				data[i].totalRecovered = data[j].totalRecovered;
				data[j].totalRecovered = store_totalRecovered;

				store_countryPopulation = data[i].countryPopulation;
				data[i].countryPopulation = data[j].countryPopulation;
				data[j].countryPopulation = store_countryPopulation;
			}
		}
	}
	printf("The task is completed.\n");
}
void sortCasesDeaths(struct corona data[], int* size) {                                                   //for sorting according to deaths number
	int i = 0, j = 0;
	char store_name[25];
	int store_totalCase, store_totalDeaths, store_totalTestNum, store_totalRecovered, store_countryPopulation;
	for (i = 0; i < *size; i++) {
		for (j = 0; j < *size; j++) {
			if (data[i].totalDeaths > data[j].totalDeaths) {
				strcpy_s(store_name, data[i].countryName);
				store_name[strlen(store_name)] = '\0';
				strcpy_s(data[i].countryName, data[j].countryName);
				data[i].countryName[strlen(data[i].countryName)] = '\0';
				strcpy_s(data[j].countryName, store_name);
				data[j].countryName[strlen(data[j].countryName)] = '\0';

				store_totalDeaths = data[i].totalDeaths;
				data[i].totalDeaths = data[j].totalDeaths;
				data[j].totalDeaths = store_totalDeaths;

				store_totalCase = data[i].totalCase;
				data[i].totalCase = data[j].totalCase;
				data[j].totalCase = store_totalCase;

				store_totalTestNum = data[i].totalTestnum;
				data[i].totalTestnum = data[j].totalTestnum;
				data[j].totalTestnum = store_totalTestNum;

				store_totalRecovered = data[i].totalRecovered;
				data[i].totalRecovered = data[j].totalRecovered;
				data[j].totalRecovered = store_totalRecovered;

				store_countryPopulation = data[i].countryPopulation;
				data[i].countryPopulation = data[j].countryPopulation;
				data[j].countryPopulation = store_countryPopulation;
			}
		}
	}
	printf("The task is completed.\n");
}
*/
