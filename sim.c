#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// function prototypes
double randNum(void);
void srand(unsigned int seed);
void sim100();
void sim1000();
void bonus_sim();
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
    int n1 = 0, n2 = 0, n3 = 0, ntotal;
    // seed - current time + 100
    srand(time(0) + 100); 
    printf("\n RNG AND SERVICE TIME SIMULATION 100 Trials \n");

    // loop to generate random numbers
    for (int n = 1; n <= 100; n++){
        double r = randNum();

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
    // total number of trials
    ntotal = n1 + n2 + n3;

    // summary of results
    print_summary(n1, n2, n3);

    // calculate and print proportions of each Ts Type
    print_probabilities(n1, n2, n3, ntotal);
}


// simulation with 1000 trials
void sim1000() {
    int n1 = 0, n2 = 0, n3 = 0, ntotal;
    // seed - current time + 1000
    srand(time(0) + 1000); 
    printf("\n RNG AND SERVICE TIME SIMULATION 1000 Trials \n");

    // loop to generate random numbers
    for (int n = 1; n <= 1000; n++){
        double r = randNum();

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
   // total number of trials
    ntotal = n1 + n2 + n3;

    // summary of results
    print_summary(n1, n2, n3);

    // calculate and print proportions of each Ts Type
    print_probabilities(n1, n2, n3, ntotal);
}


// bonsus simulation for 10 seeded run and streams of 1000
void bonus_sim() {
    int n1 = 0, n2 = 0, n3 = 0, ntotal; 

    printf("\n**BONUS RNG, Service Time SIMULATION**");
    // loop to generate random numbers
    for (int i = 1; i <= 10; i++) {
        srand(time(0)); 
        
        printf("\n*Seeded RUN %d*\n", i);
        for (int n = 1; n <= 1000; n++){
            double r = randNum();
    
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
    // total number of trials
    ntotal = n1 + n2 + n3;

    // summary of results
    print_avg_summary(n1, n2, n3);

    // calculate and print proportions of each Ts Type
    print_probabilities(n1, n2, n3, ntotal);
}


