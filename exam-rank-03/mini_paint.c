#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_info
{
	int w;
	int h;
	char c;
} t_info;

typedef struct s_circ
{
	char type;
	float x;
	float y;
	float r;
	char c;
} t_circ;

int print_error(char *str)
{
	int i=0;

	while (str[i])
		write(1, &str[i++], 1);
	return (1);
}

void print_arr(t_info *info, char arr[300][300])
{
	int i=0;
	int j;

	while (i < info->h)
		{
			j = 0;
			while (j < info->w)
			{
				write(1, &arr[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
}

int init_arr(FILE *file, t_info *info, char arr[300][300])
{
	int i=0;
	int j;

	if (fscanf(file, "%d %d %c\n", &info->w, &info->h, &info->c) == 3)
	{
		if (!(info->w > 0 && info->w <= 300 && info->h > 0 && info->h <= 300))
			return (1);
		while (i < info->h)
		{
			j = 0;
			while (j < info->w)
			{
				arr[i][j] = info->c;
				j++;
			}
			i++;
		}
	}
	else
		return (1);
	return (0);
}

void set_circ(t_circ *circ, t_info *info, char arr[300][300])
{
	int i=0;
	int j;
	float dist;

	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			dist = sqrtf((j - circ->x) * (j - circ->x) + (i - circ->y) * (i - circ->y));
			if (dist <= circ->r)
			{
				if (circ->r - dist < 1)
					arr[i][j] = circ->c;
				if (circ->type == 'C')
					arr[i][j] = circ->c;
			}
			j++;
		}
		i++;
	}
}

int draw_circ(FILE *file, t_info *info, char arr[300][300])
{
	t_circ circ;
	int ret;

	while ((ret = fscanf(file, "%c %f %f %f %c\n", &circ.type, &circ.x, &circ.y, &circ.r, &circ.c)) == 5)
	{
		if (!(circ.type == 'c' || circ.type == 'C'))
			return (1);
		if (circ.r <= 0)
			return (1);
		set_circ(&circ, info, arr);
	}
	if (ret != EOF)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	FILE *file;
	char arr[300][300];
	t_info info;

	if (argc != 2)
		return (print_error("Error: argument\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (print_error("Error: Operation file corrupted\n"));
	if (init_arr(file, &info, arr))
		return (print_error("Error: Operation file corrupted\n"));
	if (draw_circ(file, &info, arr))
		return (print_error("Error: Operation file corrupted\n"));
	print_arr(&info, arr);
	fclose(file);
	return (0);
}