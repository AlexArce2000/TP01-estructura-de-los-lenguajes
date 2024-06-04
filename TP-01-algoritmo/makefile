all: debug_example

debug_example: debug_example.c
	gcc -g -o debug_example debug_example.c

run: debug_example
	./debug_example

debug: debug_example
	gdb ./debug_example

debug_carga: debug_example
	gdb -x debug_script.gdb ./debug_example

clean:
	rm -f debug_example
