.PHONY:all 

all:reader write

write:write.c myshm.h
	gcc write.c -o write

reader:reader.c myshm.h
	gcc reader.c -o reader
