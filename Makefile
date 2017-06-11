# all
all: main.o highway.o
	g++ main.o highway.o -o main

main.o: main.cpp highway.h 
	gcc -c -g main.cpp 

highway.o: highway.cpp highway.h
	gcc -c -g highway.cpp

# clean
#clean: rm -f *.o main

clean: .clean-post

.clean-pre:
# Add your pre 'clean' code here...

.clean-post: .clean-impl
# Add your post 'clean' code here...


# include project implementation makefile
include nbproject/Makefile-impl.mk

# include project make variables
include nbproject/Makefile-variables.mk
