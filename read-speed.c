#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#define SIZE (100 * 1024 * 1024)
#define INCREMENT (100 * 1024 * 1024)

void output(struct timeval begin, long long bytes) {
	struct timeval now;

	gettimeofday(&now, NULL);

	double old = begin.tv_sec + begin.tv_usec / 1000000.0;
	double new = now.tv_sec + now.tv_usec / 1000000.0;

	printf("%lld %lf: %.6f MB/sec\n", bytes, new - old, bytes / (1024.0 * 1024.0) / (new - old));
}

int main() {
	char s[50000];
	char *buf = malloc(SIZE);

	long long bytes = 0;
	long long obytes = 0;
	struct timeval begin;

	gettimeofday(&begin, NULL);

	while (fgets(s, 50000, stdin)) {
		char *cp = strchr(s, '\n');
		if (cp != NULL) {
			*cp = '\0';
		}

		int fd = open(s, O_RDONLY);
		if (fd < 0) {
			perror(s);
			exit(EXIT_FAILURE);
		}

		ssize_t i;
		while ((i = read(fd, buf, SIZE)) > 0) {
			bytes += i;

			if (bytes > obytes + INCREMENT) {
				output(begin, bytes);
				obytes = bytes;
			}
		}
		if (i < 0) {
			perror(s);
			exit(EXIT_FAILURE);
		}

		close(fd);
	}

	output(begin, bytes);
	return 0;
}
