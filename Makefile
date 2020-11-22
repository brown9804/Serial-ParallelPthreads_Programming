##------------C project makefile------------------------------------
## Copyright (C) 2020 by Brown, Belinda.
## timna.brown@ucr.ac.cr
##-------------------------------------------------------------------


# 							Makefile logic:
# To create this file you need these files:
# $ @ replace left
# $ ^ right


####### PATHS  
LIB = ./lib/
SRC = ./src/
EXC = ./exc/

####### ALL 
.PHONY: all
all: main.o
	$(EXC)main.o

%.o: $(SRC)%.c
	gcc -pthread $^ -o $(EXC)$@


.PHONY: clean
clean:
	rm -f $(EXC)*.o *.o
