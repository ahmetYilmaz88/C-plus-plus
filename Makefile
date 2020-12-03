# Makefile for 2020-summer-cs202-pa13

CXX=/usr/bin/clang++
CXXFLAGS=-std=c++14 -Weverything -g \
        -Werror=return-type -Wno-padded -Wold-style-cast \
        -Wno-c++98-c++11-compat -Wno-c++98-compat

pa13: pa13.o String.o
	$(CXX) -o pa13 pa13.o String.o $(CXXFLAGS)

pa13.o: pa13.cpp String.h
	$(CXX) -c pa13.cpp $(CXXFLAGS)

String.o: String.cpp String.h
	$(CXX) -c String.cpp $(CXXFLAGS)

test: pa13-test.cpp String.o catch.hpp
	$(CXX) -o pa13-test pa13-test.cpp String.o $(CXXFLAGS)
	@[ -f pa13-test ] && ./pa13-test

clean:
	@rm -rf pa13.o String.o pa13 pa13-test

turnin:
	turnin -c cs202 -p pa13 -v pa13.cpp String.cpp String.h pa13-test.cpp catch.hpp Makefile
