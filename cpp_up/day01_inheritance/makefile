.PHONY:all
	 

all:test Person_Student  virtual

test:test.cc
	g++ $^ -o $@ -std=c++11

Person_Student:Person_Student.cc 
	g++ $^ -o $@

virtual:virtual.cc 
	g++ $^ -o $@
