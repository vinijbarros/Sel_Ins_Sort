## MAKEFILE SEL_INS_SORT ##


sel_ins_sort:	sel_ins_sort.o 
	gcc sel_ins_sort.o 	-o sel_ins_sort

sel_ins_sort.o:	sel_ins_sort.c
	gcc -c sel_ins_sort.c

clean:
	rm *.o
