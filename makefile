.PHONY: clean build run grind

build: clean
	@echo -e "\033[36mCompiling\033[m"
	@gcc -lraylib -g src/*.c -o game

run: build
	@echo -e "\033[32mRunning\033[m"
	@./game

grind: build
	@echo -e "\033[32mTesting\033[m"
	@valgrind ./game

clean:
	@echo -e "\033[33mCleaning\033[m"
	@rm -f game