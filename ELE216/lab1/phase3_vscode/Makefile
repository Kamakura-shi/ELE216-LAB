EXECDIR = Debug
INCLUDES_PATH = includes
SRC_PATH = src

$(shell mkdir -p $(EXECDIR))

$(EXECDIR)/app : main.c $(SRC_PATH)/*.c $(INCLUDES_PATH)/*.h
	gcc -g -o $(EXECDIR)/app -I $(INCLUDES_PATH) main.c $(SRC_PATH)/*.c
	./$(EXECDIR)/app

clean:
	rm -rf $(EXECDIR)