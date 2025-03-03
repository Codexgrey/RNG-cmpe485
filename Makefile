all: sim

sim:
	gcc sim.c -o sim

clean:
	rm sim

test: sim
	bash test.sh