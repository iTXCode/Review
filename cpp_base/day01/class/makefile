.PHONY:class

FLAG=-std=c++11

all:class copy_c test  friend  const_class

class:class.cc
	g++ $^ -o $@ $(FLAG)

#copy_c:copy_c.cc
#	g++ $^ -o $@ $(FLAG)

test:test.cc 
	g++ $^ -o $@ $(FLAG)

friend:friend.cc 
	g++ $^ -o $@ 

const_class:const_class.cc 
	g++ $^ -o $@
