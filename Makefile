CC=gcc
FLAGS = -Wall
SOURCE=powercontrol.c
OUT=powercontrold

powercontrol: $(SOURCE)
	$(CC) $(FLAGS) -lwiringPi -o $(OUT) $(SOURCE)

clean:
	rm -rf *.o powercontrol *.dSYM

install:
	cp $(OUT) /usr/local/bin/$(OUT)
