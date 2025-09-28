#include <stdio.h>
#include <stdlib.h>


int main(){
    //Declearation of a file pointer
    FILE *fp;

    // open file in write mode
    fp = fopen("jayat.txt","r");

    if(fp==NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // fprintf(fp,"Hey My Cuite Pie!\n");

    // close the file
    fclose(fp);

    return EXIT_SUCCESS;
}