CFLAGS = -std=c11

fsm: fsm.c
	cc fsm.c
test: fsm
	./fsm example1.fsm abccc