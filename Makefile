CC = gcc
CFLAGS = -Wall -Wextra -std=c99

output: SalesReport NFL-score

SalesReport: SalesReport.c
	$(CC) $(CFLAGS) -o SalesReport SalesReport.c

NFL-score: NFL-score.c
	$(CC) $(CFLAGS) -o NFL-score NFL-score.c

clean:
	rm -f SalesReport NFL-score
	
