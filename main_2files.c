/*
** This main shows the output from 2 different files.
*/

#include "get_next_line.h"
#include <stdio.h>

int main (void)
{
	int fd1;
	int fd2;
	int ret1;
	int ret2;
	char *line_file1;
	char *line_file2;
	fd1 = open("tests/test4.txt", O_RDONLY);
	fd2 = open("tests/test5.txt", O_RDONLY);


//	printf("fd1:|%d|\n", fd1);
//	printf("fd2:|%d|\n", fd2);
	while((ret1 = get_next_line(fd1, &line_file1)) && (ret2 = get_next_line(fd2, &line_file2)))
	{
		if (ret1 > 0 && ret2 > 0)
		{
			printf("File1:|%d||%s|\n", ret1, line_file1);
			free(line_file1);
			printf("File2:|%d||%s|\n\n", ret2, line_file2);
			free(line_file2);
		}
		if (ret1 == -1 || ret2 == -1)
		{
			printf("One of the files doesnt exist");
			break;
		}
	}
	ret1 = get_next_line(fd1, &line_file1);
	ret2 = get_next_line(fd2, &line_file2);
	printf("File 1:|%d||%s|\n", ret1, line_file1);
	printf("File 2:|%d||%s|\n\n", ret2, line_file2);
}
