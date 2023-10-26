/*
INTEGER POINTERS:

1.  An integer pointer is a type of pointer that points to an integer.
    - When an integer pointer is incremented, it advances the pointer to the next memory location that an integer value would occupy. 
    - Most systems typically use 4 bytes for an integer, so incrementing an integer pointer would advance the pointer by 4 bytes.

    Here's an illustration of how we use integer pointers in C:

        int num = 10;    // Declare an integer variable
        int* ptr = &num; // Declare an integer pointer and set it to the address of the num variable

        // Now, we can use the pointer to access the value of the num variable:
    
        int value = *ptr;  // value will be 10
        
    In this example, `ptr` is an integer pointer that stores the memory address of `num`.

2.  Char Pointers:
    - A char pointer is a type of pointer that points to a character(s).
    - When a char pointer is incremented, it moves to the next memory location that a char value would occupy. 
    - In most systems, a char occupies 1 byte, so incrementing a char pointer would advance the pointer by 1 byte.

    Let's look at an example of how we use character pointers:

        char* str = "Hello"; // Declare a char pointer and set it to the string "Hello"

        // Now, we can use the pointer to access the individual characters of the string:

        char first_char = *str;  // first_char will be 'H'

    In this example, `str` is a char pointer. It points to the first character of the string "Hello". 
    We can access the characters in the string "Hello" using `str`.

3.  In both these cases, the `*` operator is used to dereference the pointer or access the value at the memory location pointed to by the pointer. 
    The `&` operator is used to get the address of a variable.

4.  Suppose we have an array of integers and we want to use a pointer to traverse the array:

        int numbers[] = {10, 20, 30, 40, 50};
        int* ptr;

        // Point our integer pointer to the first element of the array
        ptr = numbers;

        for(int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, *ptr);
        
        // Increment the pointer to point to the next element of the array
        ptr++;

    In this example, we're using an integer pointer `ptr` to access each element of the numbers array. 
    When we increment the pointer `(ptr++)`, it moves to the next integer in the array.

5.  Now, suppose we have a string and we want to use a pointer to print each character:

        char* str = "Hello, World!";
        char* ptr;

        // Point our char pointer to the first character of the string
        ptr = str;

        while(*ptr != '\0') { // The end of a string in C is marked by a null character ('\0')
        printf("%c", *ptr);
    
        // Increment the pointer to point to the next character of the string
        ptr++;

    In this example, we're using a char pointer `ptr` to access each character of the `str` string. 
    When we increment the pointer `(ptr++)`, it moves to the next character in the string.

6.  In both examples, we're using pointers to traverse through a sequence of data (an array of integers and a string of characters). 
    The key difference is what the pointer points to (an integer vs a character) and how much it increments by when we do ptr++ (size of an integer vs 
    size of a char).
*/