CFLAGS = -std=c++14 -O2 -pthread -Wall

MAIN_FILES = client.cpp ./client/clnt.cpp ../net_helper/net_helper.cpp ../package/package.cpp
LOGGER = ../log/logger.cpp
APP_NAME = client_app

UserClientTest:
	g++ $(CFLAGS) -o $(APP_NAME) $(MAIN_FILES) $(LOGGER)

.PHONY: rebuild run clean

rebuild:
	rm -f $(APP_NAME)
	make

run:
	rm -f $(APP_NAME)
	make
	./$(APP_NAME)

clean:
	rm -f $(APP_NAME)