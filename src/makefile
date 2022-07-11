all :
	ocamlopt -o test.opt hello_stubs.c thread.ml thread.mli test.ml -cclib -pthread
	ocamlopt -o sem_test.opt hello_stubs.c semaphore.ml semaphore.mli thread.ml thread.mli sem_test.ml -cclib -pthread

thread.cmi : thread.mli
	ocamlc -c thread.mli

semaphore.cmi : semaphore.mli
	ocamlc -c semaphore.mli
