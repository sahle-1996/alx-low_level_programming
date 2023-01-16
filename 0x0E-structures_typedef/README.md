0x0E. C - Structures, typedef




Resources
Read or watch:

0x0d. Structures.pdf
struct (C programming language)
Documentation: structures
0x0d. Typedef and structures.pdf
typedef
Programming in C by Stephen Kochan - Chapter 8, Working with Structures p163-189
The Lost Art of C Structure Packing (Advanced - not mandatory)
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
What are structures, when, why and how to use them
How to use typedef
Copyright - Plagiarism
You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
You are not allowed to publish any content of this project.
Any form of plagiarism is strictly forbidden and will result in removal from the program.



Tasks

Define a new type struct dog with the following elements:

name, type = char *
age, type = float
owner, type = char *

1. A dog is the only thing on earth that loves you more than you love yourself
mandatory
Write a function that initialize a variable of type struct dog

Prototype: void init_dog(struct dog *d, char *name, float age, char *owner);

2. A dog will teach you unconditional love. If you can have that in your life, things won't be too bad

Write a function that prints a struct dog

Prototype: void print_dog(struct dog *d);
Format: see example bellow
You are allowed to use the standard library
If an element of d is NULL, print (nil) instead of this element. (if name is NULL, print Name: (nil))
If d is NULL print nothing.

3. Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read

Define a new type dog_t as a new name for the type struct dog.


4. A door is what a dog is perpetually on the wrong side of
Write a function that creates a new dog.

Prototype: dog_t *new_dog(char *name, float age, char *owner);
You have to store a copy of name and owner
Return NULL if the function fails

5. How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg
 
Write a function that frees dogs.

Prototype: void free_dog(dog_t *d);
