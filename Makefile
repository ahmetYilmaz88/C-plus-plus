# Makefile for 2020-summer-cs202-pa10

CXX=/usr/bin/clang++
OPTIONS=-std=c++14 -Weverything -g \
	-Werror=return-type -Wno-padded -Wold-style-cast \
	-Wno-c++98-c++11-compat -Wno-c++98-compat

pa10: pa10.o Polygon.o 
	$(CXX) pa10.o Polygon.o -o pa10 $(OPTIONS)

pa10.o: pa10.cpp Polygon.h
	$(CXX) -c pa10.cpp $(OPTIONS)

Polygon.o: Polygon.cpp Polygon.h
	$(CXX) -c Polygon.cpp $(OPTIONS)

clean:
	@rm -f *.o pa10

turnin:
	@cpplint --filter=-,+legal/copyright pa10.cpp Polygon.h Polygon.cpp
	turnin -c cs202 -p pa10 -v pa10.cpp Polygon.h Polygon.cpp Makefile
