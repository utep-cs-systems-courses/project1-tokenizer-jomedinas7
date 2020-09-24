Lab1 : tokenizer.o history.o simpleUI.o
	cc -o Lab1 tokenizer.o history.o simpleUI.o

clean:
	rm -f *.o Lab1

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c

simpleUI.o: history.h tokenizer.h simpleUI.c
