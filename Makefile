executer: compiler
	./mini_shell
compiler:
	gcc mini_shell.c mini_memory.c mini_string.c mini_io.c -o mini_shell -Wall
	gcc mini_touch.c mini_memory.c mini_string.c mini_io.c -o mini_touch -Wall
	gcc mini_cp.c mini_memory.c mini_string.c mini_io.c -o mini_cp -Wall
	gcc mini_echo.c mini_memory.c mini_string.c mini_io.c -o mini_echo -Wall
	gcc mini_cat.c mini_memory.c mini_string.c mini_io.c -o mini_cat -Wall
	gcc mini_head.c mini_memory.c mini_string.c mini_io.c -o mini_head -Wall
	gcc mini_tail.c mini_memory.c mini_string.c mini_io.c -o mini_tail -Wall
	gcc mini_clean.c mini_memory.c mini_string.c mini_io.c -o mini_clean -Wall
	gcc mini_grep.c mini_memory.c mini_string.c mini_io.c -o mini_grep -Wall
	gcc wc.c mini_memory.c mini_string.c mini_io.c -o wc -Wall
	gcc main.c mini_memory.c mini_string.c mini_io.c -o main -Wall
