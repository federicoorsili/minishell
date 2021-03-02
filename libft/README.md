# 42'S LIBFT SUBJECT

<h2>MANDATORY PART</h2>
<br>

  **Program name** | <samp>libft.a</samp> 
  -----------------|----------
  **Turn in files** | <samp>*.c, libfth.h, Makefile</samp>
  **Makefile** | Yes 
  **External functs.** | Detailed below 
  **Libft authorized** | Non-applicable 
  **Description** | Write your own library, containing an extract of important functions for your   cursus.
  
<br> 

<h3>Technical considerations</h3>
  
- It is forbidden to use global variables.
- If you need subfunctions to write a complex function, you should define these subfunctions as <code>static</code> to avoid publishing them with your library. It would be a good habit to do this in your future projects as well.
- Submit all files in the root of your repository.
- You must use the command <code>ar</code> to create your librairy, using the command libtool is forbidden.

<br> 

<h3>Part 1 - Libc functions</h3>

In this first part, you must re-code a set of the libc functions, as defined in their man. Your functions will need to present the same prototype and behaviors as the orig- inals. Your functions’ names must be prefixed by “<samp>ft_</samp>”. For instance <samp>strlen</samp> becomes <samp>ft_strlen</samp>.

<samp><b>NOTE</b>: Some of the functions’ prototypes you have to re-code use the
"restrict" qualifier.  This keyword is part of the c99 standard.
It is therefore forbidden to include it in your prototypes and to
compile it with the flag -std=c99.</samp>

<br> 

You must re-code the following functions. These function do not need any external functions:
- <samp>memset</samp>
- <samp>bzero</samp>
- <samp>memcpy</samp>
- <samp>memccpy</samp>
- <samp>memmove</samp>
- <samp>memchr</samp>
- <samp>strlen</samp>
- <samp>strlcpy</samp>
- <samp>strlcat</samp>
- <samp>strchr</samp>
- <samp>strrchr</samp>
- <samp>strnstr</samp>
- <samp>strncmp</samp>
- <samp>atoi</samp>
- <samp>isalpha</samp>
- <samp>isdigit</samp>
- <samp>isalnum</samp>
- <samp>isascii</samp>
- <samp>isprint</samp>
- <samp>toupper</samp>
- <samp>tolower</samp>

You must also re-code the following functions, using the function “malloc”:
- <samp>calloc</samp>
- <samp>strdup</samp>

<br>

<h3>Part 2 - Additional functions</h3>

In this second part, you must code a set of functions that are either not included in the libc, or included in a different form. Some of these functions can be useful to write Part 1’s functions.

<br>

 **Function name** | <samp>ft_substr</samp>
  -----------------|----------
  **Prototype** | <code>char *ft_substr(char const *s,  unsigned int start,  size_t len);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The string from which to create the substring.<br>#2.  The start index of the substring in the string ’<code>s</code>’.<br>#3.  The maximum length of the substring.
  **Return value** | The substring.  <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>
  **Description** | Allocates (with <code>malloc</code>(3)) and returns a substring from the string <code>s</code>. The substring begins at index <code>start</code> and is of maximum size <code>len</code>.

<br>

**Function name** | <samp>ft_strjoin</samp> 
  -----------------|----------
  **Prototype** | <code>char *ft_strjoin(char const *s1, char const *s2);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The prefix string.<br>#2.  The suffix string.
  **Return value** | The new string.  <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>
  **Description** | Allocates (with <code>malloc</code>(3)) and returns a new string, which is the result of the concatenation of <code>s1</code> and <code>s2</code>.
  
  <br>

**Function name** | <samp>ft_strtrim</samp>
  -----------------|----------
  **Prototype** | <code>char *ft_strtrim(char const *s1, char const *set);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The string to be trimmed.<br>#2.  The reference set of characters to trim.
  **Return value** | The trimmed string.  <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>
  **Description** | Allocates (with <code>malloc</code>(3)) and returns a copy of <code>s1</code> with the characters specified in <code>set</code> removed from the beginning and the end of the string.
  
  <br>

