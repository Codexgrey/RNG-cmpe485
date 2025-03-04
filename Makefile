all: sim bonus-sim

sim:
	gcc sim.c -o sim
	gcc bonus-sim.c -o bonus-sim
	touch results.doc

clean:
	rm sim bonus-sim results.doc

run:
	./sim >> results.doc && ./bonus-sim >> results.doc
#	./sim | tee results.txt
#	./sim > results.txt

test: sim bonus-sim
	bash test.sh