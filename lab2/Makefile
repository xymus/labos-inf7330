CFLAGS=-Wall

tout: bin/tableaux bin/trans-pour-web

bin:
	mkdir -p bin/

bin/tableaux: bin
	gcc ${CFLAGS} -o $@ tableaux.c

bin/trans-pour-web: bin
	gcc ${CFLAGS} -o $@ trans-pour-web.c
