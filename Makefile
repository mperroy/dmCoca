CC = gcc
CFLAGS = -Wall -g
EXEC = 10K2 G36 kneser72 kneser73 kneser62 kneser83 m47 m95 petersen sierp3

all:$(EXEC)

10K2: graphformat.c exemples/10K2.c
	$(CC) $(CFLAGS) $^ -o $@

G36: graphformat.c exemples/G36.c
	$(CC) $(CFLAGS) $^ -o $@

kneser72: graphformat.c exemples/kneser72.c
	$(CC) $(CFLAGS) $^ -o $@

kneser73: graphformat.c exemples/kneser73.c
	$(CC) $(CFLAGS) $^ -o $@

kneser62: graphformat.c exemples/kneser62.c
	$(CC) $(CFLAGS) $^ -o $@

kneser83: graphformat.c exemples/kneser83.c
	$(CC) $(CFLAGS) $^ -o $@

m47: graphformat.c exemples/m47.c
	$(CC) $(CFLAGS) $^ -o $@

m95: graphformat.c exemples/m95.c
	$(CC) $(CFLAGS) $^ -o $@

petersen: graphformat.c exemples/petersen.c
	$(CC) $(CFLAGS) $^ -o $@

sierp3: graphformat.c exemples/sierp3.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(EXEC)