**Function name** | <samp>ft_split</samp> 
  -----------------|----------
  **Prototype** | <code>char **ft_split(char const *s, char c);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The string to be split.<br>#2.  The delimiter character.
  **Return value** | The array of new strings resulting from the split. <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>, <code>free</code>
  **Description** | Allocates (with <code>malloc</code>(3)) and returns an array of strings obtained by splitting <code>s</code> using the character <code>c</code> as a delimiter.  The array must be ended by a <code>NULL</code> pointer.

  <br>

**Function name** | <samp>ft_itoa</samp>
  -----------------|----------
  **Prototype** | <code>char *ft_itoa(int n);</code>
  **Turn in files** | - 
  **Parameters** | #1.  the integer to convert.
  **Return value** | The string representing the integer.  <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>
  **Description** | Allocates (with <code>malloc(3)</code>) and returns a string representing the integer received as an argument. Negative numbers must be handled.
  
<br>

**Function name** | <samp>ft_strmapi</samp> 
  -----------------|----------
  **Prototype** | <code>char *ft_strmapi(char const *s, char (*f)(unsigned int, char));</code>
  **Turn in files** | - 
  **Parameters** | #1.  The string on which to iterate.<br>#2.  The function to apply to each character.
  **Return value** | The string created from the successive applications of ’<code>f</code>’.  Returns <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>
  **Description** | Applies the function <code>f</code> to each character of the string <code>s</code> to create a new string (with <code>malloc</code>(3)) resulting from successive applications of f.
  
<br>

**Function name** | <samp>ft_putchar_fd</samp>
  -----------------|----------
  **Prototype** | <code>void ft_putchar_fd(char c, int fd);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The character to output.<br>#2.  The file descriptor on which to write.
  **Return value** | none
  **External functs.** | <code>write</code>
  **Description** | Outputs the character <code>c</code> to the given file descriptor.
  
<br>

**Function name** | <samp>ft_putstr_fd</samp> 
  -----------------|----------
  **Prototype** | <code>void ft_putstr_fd(char *s, int fd);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The string to output.<br>#2.  The file descriptor on which to write.
  **Return value** | none
  **External functs.** | <code>write</code>
  **Description** | Outputs the string <code>s</code> to the given file descriptor.
  
<br>

**Function name** | <samp>ft_putendl_fd</samp>
  -----------------|----------
  **Prototype** | <code>void ft_putendl_fd(char *s, int fd);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The string to output.<br>#2.  The file descriptor on which to write.
  **Return value** | none
  **External functs.** | <code>write</code>
  **Description** | Outputs the string <code>s</code> to the given file descriptor, followed by a newline.
  
<br>

**Function name** | <samp>ft_putnbr_fd</samp>
  -----------------|----------
  **Prototype** | <code>void ft_putnbr_fd(int n, int fd);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The integer to output.<br>#2.  The file descriptor on which to write.
  **Return value** | none
  **External functs.** | <code>write</code>
  **Description** | Outputs the integer <code>n</code> to the given file descriptor.

<br>
<br>
<h2>BONUS PART</h2>
<br>

If you successfully completed the mandatory part, you’ll enjoy taking it further. You can see this last section as Bonus Points.<br>
Having functions to manipulate memory and strings is very useful, but you’ll soon discover that having functions to manipulate lists is even more useful.<br>
You’ll use the following structure to represent the elements of your list. This structure must be added to your </samp>libft.h</samp> file.<br>
<samp>make bonus</samp> will add the bonus functions to the libft.a library.<br>
You do not have to add <samp>_bonus</samp> to the .c files and the header in this part. Only add <samp>_bonus</samp> to the files containing your own bonus functions.<br>
<pre>
<code>
  typedef struct    s_list
  {<br>
    void            *content;
    struct s_list   *next;
  }                 t_list;
</code>
</pre>

<br>

Here is a description of the fields of the <code>t_list</code> struct:

- <code>content</code>:  The data contained in the element. The <code>void *</code> allows to store any kind of data.
- <code>next</code>: The next element’s address or <code>NULL</code> if it’s the last element.
<br>

The following functions will allow you to easily use your lists.

<br>

