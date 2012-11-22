CFLAGS=-Wall

tout: tableaux trans-pour-web

bin:
	mkdir -p bin/

tableaux: bin
	gcc ${CFLAGS} -o bin/$@ $@.c

trans-pour-web: bin
	gcc ${CFLAGS} -o bin/$@ $@.c
