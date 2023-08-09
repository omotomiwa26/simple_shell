COMPILE = -Wall -Wextra -Werror -pedantic -std=gnu89 -g

LEAK = -s --leak-check=full --show-leak-kinds=all --track-origins=yes 

betty-check:
	betty shell.h *.c

run:
	gcc $(COMPILE) *.c -o hsh

val:
	valgrind $(LEAK) ./hsh