**Function name** | <samp>ft_lstnew</samp>
  -----------------|----------
  **Prototype** | <code>t_list *ft_lstnew(void *content);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The content to create the new element with.
  **Return value** | The new element.
  **External functs.** | <code>malloc</code>
  **Description** | Allocates (with <code>malloc</code>(3)) and returns a new element.  The variable <code>content</code> is initialized with the value of the parameter <code>content</code>.  The variable <code>next</code> is initialized to <code>NULL</code>.
  
  <br>

**Function name** | <samp>ft_lstadd_front</samp>
  -----------------|----------
  **Prototype** | <code>void ft_lstadd_front(t_list **lst, t_list *new);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The address of a pointer to the first link of a list.<br>#2.  The address of a pointer to the element to be added to the list.
  **Return value** | None
  **External functs.** | None
  **Description** | Adds the element <code>new</code> at the beginning of the list.
  
 <br>

**Function name** | <samp>ft_lstsize</samp>
  -----------------|----------
  **Prototype** | <code>int ft_lstsize(t_list *lst);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The beginning of the list.
  **Return value** | Length of the list.
  **External functs.** | None
  **Description** | Counts the number of elements in a list.
  
  <br>
  
 **Function name** | <samp>ft_lstlast</samp>
  -----------------|----------
  **Prototype** | <code>t_list *ft_lstlast(t_list *lst);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The beginning of the list.
  **Return value** | Last element of the list.
  **External functs.** | None
  **Description** | Returns the last element of the list.
  
  <br>
  
 **Function name** | <samp>ft_lstadd_back</samp>
  -----------------|----------
  **Prototype** | <code>void ft_lstadd_back(t_list **lst, t_list *new);</code>
  **Turn in files** | - 
  **Parameters** | #1.  The address of a pointer to the first link of a list.<br>#2.  The address of a pointer to the element to be added to the list.
  **Return value** | None
  **External functs.** | None
  **Description** | Adds the element <code>new</code> at the end of the list.
  
  <br>
  
 **Function name** | <samp>ft_lstdelone</samp>
  -----------------|----------
  **Prototype** | <code>void ft_lstdelone(t_list *lst, void (*del)(void*));</code>
  **Turn in files** | - 
  **Parameters** | #1.  The element to free.<br>#2.  The address of the function used to delete the content.
  **Return value** | None
  **External functs.** | <code>free</code>
  **Description** | Takes as a parameter an element and frees the memory of the element’s content using the function <code>del</code> given as a parameter and free the element. The memory of <code>next</code> must not be freed.
  
  <br>
  
 **Function name** | <samp>ft_lstclear</samp>
  -----------------|----------
  **Prototype** | <code>void ft_lstclear(t_list **lst, void (*del)(void*));</code>
  **Turn in files** | - 
  **Parameters** | #1.  The adress of a pointer to an element.<br>#2.  The adress of the function used to delete the content of the element.
  **Return value** | None
  **External functs.** | <code>free</code>
  **Description** | Deletes and frees the given element and every successor of that element, using the function <code>del</code> and <code>free</code>(3). Finally, the pointer to the list must be set to <code>NULL</code>.
  
  <br>
  
 **Function name** | <samp>ft_lstiter</samp>
  -----------------|----------
  **Prototype** | <code>void ft_lstiter(t_list *lst, void (*f)(void *));</code>
  **Turn in files** | - 
  **Parameters** | #1.  The adress of a pointer to an element.<br>#2.  The adress of the function used to iterate on the list.
  **Return value** | None
  **External functs.** | None
  **Description** | Iterates the list <code>lst</code> and applies the function <code>f</code> to the content of each element.
  
  <br>
  
 **Function name** | <samp>ft_lstmap</samp>
  -----------------|----------
  **Prototype** | <code>t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));</code>
  **Turn in files** | - 
  **Parameters** | #1.  The adress of a pointer to an element.<br>#2.  The adress of the function used to iterate on the list.<br>#3.  The adress of the function used to delete the content of an element if needed.
  **Return value** | The new list.  <code>NULL</code> if the allocation fails.
  **External functs.** | <code>malloc</code>, <code>free</code>
  **Description** | Iterates the list <code>lst</code> and applies the function <code>f</code> to the content of each element.  Creates a new list resulting of the successive applications of the function <code>f</code>.  The <code>del</code> function is used to delete the content of an element if needed.
