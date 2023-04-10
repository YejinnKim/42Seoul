#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 

typedef struct s_info
{
    int w;
    int h;
    char c;
} t_info;

typedef struct s_rect
{
    char type;
    float x;
    float y;
    float w;
    float h;
    char c;
} t_rect;


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

void set_rect(t_rect *rect, t_info *info, char arr[300][300])
{
    int i=0;
    int j;

    while (i < info->h)
    {
        j = 0;
        while (j < info->w)
        {
            if (i >= rect->y && j >= rect->x && i <= rect->y + rect->h && j <= rect->x + rect->w)
            {
                if (j - rect->x < 1 || (rect->x + rect->w) - j < 1 || i - rect->y < 1 || (rect->y + rect->h) - i < 1)
                    arr[i][j] = rect->c;
                if (rect->type == 'R')
                    arr[i][j] = rect->c;
            }
            j++;
        }
        i++;
    }
}

int draw_rect(FILE *file, t_info *info, char arr[300][300])
{
    t_rect rect;
    int ret;

    while((ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.c)) == 6)
    {
		if (!(rect.type == 'r' || rect.type == 'R'))
			return (1);
		if (rect.w <= 0 || rect.h <= 0)
			return (1);
        set_rect(&rect, info, arr);
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
        return (print_error("Error: arguments\n"));
    file = fopen(argv[1], "r");
    if (!file)
        return (print_error("Error: Operation file corrupted\n"));
    if (init_arr(file, &info, arr))
        return (print_error("Error: Operation file corrupted\n"));
    if (draw_rect(file, &info, arr))
		return (print_error("Error: Operation file corrupted\n"));
    print_arr(&info, arr);
    fclose(file);
    return (0);
}