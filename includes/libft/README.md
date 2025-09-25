# LIBFT-PRINTF-GNL
This is a personal library used for 42 projects, which often don't let you use libraries outside of <stdio.h> or <unistd.h>.


Milestone 0 includes the project of Libft and Milestone 1 includes the projects of ft_printf, get_next_line and Born2BeRoot (a virtual machine I can't upload to git). Since the three projects are basically replicating already existing functions to understand how they work, and you are allowed to mix them all to make a library to use in bigger projects, I decided to put them all together in the same repo.


**This repo does not comply with 42's formatting rules.** I did these projects back in late 2024 and have been rewriting them as of September 2025 with a better understanding of C. This rewrite completely ignores "norminette" (42's formatting rules) and the subject guidelines about the amount of files and their names. Otherwise, the functions work the same as the ones I originally submitted.



## SOURCES

FT_CONVERT: character case and strings conversion
```
- ft_toupper: changes a string to uppercase
- ft_tolower: changes a string to lowercase
- ft_atoi: turns a character to an intenger
- ft_itoa: turns an integer to a character
```


FT_ISX: determines a character's category
```
- ft_isalpha: checks if it's a character (a-z, A-Z)
- ft_isdigit: checks if it's a number (0-9)
- ft_isalnum: checks if it's a characters or number
- ft_isascii: checks if it's an ascii character (0 - 127, NULL - DEL)
- ft_isprint: check if it's printable (' ' - ~, 32 - 126)
```


FT_LST: linked list management
```
- ft_lstnew: creates a new node
- ft_lstsize: returns the list's length
- ft_lstadd_front: adds a node to the top of the list
- ft_lstadd_back: adds a node to the bottom of the list
- ft_lstlast: returns the last node of the list
- ft_lstiter: iterates a function through every node of the list
- ft_lstmap: creates a new list by iterating a function through every node
- ft_lstdelone: deletes one node (specified)
- ft_lstclear: deletes teh whole list
```


FT_MEMORY: memory managemnet and allocation
```
- ft_memcpy: copies n bytes of a memory space to another
- ft_memchr: finds the first instance of a character in an specific memory space
- ft_memcmp: compares two memory spaces to check which one's bigger
- ft_memmove: copies n bytes of memory from a space to another and returns a pointer to the copy
- ft_memset: fills a memory space with a given character
- ft_fbzero: fills a memory space with 0s
- ft_calloc: allocates a memory space and fills it with 0s
```

FT_PRINTF:
```
- ft_printf: replicates printf() behaviour (only accepts c, s, d, i, u, p, x, X and %)
```

FT_PUTFD:
```
- ft_putchar_fd: writes a character in a fd
- ft_putstr_fd: writes a string in a fd
- ft_putendl_fd: writes a string in a fd and ends it with a new line
- ft_putnbr_fd: writes a number in a fd
```

FT_SPLIT:
```
- ft_split: splits a string into a matrix (string of strings) by using a character as separator
```


FT_STR:
```
- ft_strlen: returns the length of a string
- ft_strncmp: compares two strings and returns which one's bigger (only up to n bytes)
- ft_strlcpy: copies a string to another and returns the length of the copy
- ft_strdup: duplicates a string
- ft_strlcat: concatenates two strings and returns the length
- ft_strjoin: concatenates two strings and returns the new string
- ft_substr: extracts a string from another using delimiters
- ft_strtrim: cuts a set of characters from the start and end of a string
- ft_strchr: finds the first instance of a character in a string
- ft_strrchr: finds the last instance of a character in a string
- ft_strnstr: finds a string within another string (only up to n bytes)
- ft_striteri: iterates a function through every character of a string
- ft_strmapi: creates a new string by iterarting a function through every character of a string
```


GET_NEXT_LINE:
```
- ft_get_next_line: reads a fd line by line, using a static variable to keep track between calls
```
