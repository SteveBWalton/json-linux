#
# Makefile for the json-test program.
#
# Little program to test a little C++ json library in Linux.
#

#
# The processor that this computer is using
#
PROCESSOR = $(shell uname -m)

#
# Libraries
# 	prefix LIBS with -l
# 	prefix LIBDIR with -L
#
LIBS :=
LIBDIR :=

OPTIONS := -Wall -std=c++17

#
# Header files.
#
HEADERS := json-test.h json.h

#
# Source objects (prefix with obj/)
#
OBJS := \
obj/json-test.o \
obj/json.o

bin/json-test : $(OBJS)
	@mkdir -p $(@D)
	g++ $(OPTIONS) -o bin/json-test $(OBJS) $(LIBDIR) $(LIBS)

obj/json-test.o : json-test.cpp $(HEADERS)
	@mkdir -p $(@D)
	g++ -c $(OPTIONS) -o obj/json-test.o json-test.cpp

obj/json.o : json.cpp $(HEADERS)
	@mkdir -p $(@D)
	g++ -c $(OPTIONS) -o obj/json.o json.cpp


clean:
	-rm -f bin/json-test
	-rm -f $(OBJS)

