CFLAGS = -std=c++14 -O2

MAIN_FILES = server.cpp ./server/srv.cpp ./net_helper/net_helper.cpp
LOGGER = ./log/logger.cpp
APP_NAME = server_app

ServerTest:
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