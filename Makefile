export COLORS

DBUILD = .build
LIBS = .lib/ccrush.a
MAPS = maps/*
CFLAGS = -std=c11 -pedantic -Wall -Werror
CC = gcc
OBJECTS = $(DBUILD)/game.o $(DBUILD)/ccrush.o $(DBUILD)/board.o

.PHONY: clean colorize tar charcrush

all: charcrush

$(OBJECTS): $(DBUILD)/%.o: %.c
	mkdir -p $(DBUILD) || rm $(DBUILD)/*
	$(CC) $(CFLAGS) $(COLORS) -c $< -o $@

colorize:
	$(eval COLORS=-DY='"\033[0;33m\u25A0\033[0m"' -DG='"\033[0;32m\u25b2\033[0m"' -DW='"\033[0;37m\u2665\033[0m"' -DP='"\033[0;35m\u25cf\033[0m"' -DB='"\033[0;34m\u25ba\033[0m"' -DR='"\033[0;31m\u2617\033[0m"' -DO='"\033[0;36m\u2663\033[0m"')
	-$(MAKE) clean
	$(MAKE) charcrush

tar:
ifndef USERNAME
	$(error You must set your USERNAME to create the tarball)
endif
	tar --transform 's,^,$(USERNAME)/,' -zcvf $(USERNAME).tar.gz -T .files $(LIBS) $(MAPS)

charcrush: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

clean:
	-@rm charcrush 2>/dev/null || true
	-@rm $(DBUILD)/* 2>/dev/null || true
	@rm *.o 2>/dev/null || true
