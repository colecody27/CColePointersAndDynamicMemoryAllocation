/*
 ============================================================================
 Name        : CColePointersAndDynamicMemAloc.c
 Author      : Cody Cole
 Version     :
 Copyright   : 21 October 20
 Description : In-Class Assignment
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//PROTOTYPES
/* bubble sort takes in a compare function pointer to call the correct function depending
on sort type */
void bubbleSort( double n[], int size, double (*compare) (double a, double b));
double ascending(double a, double b);
double descending(double a, double b);

int main(){
    double iSize = 0;
    double *ptr = NULL;
    //READS DATA FROM USER. IF INPUT IS ZERO OR PTR IS NULL, PROGRAM IS TERMINATED.
    puts("Enter amount of data points");
    scanf("%lf", &iSize);
    if(iSize == 0){
        puts("Size of array must be larger than 0");
        exit(0);
    }
    ptr = malloc(sizeof(double) * iSize);
    if(ptr == NULL){
        puts("Error in allocation");
        exit(1);
    }
    else{
        printf("Successful allocation\n");
    }
    //CHOICE TO FILL IN ARRAY
    printf("You are about to enter a loop to fill array\n");
    printf("Would you like to continue? Enter 1 for continue, 2 for end\n");
    int choice_1;
    scanf("%d", &choice_1);
    if(choice_1 != 1){
        puts("Program ended");
        exit(0);
    }

    //FILL IN ARRAY 1 AT A TIME
    printf("Enter elements 1 at a time\n");
    int i;
    double j = 0;
    for(i = 0; i < iSize; i++){
        scanf("%lf", &j);
        ptr[i] = j;
    }

    puts("Array filled");
    puts("Enter 1 to sort array in ascending order OR enter 2 for descending order");
    fflush(stdin);

    int choice_2;
    scanf("%d", &choice_2);
    if(choice_2 == 1)
        bubbleSort(ptr, iSize, ascending);
    if(choice_2 == 2)
        bubbleSort(ptr, iSize, descending);
    puts("Sorted Array:");
    for(i = 0; i < iSize; i++){
        printf("Element at %d equals: %.2lf\n", i, ptr[i] );
    }
    puts("--Complete--");
    //FREE MEMORY
    free(ptr);
}

void bubbleSort( double n[], int size, double (*compare) (double a, double b))
{
 int pass, i, temp;
 for( pass = 1; pass < size; pass++ ) {
     for( i = 0 ; i < size - 1 ; i++ ) {
         if ((*compare)( n[i] , n[i+1]) ) { //If not in order, swap
             temp = n[i];
             n[i] = n[i+1];
             n[i+1] = temp;
         }
      }
    }
}

/* returns 1 if not in ascending order */
double ascending (double a, double b){
    return (a > b) ? 1 : 0;
}

/* returns 1 if not in descending order */
double descending (double a, double b){
    return (a < b) ? 1 : 0;
}

