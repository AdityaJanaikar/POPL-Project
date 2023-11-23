# Problem Statement
Data security is a big issue in the current world. The problem at hand is to implement a simple encryption and decryption algorithm in both Rust and C++ and identify various advantages and disadvantages both languages have for our specific use case .
<br>
By using the principles of both the languages we aim to compare and contrast the performance advantage they can provide<br>
The algorithm involves swapping adjacent characters in a string and then performing an XOR operation with a user-provided key.
 <br>

 While encryption and decryption are well-established concepts, this specific combination of swapping adjacent characters and using XOR with user-provided keys may not have a direct precedent. 
 Existing solutions often rely on established cryptographic algorithms, but this implementation provides a simple yet unique approach.

# Software Architecture

![Screenshot 2023-11-23 204258](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/93305226-fafb-46bc-b61d-c6970f2aec41)
<be>

- The software architecture is a functional programming approach. 
- It is a standalone architecture with no network involved
- All the testing is done on local files as of now. 

We developed all the parts of the code on our own. Both the C++ and the Rust code as it is a simplified and different encryption algorithms. The steps in the algorithm are as follows:

## Encryption:
1. It converts the file to a string
2. Adjacent characters of the string are swapped 
3.   The swapped string is then xored with a key input by the user repeatedly till the staring is exhausted.
4. The encrypted string is converted to hex values for storing and then stored in a text file

## Decryption:
1. The encrypted string is xored with the key again, the idea is a^a =0.
2. The adjacent strings are swapped back and we obtain our original string. 
3. The original string is stored back in a file


# POPL aspects
- Ownership and Borrowing: <br>
Here, rust's ownership system is leveraged when creating a mutable String from the input string (s). The subsequent collection of characters into a mutable Vec demonstrates borrowing. <br> <br>

![Screenshot 2023-11-23 194642](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/9966c3cc-980c-4ce3-affb-005b9194e360)
<br>
Necessity: Ownership helps to write clear code which uses up less memory to write the entire algorithm. Also, this should increase the code reliability. <br> <br>
- Pattern Matching and Destructuring: <br>
Rust's pattern matching and destructuring capabilities are employed in the xor_with_key function, where characters from the input string (c) and key (k) are matched and destructure simultaneously during the XOR operation.
<br> <br>

![Screenshot 2023-11-23 195025](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/224dfdbf-6125-4445-b23f-7c3eaab27823)
<br>
Necessity: Rust's pattern matching and destructuring abilities simplified code readability and reduced the risk of errors during complex operations, solving challenges related to data processing logic.
<br> <br>
- Error Handling: <br> 
The expect method is used for error handling when reading user input, demonstrating Rust's approach to explicit error handling.
<br>


![Screenshot 2023-11-23 200214](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/82c6a963-d425-43fc-b796-44691197bbff)
<br> 
Necessity: Rust's explicit error handling with the expect method solved challenges associated with ambiguous error messages. It provided a clear and concise way to handle errors during user input. It helped us understand the problems which our code had during implementation and testing.
<br> <br>
- Memory Safety: <br>
The use of String::from ensures that the memory allocation for the swapped string is handled safely, avoiding common memory-related issues.


![Screenshot 2023-11-23 200734](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/225bc2ba-27f5-4c74-b483-1e7808b28ffb)
<br> 
Necessity: Rust's memory safety features, prevented common memory-related issues, solving challenges related to manual memory management and memory safety. So we did not have to worry about keeping track of pointers and managing memory.
<br> <br>
- Lifetime: <br>
The &str parameter in the display_in_hex function uses a lifetime annotation, highlighting Rust's emphasis on explicit lifetime management for references.
<br>


![Screenshot 2023-11-23 201119](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/8820fef6-354b-463f-a249-7b0b451e56ef)
<br> 
Necessity: Difficulty Solved: Rust's use of explicit lifetime annotations addressed challenges in managing references and their lifetimes, providing clarity and preventing dangling references.
<br> <br>
- Static Typing: <br>
The explicit type annotations and conversions in the get_key_from_user function showcase Rust's commitment to static typing for enhanced safety.
<br>

![Screenshot 2023-11-23 201427](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/f38e7693-fbd8-40c1-95dc-ff72c2aa5470)
<br> 
Necessity: Rust's static typing system addressed challenges associated with type-related errors, providing early detection of potential issues and improving overall code reliability.
<be>

# Results

One of the test case files is attached in the tests folder. And the outputs generated from that file are attached in the results folder.
The outputs include:
1. Encrypted file from C++ algorithm
2. Decrypted file from C++ algorithm 
3. Encrypted file from Rust algorithm
4. Decrypted file from Rust algorithm


- The files 1 and 3 are the exact same and files 2,4 and the original test file are the exact same.

## Performance Analysis
- We tried to analyze timing differences for various types of text files, but it gave inconsistent results.
- We later understood it to be variable due to the variable time required for inputting the key
- We did compare the runtime of both the languages with a defined key value, the values are attached in the graph below:
 ![Screenshot 2023-11-23 214104](https://github.com/AdityaJanaikar/POPL-Project/assets/101914528/ba4cb009-23d2-422f-8691-d10ed0dfaaa9)

# How to compile
- C++: g++ filename.c
- Rust: rustc filename.rs
- Give file name as command line input with the object name. 

# Future Work
- Consideration for a more user-friendly interface, potentially transitioning from a command-line application to a graphical user interface (GUI) could be done. This enhancement could involve designing a more intuitive and visually appealing way for users to interact with the encryption and decryption processes. <br>
- Developing detailed tutorials and examples demonstrating guidelines to use the application, common encryption scenarios, key management best practices, and troubleshooting guides could help users take full advantage of our project. <br>
- We could also explore the possibility of compiling the application to WebAssembly for running in web browsers, expanding accessibility. <br>
- Testing on remote files from a LAN server or something similar. <br>
