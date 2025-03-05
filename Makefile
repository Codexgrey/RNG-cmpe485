all: sim

sim: 
	gcc sim.c -o sim
	touch results.doc

clean: 
	rm sim results.doc

run:
	./sim >> results.doc
#	./sim | tee results.txt
#	./sim > results.txt

test: sim
	bash test.sh