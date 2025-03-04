all: sim bonus-sim

sim: # compile sim bonus-sim, create results.doc
	gcc sim.c -o sim
	gcc bonus-sim.c -o bonus-sim
	touch results.doc

clean: 
	rm sim bonus-sim results.doc

run:
	./sim >> results.doc
	sleep 2 
	./bonus-sim >> results.doc
#	./sim | tee results.txt
#	./sim > results.txt

test: sim bonus-sim
	bash test.sh