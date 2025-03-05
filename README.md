# List of files submitted
- sim.c         : source code for sim
- sim.exe       : compile code
- Makefile      : config to help compile, test, clean (working dir) and run codes
- test.sh       : simple script to test codes and report errors
- results.doc   : simulation results


# How-To Guide > LINUX
- Clone repo via ssh (git clone https://github.com/Codexgrey/RNG-cmpe485)
- Depending on your environment, use Makefile as follows;

## To compile and test the codes
- $ `mingw32-make test`
-   OR
- $ `make test` 

## To run simulation and print the results
- $ `mingw32-make run` 
-   OR
- $ `make run` 

## To clean working directory (remove results and all .exe files)
- $ `mingw32-make clean` 
-   OR
- $ `make clean` 


# If you have difficulty using Makefile, please run the following commands...
## Create Results Doc
- $ `touch results.doc`

## Compile Code
- $ `gcc sim.c -o sim 

## Run code and append results to results file
- $ `./sim >> results.doc


# Have a nice day...
