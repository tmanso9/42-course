/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:23:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/10/28 15:24:24 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *decode(char *buffer, char *result) {
	int offset = 0;

	while (*buffer)
	{
		if (*buffer >= '0' && *buffer <= '9') {
			int size = atoi(buffer);
			for (int i = 0; i < size; i++) {
				result[offset] = (offset % 26) + 'a';
				offset++;
			}
			while(*buffer >= '0' && *buffer <= '9') {
				buffer++;
			}
		} else if (*buffer == '\n') {
			result[offset++] = '\n';
			buffer++;
		} else {
			fprintf(stderr, "Fix your shit");
		}
	}
	result[offset] = 0;
	return result;
}

int count_lines(char *str) {
	int i = 0;
	char *s = str;
	while(s != NULL) {
		s = strchr(s, '\n');
		if (s != NULL)
			s++;
		i++;
	}
	if (str[strlen(str) - 1] == '\n')
		i--;
	return i;
}

char *get_line(char *s, int i) {
	while(*s && i > 0) {
		if (*s == '\n')
			i--;
		s++;
	}
	if (i > 0 || *s == 0) return NULL;
	char *next = strchr(s, '\n');
	if (next) {
		char *res = calloc(next - s + 2, 1);
		strncpy(res, s, next - s + 2);
		res[next - s + 1] = 0;
		return res;
	} else {
		return strdup(s);
	}
}

int main()
{/*
	int	fd = open("teste", O_RDONLY);
	char *line_read = get_next_line(fd);
	printf("%s", line_read);
	free(line_read);
	close(fd);
	line_read = get_next_line(fd);
	printf("%s", line_read);
	free(line_read);
	fd = open("get_next_line.c", O_RDONLY);
	line_read = get_next_line(fd);
	printf("%s", line_read);
	free(line_read);
	line_read = get_next_line(fd);
	printf("%s", line_read);
	free(line_read);
	line_read = get_next_line(fd);
	printf("%s", line_read);
	free(line_read);
	line_read = get_next_line(fd);
	printf("%s", line_read);
	free(line_read);
	return (0);
	
	char	*buf = malloc(BUFFER_SIZE + 1);
	int	b_read = read(fd, buf, BUFFER_SIZE);
	buf[b_read] = 0;
	printf("%d\n", b_read);
	printf("%s\n", buf);
	free(buf);
	close(fd);
	buf = malloc(BUFFER_SIZE + 1);
	b_read = read(fd, buf, BUFFER_SIZE);
	if (b_read > -1)
		buf[b_read] = 0;
	else
		buf[0] = 0;
	printf("%d\n", b_read);
	if (strlen(buf) > 0)
		printf("buf is %s\n", buf);
	fd = open("teste", O_RDONLY);
	b_read = read(fd, buf, BUFFER_SIZE);
	buf[b_read] = 0;
	printf("%d\n", b_read);
	printf("%s\n", buf);
	free(buf);
	*/
	char *tests[18] = {"9", "9\n", "10", "10\n", "11", "11\n", "19", "19\n", "20", "20\n", "21", "21\n",
		"9\n9\n", "9\n10", "9\n10\n",
		"10\n8\n", "10\n9", "10\n9\n"
	};

	char content[10000];
	for (int i = 0; i < 18; i++) {
		decode(tests[i], content);
	FILE * file = fopen("limits.txt", "w");
	fprintf(file, "%s", content);
	fclose(file);
	}
	int lines = count_lines(content) + 1;
	printf("%d\n", lines);
	int	fd = open("limits.txt", O_RDONLY);
	for (int i = 0; i < lines; i++) {
		//char *expected = get_line(content, i);
		char	*expected = get_next_line(fd);
		printf("%s", expected);
		//test_gnl_limits(fd, expected, i, content);
		if (expected != NULL)
			free(expected);
	}
	close(fd);
}

