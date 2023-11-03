CC = gcc
CFLAGS = -Wall -Wextra
TARGETS = caesar caesar1 caesarrecreate caesarfile2 caesarfile

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
