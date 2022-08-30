NAME = coremark
SRCS = $(shell find -L ./src/ -name "*.c")
include $(AM_HOME)/Makefile.app

yexc-try:
	make ARCH=riscv64-xs-flash

yexc-echo:
	echo $(OBJS)
	echo $(LIBS)

