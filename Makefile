SOURCE_DIR=src
OBJECT_DIR=Objects
CC=arm-linux-gcc
CFLAGS=-g -Iinc/ -I../includes/

objs=$(OBJECT_DIR)/Damascus_GPIO.o 

all: GPIO
#	$(CC) $(CFLAGS) -o $(OBJECT_DIR)/Damascus.o $(objs)
	ar crv $(OBJECT_DIR)/libDamascus.a $(OBJECT_DIR)/*.o

GPIO:
	$(CC) $(CFLAGS) -c -o $(OBJECT_DIR)/Damascus_GPIO.o $(SOURCE_DIR)/Damascus_GPIO.c
