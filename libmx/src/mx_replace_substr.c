#include "libmx.h"

static char *give_new(const char *str, const char *sub, const char *replace);
char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
 	if (!str || !sub || !replace)
         return NULL;

	return give_new(str, sub, replace);
} 

static char *give_new(const char *str, const char *sub, const char *replace)
{
	int count = mx_count_substr(str, sub);
	int len_replace = mx_strlen(replace);
	int len_sub = mx_strlen(sub);
	char *new = mx_strnew(mx_strlen(str) 
	- (count * len_sub) + (count * len_replace));
	char *new_copy = new;

	while (*str) {
		if (mx_strstr(str, sub) == str) {
			mx_strcpy(new_copy, replace);	
			new_copy += len_replace;
			str += len_sub;
		}
		else 
			*new_copy++ = *str++;
	}
	return new;
}
