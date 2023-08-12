#################################################################
# Makefile to Automate the compilation and execute the code	#
# 1. make 	to compile					#
# 2. make run	to execute the simple shell			#
#################################################################

all:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

run:
	./hsh

clean:
	rm hsh

