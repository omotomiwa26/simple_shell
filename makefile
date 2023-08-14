COMPILE = -Wall -Wextra -Werror -pedantic -std=gnu89 -g

MEMORY_LEAK = -s --leak-check=full --show-leak-kinds=all --track-origins=yes 

betty:
	betty shell.h *.c

run:
	gcc $(COMPILE) *.c -o hsh

leak:
	valgrind $(MEMORY_LEAK) ./hsh
