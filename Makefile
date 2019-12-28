CC=gcc
FLAGS = -Wall
SOURCE=powercontrol.c
OUT=powercontrold
INSTALL_PATH=/usr/local/bin
SYSTEMD_SERVICE_PATH=/lib/systemd/system

powercontrol: $(SOURCE)
	$(CC) $(FLAGS) -lwiringPi -o $(OUT) $(SOURCE)

clean:
	rm -rf *.o $(OUT) *.dSYM

install:
	cp $(OUT) $(INSTALL_PATH)/$(OUT)
	cp $(OUT).service $(SYSTEMD_SERVICE_PATH)/$(OUT).service
	echo "Start daemon with 'systemctl start $(OUT).service'"

uninstall:
	echo "Uninstalling..."
	rm -rf $(SYSTEMD_SERVICE_PATH)/$(OUT).service
	rm -rf $(INSTALL_PATH)/$(OUT)
