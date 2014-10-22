#include "my.h"

/*
 * Author: Jeff Mariconda
 * Class: CS392
 *
 * Pre: Takes a char** vector.
 * Post: Returns a string containing all of the strings in the vector separated by whitespaces.
 */
char *my_vect2str(char **v)
{
	int i, slen, vlen;
    char *str = NULL;
    
    if (v != NULL) {
		for (vlen = 0, slen = 0; v[vlen] != NULL; vlen++)
			slen += my_strlen(v[vlen]) + 1;
            str = vlen > 0 ? (char *)xmalloc(slen) : NULL;
            for (i = 0; i < vlen; i++) {
				str = my_strcat(str, v[i]);
                if (i < vlen - 1)
					str = my_strcat(str, " ");
			}
    }

    return str;
}
