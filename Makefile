SOURCE = main.c 
COMPILER = gcc   
FLAGS = -Wall -Wextra  -g -std=c11 
all: 
	${COMPILER} ${FLAGS} ${SOURCE} -o linux
	
