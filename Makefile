all: lab1 lab2

lab1:
	make -C $@

lab2:
	make -C $@

doc:
	doxygen Doxyfile

# .PHONY permet de forcer l'exécution de certaines règles
.PHONY: lab1 lab2 doc
