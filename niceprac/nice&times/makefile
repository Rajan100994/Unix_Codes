all: simple-sh sim-sh nice nicerun times1 timesrun

simple-sh: simple-sh.c
	gcc -o simple-sh simple-sh.c
	
sim-sh :
	./simple-sh

nice: nice.c
	gcc nice.c error.c -o nice

nicerun:
	./nice  

times1: times1.c 
	gcc times1.c error.c prexit.c -o times1

timesrun:
	./times1 "sleep 5"   "date"   "man bash > /dev/null"
