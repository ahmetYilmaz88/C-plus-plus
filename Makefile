# Makefile for 2020-summer-cs202-pa12

PROJ=pa12
TESTDIR=/home/shared/cs202/$(PROJ)

CXX=/usr/bin/clang++
OPTIONS=-std=c++14 -Weverything -g \
	-Werror=return-type -Wold-style-cast \
	-Wno-padded -Wno-c++98-c++11-compat -Wno-c++98-compat

SRCS=String.cpp pa12.cpp
HDRS=String.h String.h
OBJS=String.o pa12.o
EXE=$(PROJ)

$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE) $(OPTIONS)

String.o: String.cpp String.h
	$(CXX) -c String.cpp $(OPTIONS)

pa12.o: pa12.cpp String.h
	$(CXX) -c pa12.cpp $(OPTIONS)

judge:
	@judge -p $(EXE) -i $(TESTDIR)/$(PROJ)-input0.txt -o $(TESTDIR)/$(PROJ)-output0.txt -l || :
	@judge -p $(EXE) -i $(TESTDIR)/$(PROJ)-input1.txt -o $(TESTDIR)/$(PROJ)-output1.txt -l || :

clean:
	@rm -f $(OBJS) $(EXE) *.gch *.log

turnin: pa11 judge
	@cpplint --filter=-,+legal/copyright $(SRCS) $(HDRS)
	@echo
	turnin -c cs202 -p $(PROJ) -v $(HDRS) $(SRCS) Makefile

