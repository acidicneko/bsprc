CC = gcc
CFILES = $(shell find src/ -type f -name '*.c')
OFILES = $(CFILES:.c=.o)

home = $(HOME)

TARGET = build/bsprc

.PHONY = clean test all install

$(TARGET): $(OFILES)
	@echo [LD] $(TARGET)
	@$(CC) $(OFILES) -o $@

%.o: %.c
	@echo [CC] $@
	@$(CC) -I src/include/ -c $< -o $@

clean:
	@echo [CLEAN]
	@rm $(OFILES) $(TARGET)

all: clean $(TARGET)

install:
	@echo [INSTALL]
	@cp $(TARGET) $(home)/.config/bspwm/bsprc