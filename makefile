OBJ = main.o screen.o 
APPNAME = letter.out

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm
 
%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)

zip : 
	tar cf sound.tar *.c *.h makefile
