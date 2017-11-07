SOURCE_DIR=src
OBJECT_DIR=Objects
CC=arm-linux-gcc
CFLAGS=-g -Iinc/ -I../includes/

all: modules
	ar crv $(OBJECT_DIR)/libDamascus.a $(OBJECT_DIR)/*.o

modules:
	for name in $(wildcard $(SOURCE_DIR)/*.c); \
	do \
		echo "$$name" | awk -F '.' '{print $$1}' | awk -F '/' '{print sprintf("%s.o", $$2)}' | xargs -I {} $(CC) $(CFLAGS) -c -o $(OBJECT_DIR)/{} $$name; \
	done
