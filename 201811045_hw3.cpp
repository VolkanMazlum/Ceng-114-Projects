/*

#include <stdio.h>
int inputProductAmount(int arr1[10][10],int* storeId,int* productId);
void stockControl(int productId, int storeId, int arr2[][10], int size1);
void listProduct(int productId2, int storeId2, int arr3[][10]);
void listProductsExistNot(int storeId1, int storeId2, int arr4[][10], int size2);
void listProductsExist(int storeId3, int storeId4, int arr5[][10], int size3);
void listSorted(int arr6[][10], int size4, int productIds[], int* size1, int amounts[], int* size2);
int updateStock(int storeId5, int productId3, int newStock, int arr6[][10], int size4);
int main(void) {
	int operation = 0, productAmount[10][10] = { 0 }, storeId1=0, productId1=0, selection = 1, newStock = 0, operationList = 0, compare1=0, compare2=0;
	int prodId[10], amount[10],size_productId,size_amount,i=0,j=0;                                                                                              //This variables for function of listSorted                                                                       //Variables for listSorted function
	while (operation != 4) {                                                                                                                                    //To control until 4 is inputted
		selection = 1;                                                                                                                                       //The variable for controlling contunie or not
		printf("Main Menu\n");
		printf("0- Input product amount of stores\n1 - Stock control with product id and store id\n2 - List products\n3 - Update stock\n4 - Quit\n");
		printf("Select yout operation: ");
		scanf_s("%d", &operation);
		switch (operation) {
		case 0:
		{
			while (selection == 1) {
				productAmount[storeId1][productId1] = inputProductAmount(productAmount, &storeId1, &productId1);
				printf("1- Continue\n2 - Return main menu\nSelection: ");
				scanf_s("%d", &selection);
			}
			break;
		}
		case 1: {                                                           //For function of stockControl
			while (selection == 1) {                        
				printf("Enter product id :");
				scanf_s("%d", &productId1);
				printf("Enter store id: ");
				scanf_s("%d", &storeId1);
				stockControl(productId1, storeId1, productAmount, 10);
				printf("1- Continue\n2 - Return main menu\nSelection: ");                     //To ask to continue or not
				scanf_s("%d", &selection);
			}
			break;
		}
		case 2: {
			while (selection == 1) {
				printf("1- List all products of store n\n2 - List products exist in store n but not store m\n3 - List products exist in both store n and store m\n4 - List sorted product by stock\n");
				printf("Select your operation : ");
				scanf_s("%d", &operationList);
				if (operationList == 1) {                                                           //If for function of listProduct
						printf("Input store Id: ");
						scanf_s("%d", &storeId1);
						listProduct(productId1, storeId1, productAmount);
				}
				else if (operationList == 2) {                                                     //else if for function of listProductExistNot
						printf("Select two stores to compare: ");
						scanf_s("%d %d", &compare1,&compare2);
						listProductsExistNot(compare1, compare2, productAmount, 10);
				}
				else if (operationList == 3) {                                                    //else if for function of listProductsExist
						printf("Choose two stores: ");
						scanf_s("%d%d", &compare1, &compare2);
						listProductsExist(compare1, compare2, productAmount, 10);
				}
				else if (operationList == 4) {
					listSorted(productAmount, 10, prodId, &size_productId, amount, &size_amount);
					printf("Product ID:");
					for (i = 0; i <size_productId ; i++) {
						printf(" %d ", prodId[i]);
					}
					printf("\nAmount: ");
					for (j = 0; j < size_amount; j++) {                                                //to print amount taken from function of listsorted
						printf(" %d ", amount[j]);
					}
					puts("\n");
				}
				else
					printf("It is wrong operation.\n");
				printf("\n\n1- Continue\n2 - Return main menu\nSelection: ");                    //To ask continue or not
				scanf_s("%d", &selection);
			}
			break;
		}
		case 3: {
			while (selection == 1) {
				
				printf("Select store 0-9 :");
				scanf_s("%d", &storeId1);
				if (storeId1 <= 9) {                                         //To control product id, it is higher than 9 or not.
					printf("Enter product id in store %d ", storeId1);
					scanf_s("%d", &productId1);
					if (productId1  <= 9) {
						printf("Current stock of product %d in store %d :  %d\n", productId1, storeId1, productAmount[storeId1][productId1]);
						printf("Enter new stock : ");
						scanf_s("%d", &newStock);
						productAmount[storeId1][productId1] = updateStock(storeId1, productId1, newStock, productAmount, 10);
					}
					else {
						printf("It is wrong.");
						break;
					}
				}
				else {
					printf("It is wrong.");
					break;
				}
				printf("1- Continue\n2 - Return main menu\nSelection: ");                             //To ask continue or not
				scanf_s("%d", &selection);	
			}
			break;
		}
		case 4: {                                                                         //If inputted 4, program will be end
			printf("BYE...\n");
			break;
		}
		default:                                                                         //For controling is there a problem
		  {
			printf("It is wrong operation.\n");
			break;
		  }
	    }
	}
	return(0);
}
int inputProductAmount(int arr[10][10], int* storeId, int* productId) {
	int amount=0;
	printf("Enter store Id: ");                                                   //To take store,product id and amount from user
	scanf_s("%d", storeId);
	printf("Enter product Id: ");
	scanf_s("%d", productId);
	printf("Enter amount: ");
	scanf_s("%d", &amount);
	arr[*storeId][*productId] = arr[*storeId][*productId]+ amount;
	return(arr[*storeId][*productId]);
}
void stockControl(int productId, int storeId, int arr2[][10], int size1) {
	printf("Store: %d   Product: %d   Amount: %d  \n",storeId,productId,arr2[storeId][productId]);
}
void listProduct(int productId2, int storeId2, int arr3[][10]) {
	int  i=0,j = 0;
	printf("Product:");
	for (i = 0; i < 10; i++) {                                                     //To list product id
		printf("  %d", i);
	}
	printf("\nStock:");
	for (j = 0; j < 10; j++) {                                                       //to list amount of product which is inputted
		printf("  %d", arr3[storeId2][j]);
	}
	puts("\n");
}
void listProductsExistNot(int storeId1, int storeId2, int arr4[][10], int size2) {
	int j = 0,i=0;
	printf("Product: ");
	for (j = 0; j < size2; j++) {                                                 //To control,some products should be in one store,other store doesn't have. 
		if (arr4[storeId2][j] == 0 && arr4[storeId1][j] > 0) {
			printf(" %d", j);
		}
	}
	puts("\n");
	printf("Amount: ");
	for (i = 0; i < size2; i++) {                                                   //For printing amount
		if (arr4[storeId2][i] == 0 && arr4[storeId1][i] > 0) {
			printf(" %d ", arr4[storeId1][i]);
		}
	}
	puts("\n");
}
void listProductsExist(int storeId3, int storeId4, int arr5[][10], int size3) {
	int j = 0,counter=0;
	printf("Products available both store %d and %d:", storeId3, storeId4);
	for (j = 0; j < size3; j++) {                                                  //This loop for controling product exist
		if (arr5[storeId3][j] > 0 && arr5[storeId4][j]>0) {
			printf(" %d ", j);
			counter++;
		}
	}
	if (counter == 0)                                                                   //If there is no change, there is no values of products
		printf("There is nothing.\n ");
}
void listSorted(int arr6[][10], int size4, int productIds[], int* size1, int amounts[], int* size2) {
	int sumi,storeIndex=0,min=0, sumj, sortj = 0, sorti = 0, i = 0, j = 0, store, n = 0, sumChange[10] = { 0 }, sum1 = 0, index[10] = { 0 };
	for (sumi = 0; sumi < size4; sumi++) {
		for (sumj = 0,sum1=0; sumj < 10; sumj++) {
			sum1 = sum1 + arr6[sumj][sumi];
		}
		sumChange[sumi] = sum1;                                                         //to take value of sum of columns
		index[sumi] = sumi;                                                             //to take product id

	}
	printf("\n");
	for (sorti = 0; sorti < size4; sorti++) {                                      //to sort array of amount and product id
		for (sortj = sorti+1; sortj < 10; sortj++) {
			if (sumChange[sortj] < sumChange[sorti]) {
				store = sumChange[sorti];
				sumChange[sorti] = sumChange[sortj];
				sumChange[sortj] = store;
				storeIndex = index[sorti];
				index[sorti] = index[sortj];                                        //To change index and hold value
				index[sortj] = storeIndex;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		amounts[i] = sumChange[i];                                                //to get value into array of amount
		productIds[i] = index[i];                                                 //to get value into array of product id
	}
	*size1 = 10;
	*size2 = 10;
}
int updateStock(int storeId5, int productId3, int newStock, int arr6[][10], int size4) {

	arr6[storeId5][productId3] = newStock;                                                      //to update stock with new stock which is inputted from user
	if (arr6[storeId5][productId3] == 0) {
		printf("Product %d is out of stock in store %d.", productId3, storeId5);
		printf("DONE!\n");
	}
	else
		printf("DONE!\n");
	return(arr6[storeId5][productId3]);
}
*/
