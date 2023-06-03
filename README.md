**Labs and Problem Sets for C**  
*from Harvard's CS50 Introduction to Computer Science course - Professional Certificate*  
   
This repository contains the labs and problem sets for C that I've completed as part of my professional certificate program through Harvard's CS50: Introduction to Computer Science. 
   
https://www.edx.org/course/introduction-computer-science-harvardx-cs50x
   
**CS50 overview**  
*Topics include*  
abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web development.

*Languages include*  
C, Python, SQL, and JavaScript plus CSS and HTML.

*Labs and problem sets*  
Inspired by real-world domains of biology, cryptography, finance, forensics, and gaming.
   
---   
   
My contribution to the code, where CS50 has included pre-existing code, is commented with LauraPG, and outlined under implementation details below. I've listed the assignments in reverse order of completion.
   
---

**Topic 5: Data Structures**
*abstract data types // queues, stacks // linked lists // trees, binary search trees // hash tables // tries*    
   
**Lab 5: Inheritance**
Creates a family of a specified generation size and assigns blood type alleles to each family member. The oldest generation has alleles assigned randomly to them.
Implementation details for my contribution:     
- allocates memory for a new person via malloc
- sets parent pointers of new person
- assigns both alleles for new person by randomly choosing one allele from each parent, or if reaches final generation sets parent pointers to NULL and generates each allele randomly
- returns a pointer for the person that was allocated
- frees memory for the person, then recursively frees memory for all their ancestors.

---   
   
**Topic 1: C**  
**Lab 1: Population Growth**  
Calculates number of years required for a population of llamas to grow from a start size to and end size.   
Specs:   
- Prompts user for a starting and an ending population size, with input validation
- Calculates and prints the number of years required for the population to reach that size

**Problem Set 1**   
*Mario less*  
Prints a half pyramid using # based on user's integer input, with input validation.
   
*Mario more*  
Prints a full pyramid, with empty column in middle, using # based on user's integer input, with input validation.

*


