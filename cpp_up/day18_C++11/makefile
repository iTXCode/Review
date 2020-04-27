.PHONY:all 

all:test  pthread 

test:test.cc
	g++ $^ -o $@

pthread:pthread.cc 
	g++ $^ -o $@ -lpthread
