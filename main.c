#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		printf("Usage: %s <file>\n", argv[0]);
		return 0;
	}

	char *file_name = argv[1];

	int fd = open(file_name, O_RDONLY);
	if (fd == -1) {
		err(0, "open %s", file_name);
	}

	char buf[4];
	ssize_t bytes_read = read(fd, buf, sizeof(buf));

	if (bytes_read == -1) {
		err(0, "read %s", file_name);
	}

	if (close(fd) == -1) {
		warn(0, "close %s", file_name);
	}

	return bytes_read == 4 && (buf[0] != '\x89' || buf[1] != 'P' || buf[2] != 'N' || buf[3] != 'G');
}
