all: stacktest stacktest_dbg stacktest2

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stacktest2: stacktest2.o stack.o
	gcc -g stacktest2.o stack.o -o stacktest2

stacktest_dbg: stacktest.c stack.h
	gcc -g -DDEBUG_TEST -c stacktest.c -o stacktest_dbg.o
	gcc -g stacktest_dbg.o stack.o -o stacktest_dbg

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

stacktest2.o: stacktest2.c stack.h
	gcc -g -c stacktest2.c

stack.o: stack.c stack.h
	gcc -g -c stack.c

docs:
	doxygen
	rsync -p -r /home/rboutayeb/cs2303_hws/cs2303_hw05/html/* /home/rboutayeb/public_html/cs2303_hw05/

clean:
	rm -f *.o stacktest stacktest_dbg
