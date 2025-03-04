#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// function prototypes
double randNum(void);
void srand(unsigned int seed);


// generate random number
double randNum(void){
    return  ((double)rand() / RAND_MAX);
}


// main function
int main(void){
    int n, n1 = 0, n2 = 0, n3 = 0, ntotal;
    double r;

    /*
        service time : probability : cumulative probability
        Ts-1 => 4 : 0.35 : 0.35
        Ts-2 => 8 : 0.50 : 0.85
        Ts-3 => 12 : 0.15 : 1.00
    */

    // seed random number generator with current time
    srand(time(0)); 
    int ntrials = 1000; printf("\n RNG AND SERVICE TIME SIMULATION %d Trials \n", ntrials);

    // loop to generate random numbers
    for (n = 1; n <= ntrials; n++){
        r = randNum();

        if (r <= 0.35) {
            n1 += 1;
            printf("Random number %d = %f -> assigned Ts (Service time) -> Ts-1 ( 4 mins.) \n", n, r);
        }
        else if (r > 0.35 && r <= 0.85) {
            n2 += 1;
            printf("Random number %d = %f -> assigned Ts (Service time) -> Ts-2 ( 8 mins.) \n", n, r);
        }
        else {
            n3 += 1;
            printf("Random number %d = %f -> assigned Ts (Service time) -> Ts-3 (12 mins.) \n", n, r);
        }
    }

    // summary of results
    printf("\n Number of each Ts Type: \n"
        "Ts-1: %d \n"
        "Ts-2: %d \n"
        "Ts-3: %d \n", n1, n2, n3);

    // calculate and print proportions of each Ts Type
    ntotal = n1 + n2 + n3; 
    double p1, p2, p3;

    p1 = ((double) n1 / ntotal) * 100;
    p2 = ((double) n2 / ntotal) * 100;
    p3 = ((double) n3 / ntotal) * 100;

    printf("\n Proportion of each Ts Type: \n"
        "Ts-1: %f% \n"
        "Ts-2: %f% \n"
        "Ts-3: %f% \n", p1, p2, p3);


    return 0;
}

