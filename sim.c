/*
    1. Problem
    1.1 Sub-Problem-1
    Write a “C” program to generate 100 random integers which can then be converted to random numbers (RNs) uniformly distributed between 0.0 and 1.0 i.e. U(0,1).
    Hint:
    - Use RAND_MAX to convert random integer to a random number.
    - Uniformly distributed: means it is equally likely to generate any number in the range.

    1.2 Sub-Problem-2
    Use the Uniform Random Number Generator you have developed in (2.1) to solve the problem which is given below:
    • Assume that there are just 3 possible values for Service Time (Ts) of customers arriving at a bank (with single server).
    • Need to transform each RN to a service time of a given probability.
    • Assume each customer spends either 4, 8 or 12 minutes at the bank.
    • Proportion of each service duration is 35%, 50% and 15% respectively.

    Write a random number generator which will generate 100 customers, 
    display the numbers on the screen and count the number of each type 
    (1, 2 or 3) of Ts generated. Your program should list them as:

    2. Verification
    Verify that the probabilities assigned to have roughly been met. 
    Continue to run the same experiment by increasing the number of TSs to be generated to 1000. 
    Comment on your new results and come to a conclusion. Compare with expected values and comment 
    on the results.

    Bonus
    Repeat experiment used in the “verification” part above with 10 sets of different runs 
    (using different seeds and streams of RNs)

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// function prototypes
double randNum(void);
void srand(unsigned int seed);
void sim100();
void sim1000();
void bonus_sim();
void simloop(int *a, int *b, int *c, int d);
void print_summary(int a, int b, int c);
void print_avg_summary(int a, int b, int c);
void print_probabilities(int a, int b, int c, int ntotal);


// generate random number
double randNum(void){
    return  ((double)rand() / RAND_MAX);
}

// main function
int main(void){
    /*
        service time : probability : cumulative probability
        Ts-1 => 4 : 0.35 : 0.35
        Ts-2 => 8 : 0.50 : 0.85
        Ts-3 => 12 : 0.15 : 1.00
    */

    // run simulations
    sim100();
    sim1000();
    bonus_sim();

    return 0;
}


void simloop(int *a, int *b, int *c, int d){
    // loop to generate random numbers
    for (int n = 1; n <= d; n++){
    double r = randNum();

        if (r <= 0.35) {
            *a += 1;
            printf("Random number %d = %f -> assigned Ts (Service time) -> Ts-1 ( 4 mins.) \n", n, r);
        }
        else if (r > 0.35 && r <= 0.85) {
            *b += 1;
            printf("Random number %d = %f -> assigned Ts (Service time) -> Ts-2 ( 8 mins.) \n", n, r);
        }
        else {
            *c += 1;
            printf("Random number %d = %f -> assigned Ts (Service time) -> Ts-3 (12 mins.) \n", n, r);
        }
    }
}


void print_summary(int a, int b, int c){
    printf("\n Number of each Ts Type: \n"
            "Ts-1: %d \n"
            "Ts-2: %d \n"
            "Ts-3: %d \n", a, b, c);
} 


void print_avg_summary(int a, int b, int c) {
    printf("\n Averaged Summary of Results: \n"
        "Ts-1(average of 10 runs): %d \n"
        "Ts-2(average of 10 runs): %d \n"
        "Ts-3(average of 10 runs): %d \n", a/10, b/10, c/10);
}


void print_probabilities(int a, int b, int c, int tt){
    // calculate percentage probabilities
    double p1, p2, p3;   
    p1 = ((double) a / tt) * 100;
    p2 = ((double) b / tt) * 100;
    p3 = ((double) c / tt) * 100;

    printf("\n Proportion of each Ts Type: \n"
            "Ts-1: %.3f% \n"
            "Ts-2: %.3f% \n"
            "Ts-3: %.3f% \n", p1, p2, p3);
}


// simulation with 100 trials
void sim100() {
    int x1 = 0, x2 = 0, x3 = 0, xtrials = 100, xtotal;
    // seed - current time + 100
    srand(time(0) + 100); 
    printf("\n RNG AND SERVICE TIME SIMULATION 100 Trials \n");
    simloop(&x1, &x2, &x3, xtrials);

    // total number of trials
    xtotal = x1 + x2 + x3;

    // summary of results
    print_summary(x1, x2, x3);

    // calculate and print proportions of each Ts Type
    print_probabilities(x1, x2, x3, xtotal);
}


// simulation with 1000 trials
void sim1000() {
    int y1 = 0, y2 = 0, y3 = 0, ytrials = 1000, ytotal;
    // seed - current time + 1000
    srand(time(0) + 1000); 
    printf("\n RNG AND SERVICE TIME SIMULATION 1000 Trials \n");
    simloop(&y1, &y2, &y3, ytrials);

    // total number of trials
    ytotal = y1 + y2 + y3;

    // summary of results
    print_summary(y1, y2, y3);

    // calculate and print proportions of each Ts Type
    print_probabilities(y1, y2, y3, ytotal);
}


// bonsus simulation for 10 seeded runs and streams of 1000
void bonus_sim() {
    int n1 = 0, n2 = 0, n3 = 0, ntrials = 1000, ntotal; 

    printf("\n**BONUS RNG, Service Time SIMULATION**");
    for (int i = 1; i <= 10; i++) {
        // seeding each run
        srand(time(0) + i); 
        printf("\n*Seeded RUN %d*\n", i);
        simloop(&n1, &n2, &n3, ntrials);
    }
    // total number of trials
    ntotal = n1 + n2 + n3;

    // summary of results
    print_avg_summary(n1, n2, n3);

    // calculate and print proportions of each Ts Type
    print_probabilities(n1, n2, n3, ntotal);
}


