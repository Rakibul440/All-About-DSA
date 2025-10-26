#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* ========== Structure for Array Properties ============ */

struct Array {
    int *p;
    int size; 
    int length;
};

/*======= All the Function ========*/

void Display(struct Array arr);

int main(){

    /*========== Initialize the structure =========*/
    struct Array arr;

    printf("Enter the size of teh Array : ");
    scanf("%d",&arr.size);
    arr.p = (int *)malloc(arr.size * sizeof(int));

    arr.length = 0;

    /* ========= Storing Elementing =========*/
    int n , i;

    printf("Enter How Many Elements you want to store : ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&arr.p[i]);
    
    arr.length = n;

    /*========== Print All Elemnts =========*/

    printf("=========== Printing All the elements =========\n");
    Display(arr);

    return 0;
}

void Display(struct Array arr){
    int i;
    for(int i = 0; i < arr.length ; i++){
        printf("%d \t", arr.p[i]);
    }
}