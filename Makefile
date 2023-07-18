TARGET=add-nbo
CFLAGS=-g

all: $(TARGET)

$(TARGET): add-nbo.o
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o
