#include <stdlib.h>
#include <stdio.h>

// function prototypes
int rand(void);
void srand(unsigned int seed);


// main function
int main(void){
    printf("random num is %d", rand());

    return 0;
}

int rand(void){
    return RAND_MAX;
}