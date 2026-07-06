build:
	clang -Iinclude -o nscanner src/main.c lib/scanner.c
run:
	./nscanner