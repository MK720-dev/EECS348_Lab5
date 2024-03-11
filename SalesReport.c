#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swapint(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swapchar(char **a, char **b) {
    char *temp = NULL;
    temp = *a;
    *a = *b;
    *b = temp;
  
}

void quicksort(float arr1[], char *arr2[],  int low, int high) {
    if (low < high) {
        // Partition the array into two halves
        int pivot = arr1[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr1[j] >= pivot) {
                i++;
                swapint(&arr1[i], &arr1[j]);
                swapchar(&arr2[i], &arr2[j]);
            }
        }
        swapint(&arr1[i + 1], &arr1[high]);
        swapchar(&arr2[i + 1], &arr2[high]);
        // Recursively sort the two halves
        quicksort(arr1, arr2, low, i);
        quicksort(arr1, arr2, i + 2, high);
    }
}

int main(){

    FILE *fptr;
    fptr = fopen("SalesReportSampleInput1", "r");
    
    char myString[100];
    float sales[12];
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "Sepetember", "October", "November", "December"};

    if (fptr != NULL){
        int i = 0;
        while(fgets(myString, 100, fptr) && i<12){
            sales[i] = strtof(myString, NULL);
            i++;
        }
    }
    else{
        printf("Not able to open the file.");
        return 1;
    }
    printf("Monthly sales report for 2024:\n");
    printf("%-10s | %s\n", "Month", "Sales");
    printf("--------------------\n");

    float max = sales[0];
    float min = sales[0];
    float average = 0;
    // Print each row of the table
    for (int i = 0; i < 12; i++) {
        printf("%-10s | $%0.2f\n", months[i], sales[i]);
        if (sales[i] < min){
            min = sales[i];
        }
        if (sales[i] > max){
            max = sales[i];
        }
        average += sales[i];
    }
    average = average/12;
    printf("\n");
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f\n", min);
    printf("Maximum sales: $%.2f\n", max);
    printf("Average sales: $%.2f\n", average);

    printf("\n");
    printf("Six-Month Moving Average Report:\n");
    printf("%-20s    | %-10s\n", "Period", "Average Sales");
    printf("-------------------------------------------\n");
    
    for (int i = 0; i<=6; i++){
        float six_month_avg = 0;
        for (int j = i; j<i+6; j++){
            six_month_avg += sales[j];
        }
        six_month_avg /= 6;
        printf("%-10s - %-10s | $%0.2f\n", months[i], months[i+5], six_month_avg);
    }

    printf("\n");
    printf("Sales Report (Highest to Lowest):\n");
    quicksort(sales, months, 0, 11);
    for (int i = 0; i < 12; i++) {
        printf("%-10s | $%0.2f\n", months[i], sales[i]);
    }

    fclose(fptr);

    return 0;

}