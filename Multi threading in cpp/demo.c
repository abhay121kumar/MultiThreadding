//simple structure -> a basic structure with member variable
//nested structure -> a structure that contains another structure as a member
//array of structure -> an array where each element is a structure
//pointer to structure -> a structure that holds a pointer to another structure

// Great! Let’s dive into *nested structures, **arrays of structures, and **pointers to structures* with simple examples for each.

// ### 1. *Nested Structure*

// A nested structure is a structure that contains another structure as one of its members.

// #### Example:

#include <stdio.h>

// Define a structure for Address
// struct Address {
//     char street[100];
//     char city[50];
//     int zip;
// };

// // Define a structure for Employee that contains Address as a member
// struct Employee {
//     char name[50];
//     int age;
//     struct Address address;  // Nested structure
// };

// int main() {
//     struct Employee emp;

//     // Input details for the employee
//     printf("Enter employee name: ");
//     scanf("%s", emp.name);
//     printf("Enter employee age: ");
//     scanf("%d", &emp.age);
//     printf("Enter street: ");
//     scanf("%s", emp.address.street);
//     printf("Enter city: ");
//     scanf("%s", emp.address.city);
//     printf("Enter zip code: ");
//     scanf("%d", &emp.address.zip);

//     // Output the employee details
//     printf("\nEmployee Details:\n");
//     printf("Name: %s\n", emp.name);
//     printf("Age: %d\n", emp.age);
//     printf("Address: %s, %s, %d\n", emp.address.street, emp.address.city, emp.address.zip);

//     return 0;
// }


// ### Explanation:

// * *Nested Structure*: Employee contains an Address structure.
// * *Input and Output*: We take input for both the employee's personal details and address. Then, we print all the details.

// ### Possible Questions:

// 1. *What is a nested structure in C?*

//    * Answer: A nested structure is a structure that contains another structure as a member.

// 2. *Can you have multiple levels of nested structures?*

//    * Answer: Yes, structures can be nested multiple times (a structure within another structure within another structure, and so on).

// ---

// ### 2. *Array of Structures*

// An array of structures is a collection of multiple structures of the same type. This allows you to store information about multiple entities of the same type.

// #### Example:


// #include <stdio.h>

// Define structure for storing book details
// struct Book {
//     char title[100];
//     char author[50];
//     int year;
// };

// int main() {
//     // Declare an array of structures
//     struct Book library[3];

//     // Input details for each book in the array
//     for (int i = 0; i < 3; i++) {
//         printf("\nEnter details for Book %d:\n", i + 1);
//         printf("Enter title: ");
//         scanf("%s", library[i].title);
//         printf("Enter author: ");
//         scanf("%s", library[i].author);
//         printf("Enter year of publication: ");
//         scanf("%d", &library[i].year);
//     }

//     // Output details of all books
//     printf("\nLibrary Book Details:\n");
//     for (int i = 0; i < 3; i++) {
//         printf("\nBook %d:\n", i + 1);
//         printf("Title: %s\n", library[i].title);
//         printf("Author: %s\n", library[i].author);
//         printf("Year: %d\n", library[i].year);
//     }

//     return 0;
// }


// ### Explanation:

// * *Array of Structures*: library[3] is an array that holds 3 structures, each of type Book.
// * *Input and Output*: The program takes input for three books and then displays their details.

// ### Possible Questions:

// 1. *What is an array of structures?*

//    * Answer: An array of structures is a collection of structures, where each element of the array is a structure. All structures in the array have the same type.

// 2. *Can the size of the array of structures be dynamic?*

//    * Answer: In C, arrays have a fixed size. For dynamic sizes, you would need to use pointers and dynamically allocate memory (using malloc() or calloc()).

// ---

// ### 3. *Pointer to Structure*

// A pointer to a structure holds the address of a structure. This is useful when you need to pass a
//  large structure to a function without making a copy of it.

// #### Example:


#include <stdio.h>

// Define a structure for storing person details
struct Person {
    char name[50];
    int age;
};

// Function to display person details using pointer to structure
void displayPerson(struct Person *p) {
    printf("\nPerson Details:\n");
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main() {
    struct Person person1;

    // Input details for the person
    printf("Enter name: ");
    scanf("%s", person1.name);
    printf("Enter age: ");
    scanf("%d", &person1.age);

    // Pass the address of person1 to the function using pointer
    displayPerson(&person1);

    return 0;
}


// ### Explanation:

// * *Pointer to Structure*: We use a pointer (struct Person *p) to pass the address of person1 to the displayPerson function.
// * *Accessing Members via Pointer*: We use the -> operator to access structure members via a pointer.

// ### Possible Questions:

// 1. *What is a pointer to a structure?*

//    * Answer: A pointer to a structure holds the memory address of the structure, allowing you to manipulate the structure directly without making a copy.

// 2. *How do you access members of a structure using a pointer?*

//    * Answer: To access members of a structure via a pointer, use the -> operator. Example: p->name and p->age.

// 3. *Why would you use a pointer to a structure instead of passing by value?*

//    * Answer: Using a pointer avoids the overhead of copying large structures when passing them to functions, and allows functions to modify the original structure.

// ---

// ### Summary of Types of Structures in C:

// 1. *Simple Structure*: A basic structure that groups different types of variables.
// 2. *Nested Structure*: A structure that contains another structure as a member.
// 3. *Array of Structures*: An array where each element is a structure, allowing you to manage multiple entities of the same type.
// 4. *Pointer to Structure*: A pointer that holds the address of a structure, allowing for efficient manipulation of large structures.

// ---

// Let me know if you want further examples or if something is unclear!
