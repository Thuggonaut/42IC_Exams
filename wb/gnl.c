/*
This code belongs to Christopher Murphy. I couldn't resist dissecting a clever get_next_line function that was written in less than 25 lines of code.
*/

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd) //Define a function that takes in integer (a file descriptor), and returns a pointer to a character
{
	char	buffer[10960]; //Declare a character array that will be used to store the characters read from a file. `10960` size to make it big enough for Moulinnette to read
	char	*line; //Declare a pointer variable that will point to a character, and will be used to store the line read from a file
	ssize_t	bytes_read; //Declare a `ssize_t` variable that will be used to keep track of the number of bytes read from the file

	bytes_read = 0; //Initialised to `0` as no bytes have been read yet
	if (fd == -1 || read(fd, &buffer[0], 0) == -1 || BUFFER_SIZE == 0) //Check if `fd` is `-1`, implying an error and the file can't be opened; if reading from the `fd` fails; or if `BUFFER_SIZE` is `0`. See #1
		return (NULL); //If any is true, return `NULL`
	while (read(fd, &buffer[bytes_read], 1) > 0 && buffer[bytes_read++] != '\n') //Read from the file one character at a time and check if the character read is a newline character ('\n'). See #2
		;
	if (bytes_read == 0) //Check if no bytes were read (i.e., the file is empty or only contains a newline)
		return (NULL); //If so, return `NULL`
	line = (char *)malloc(sizeof(char) * (bytes_read + 1)); //Allocate memory for the `line` string. The size of the memory allocated is one more than the number of bytes read to accommodate the `\0` character
	if (!line) //Checks if the memory allocation failed
		return (NULL); //If so, return `NULL`
	line[bytes_read] = '\0'; //Add a null-terminating character at the end of the `line` string
	while (--bytes_read > -1) //Check if the value of `bytes_read` (after it has been decremented by `1`) is greater than `-1`. See #3
		line[bytes_read] = buffer[bytes_read]; //Copy the characters from the `buffer` to the `line` string in reverse order. See #4
	return (line); //Return the pointer that points to the first character of the `line` string read from the file
}

/*
#1  `if (fd == -1 || read(fd, &buffer[0], 0) == -1 || BUFFER_SIZE == 0)`:
	- is a conditional statement that checks for three possible error conditions before the function proceeds to read from the file. If any are true, the 
	  function immediately returns `NULL`:

	1. `fd == -1`: 
		- This checks if the file descriptor `fd` is `-1`. 
		- In Unix-like operating systems, `-1` is often used as the return value of a function that fails to open a file. 
		- So, if `fd` is `-1`, it means that the file failed to open.

	2. `read(fd, &buffer[0], 0) == -1`: 
		- This is a bit tricky. The `read` function is being called with a count of `0`, which means it doesn't actually read any data. 
		- Instead, this call to read is used as a way to check if `fd` is a valid file descriptor that can be read from. 
		- If `fd` is not valid, `read()` will return `-1`. 
		- So, if `read(fd, &buffer[0], 0) == -1`, it means that `fd` is not a valid file descriptor.

	3. `BUFFER_SIZE == 0`: 
		- This checks if `BUFFER_SIZE` is `0`. 
		- `BUFFER_SIZE` is a macro that specifies the size of the buffer used to read data from the file. 
		- If `BUFFER_SIZE` is `0`, it means that the buffer size is not properly set, and thus the function cannot proceed to read from the file.


#2	`while (read(fd, &buffer[bytes_read], 1) > 0 && buffer[bytes_read++] != '\n')	;`:
	- this while loop reads characters from the file one at a time into the buffer until it encounters a newline character or reaches the end of the file. 
	  The number of characters read (not including the newline character) is stored in `bytes_read`.

	1. `read(fd, &buffer[bytes_read], 1) > 0`: 
		- The `read` function is called to read one character from the file descriptor `fd` and store it in the buffer at the position indicated by 
		  `bytes_read`. 
		- The `read` function returns the number of bytes read, or `-1` if an error occurred. 
		- So, `read(fd, &buffer[bytes_read], 1) > 0` checks if at least one byte was read, which means that the end of the file has not been reached.

	2. `buffer[bytes_read++] != '\n'`: 
		- This checks if the character just read is not a newline character ('\n'). 
		- The `bytes_read++` part is a post-increment operation, which means that `bytes_read` is incremented after its value is used. 
		- So, `buffer[bytes_read++]` gets the character just read, and `bytes_read` is then incremented to prepare for the next read operation.

	3. `while (read(fd, &buffer[bytes_read], 1) > 0 && buffer[bytes_read++] != '\n') ;`: 
		- The while loop continues as long as both conditions are true: that is, as long as 
			- there are more characters to read from the file, and 
			- the character just read is not a newline character. 
		- When a newline character is encountered, the loop breaks, and the function proceeds to the next line of code.

	4. The semicolon (;) at the end of the line indicates that this while loop has no body. 
		- This is known as a "do nothing" or "null" statement. 
		- It means that the loop continues to iterate, reading one character at a time from the file, but doesn't perform any other action within the loop. 
		- The work is done in the condition itself: reading from the file and checking for the newline character.


#3	The condition `--bytes_read > -1`:
	- decrements `bytes_read` before comparing it with `-1` because in the previous steps, `bytes_read` was incremented each time a character was read from 
	  the file, including when the newline character was read. 
	- As a result, `bytes_read` is currently one position ahead of the last character read (not including the newline), so it needs to be decremented to 
	  point back at the last character. 
	- The comparison with `-1` is because array indices start at `0`, so the loop needs to continue as long as `bytes_read` is at least `0`.


#4	`line[bytes_read] = buffer[bytes_read];`: 
	- For each iteration of the loop, it takes the character at position `bytes_read` in `buffer` and assigns it to the same position in `line`. 
	
	1. In other words, it copies the character from `buffer` to `line`.

	2. `while (--bytes_read > -1) { line[bytes_read] = buffer[bytes_read]; }`: 
		- Together, these parts form a loop that starts from the end of `buffer` (and `line`) and works backwards to the beginning, copying each character
		  from `buffer` to `line`.
		- The end result of this loop is that `line` contains a copy of the characters from `buffer`, in the same order. 
		- This is the `line` read from the file, which the function then returns.
*/