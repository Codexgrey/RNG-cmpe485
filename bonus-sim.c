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

    printf("\n**BONUS RNG, Service Time SIMULATION**");
    // loop to generate random numbers
    for (int i = 1; i <= 10; i++) {
        // seed random number generator with current time
        int seed = time(0) + 1;
        srand(seed); 
        
        printf("\n*Seeded RUN %d*\n", i);
        for (n = 1; n <= 1000; n++){
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
    }
    

    // summary of results


    printf("\n Averaged Summary of Results: \n"
        "Ts-1(average of 10 runs): %d \n"
        "Ts-2(average of 10 runs): %d \n"
        "Ts-3(average of 10 runs): %d \n", n1/10, n2/10, n3/10);

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

