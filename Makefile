xwatcher: xwatcher.c
	$(CC) $(CFLAGS) xwatcher.c -o xwatcher -lX11

.PHONY: test clean

test: xwatcher
	./xwatcher

clean:
	rm -f xwatcher
