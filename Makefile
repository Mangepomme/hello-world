KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

MODULE_NAME := chip

obj-m := main.o

all:
	make -C "$(KDIR)" SUBDIRS="$(PWD)" modules

install:
	make -C "$(KDIR)" SUBDIRS="$(PWD)" modules_install

clean:
	make -C "$(KDIR)" SUBDIRS="$(PWD)" clean
