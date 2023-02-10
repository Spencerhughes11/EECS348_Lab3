#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	// ------------------------------ Read from input file ------------------------------

float* read_file(const char* filename){
	FILE* fileIn = fopen(filename, "r");	
	float* sales = (float*)malloc(sizeof(float)*12);
	int i;

	for (i = 0; i < 12; i++){
		
		fscanf(fileIn, "%f", &sales[i]);
	}
	fclose(fileIn);
	return sales;
}

// ------------------------------ Monthly Sales report ------------------------------

void monthly_sales_report(const char* months[], float* sales){
	int i;
	printf("\nMonthly sales report for 2022\n\n");
	printf("%-9s %12s\n", "Month", "Sales");
	for (i = 0; i < 12; i++){
	
		printf("%-9s\t $%8f\n", months[i], sales[i]);
	}
}
	
// ------------------------------------ Sales Summary ------------------------------------

void sales_summary(const char* months[], float* sales){
	// MIN MAX
	float smallest = sales[0];
	float max = sales[0];
	int minIndex = 0, maxIndex = 0;

	printf("\nSales summary:\n");

	for (int i = 0; i < 12; i++){
		if (sales[i] > max){
			max = sales[i];
			maxIndex = i;
		}
	
	}
	for (int i = 0; i < 12; ++i){
		if (sales[i] < smallest){
			smallest = sales[i];
			minIndex = i;
		}
	
	}

	printf("Minimum sales:\t $%8f (%s)\n", smallest, months[minIndex]);
	printf("Maximum sales:\t $%8f (%s)\n", max, months[maxIndex]);
	
	// AVERAGE

	float average;
	float sum = 0;
	for (int i = 0; i < 12; i++){
		sum = sum + sales[i];
	}
	average = sum/12;
		
	printf("%-14s\t $%8f\n",  "Average sales: ", average);
	

}
	// ------------------------------ 6 month moving average ------------------------------
void moving_average(const char* months[], float* sales){
	float sum = 0;
	float average;
	printf("\nSix-Month Moving Average Report\n");

	for (int i = 0; i < 7; i++){
		sum = sales[i] + sales[i+1] + sales[i+2] + sales[i+3] + sales[i+4] + sales[i+5];
	
		printf("%-10s\t -\t%-10s $%-12f\n", months[i], months[i+5], sum/6);
}
}

	// ------------------------------ Sales report in order ------------------------------

void float_sort(float* x, float* y){
	float temp = *x;
	*x = *y;
	*y = temp;
}

void char_sort(char **x, char **y){
	char* temp = *x;
	*x = *y;
	*y = temp;
}

void ordered_report(const char* months[], float* sales){
	printf("\n\nSales Report (Highest to Lowest):\n");
	printf("%4s %10s\n", "Month", "Sales");

	// create copy array to sort
		float* sorted_sales = (float*)malloc(sizeof(float)*12);
		for (int i = 0; i < 12; i++){
			sorted_sales[i] = sales[i];
		}

		char *sorted_months[12];
		for (int i = 0; i < 12; i++){
			char* copy_month = (char*)malloc(sizeof(char)*sizeof(months[i]+1));
			strcpy(copy_month, months[i]);
			sorted_months[i] = copy_month;
		}

		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if (sorted_sales[i] > sorted_sales[j]){
					float_sort(&sorted_sales[i], &sorted_sales[j]);
					char_sort(&sorted_months[i], &sorted_months[j]);
				}
			}
		}

		for (int i = 0; i < 12; i++){
			printf("%-10s $%10f\n", sorted_months[i], sorted_sales[i]);
		}
}
// ------------------------- MAIN ---------------------------------->
int main(){
	float* sales = read_file("num.txt");
	const char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October", "November", "December"};
		
	//  Monthly Sales report 
	monthly_sales_report(months, sales);

	//  Sales Summary 
	sales_summary(months, sales);
	
	//  6 month moving average 
	
	moving_average(months, sales);	
	//  Sales report in order 
	ordered_report(months, sales);	
		
	return 0;
}