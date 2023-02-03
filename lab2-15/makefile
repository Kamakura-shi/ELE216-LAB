EXECDIR = Debug
INCLUDES_PATH = includes
SRC_PATH = src

$(shell mkdir -p $(EXECDIR))

$(EXECDIR)/main: main.c $(SRC_PATH)/*.c $(INCLUDES_PATH)/*.h
	gcc -g -o $(EXECDIR)/main -I $(INCLUDES_PATH) main.c $(SRC_PATH)/*.c

clean:
	rm -rf $(EXECDIR)