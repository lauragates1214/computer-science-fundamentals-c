**Labs and Problem Sets for C**<br>
*from Harvard's CS50 Introduction to Computer Science course - Professional Certificate*
<br><br>
This repository contains the labs and problem sets for C that I've completed as part of my professional certificate program through Harvardx's CS50: Introduction to Computer Science.
<br><br><br>
**CS50 overview**<br>
*Topics include*<br>
abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web development.
<br><br>
*Languages include*<br>
C, Python, SQL, and JavaScript plus CSS and HTML.
<br><br>
*Labs and problem sets*<br>
Inspired by real-world domains of biology, cryptography, finance, forensics, and gaming.
<br><br>

---

My contribution to the code, where CS50 has included pre-existing code, is commented with **LauraPG**, and outlined under implementation details below. I've listed the assignments in reverse order of completion.

---

**Topic 5: Data Structures**<br>
*abstract data types // queues, stacks // linked lists // trees, binary search trees // hash tables // tries*
<br><br><br>
**Lab 5: Inheritance**<br>
*Creates a family of a specified generation size and assigns blood type alleles to each family member. The oldest generation has alleles assigned randomly to them.*
<br><br>
Implementation details for my contribution to code:     
- allocates memory for a new person via malloc
- sets parent pointers of new person
- assigns both alleles for new person by randomly choosing one allele from each parent, or if reaches final generation sets parent pointers to NULL and generates each allele randomly
- returns a pointer for the person that was allocated
- frees memory for the person, then recursively frees memory for all their ancestors.<br><br>

**Problem Set 5: Speller**   
*Spell-checks a file, using hash table, after loading a dictionary of words from disk into memory (implemented in dictionary.c). Prototypes for functions defined in dictionary.h. Texts for spell-checking in /texts.*
<br><br>
Implementation details for my contribution to code (dictionary.c):   
- implements, in order, load, hash, size, check, and unload as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized.
- uses hash function written by me.


---


**Topic 4: Memory**<br>
*pointers // segmentation faults // dynamic memory allocation // stack, heap // buffer overflow // file I/O // images*
<br><br><br>
**Lab 4: Volume**<br>
*Modifies the volume of an audio file, where INPUT.wav is the name of an original audio file and OUTPUT.wav is the name of an audio file with a volume that has been scaled by the given factor (e.g., 2.0).*
<br><br>
Implementation details for my contribution to code:   
- reads header from input file and writes that header to output file
- reads rest of data from WAV file, one 16-bit (2-byte) sample at a time
- multiplies each sample by the factor and write the new sample to output file.<br><br>   
   

**Problem Set 4a: Filter**<br>
*Allows user to apply grayscale, sepia, reflection, or blur filters to their images.*
<br><br>
Implementation details for my contribution to code (helpers.c):
- wrote functions to allow users to apply the above filters to an existing image.<br><br>  


**Problem Set 4b: Recover**<br>
*Iterates over a forensic image of a memory card, looking for JPEG signatures and recovering the images*
<br><br>
Implementation details for my contribution to code:
- accepts one command-line argument, the name of the forensic image of memory card from which to recover JPEGs, with input validation checks and error handling
- iterates over the image looking for JPEG signatures
- recovers the images, generating JPEG files
- uses malloc to dynamically allocate memory for output filenames, then frees memory allocation.
<br><br>   

---

**Topic 3: Algorithms**<br>
*searching: linear search, binary search // sorting: bubble sort, selection sort, merge sort // asymptotic notation: <math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi>O</mi>
</math>, <math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi mathvariant="normal">&#x3A9;</mi>
</math>, <math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi mathvariant="normal">&#x398;</mi>
</math> // recursion*
<br><br><br>
**Problem Set 3a: Plurality**<br>
*Simulates a plurality vote election*
<br><br>
Implementation details for my contribution to code:
- in vote function, checks for name match in candidate array
- updates matching candidates' vote tallies
- prints name of winner.   
<br>

**Problem Set 3b: Runoff**<br>
*Simulates a runoff election*
<br><br>
Implementation details for my contribution to code: 
- vote function identifying matching candidate names and compiles rank preferences
- tabulate function updates votes at each stage in the runoff
- print_winner function prints candidate with more than half the votes at any stage in the election
- find_min function returns minimum vote total for any candidate still in the election
- is_tie function returns true if every remaining candidate has same number of votes, otherwise false
- eliminate function eliminates candidates with smallest number of votes at any stage in the election.
<br><br>

---

**Topic 2: Arrays**<br>
*preprocessing // compiling // assembling // linking // debugging // arrays // strings // command-line arguments // cryptography*
<br><br><br>
**Lab 2: Scrabble**<br>
*Determines which of two Scrabble words is worth more*
<br><br>
Implementation details for my contribution to code:
- computes scores for words entered by the user for players 1 and 2
- prints winning player, or tie.
<br><br>

**Problem Set 2a: Readability**<br>
*Calculates the approximate grade reading level for a text using Coleman-Liau index*
<br><br>
Implementation details (fully written by me, no pre-filled CS50 code):
- prompts user for a string of text
- counts number of letters, words and sentences in the text
- prints relevant grade reading level.
<br><br>

**Problem Set 2b: Bulbs**<br>
*Converts user input message from text to binary using emoji art representing lightbulbs in on or off position*
<br><br>
Implementation details for my contribution to code:
- converts text into decimal numbers using ascii
- converts decimal numbers into equivalent binary numbers
- creates then reverses binary array to print emoji light/dark lightbulbs.
<br><br>

**Problem Set 2c: Caesar**<br>
*Encrypts messages using Caesar's cipher <math xmlns="http://www.w3.org/1998/Math/MathML" display="block">
  <msub>
    <mi>c</mi>
    <mi>i</mi>
  </msub>
  <mo>=</mo>
  <mo stretchy="false">(</mo>
  <msub>
    <mi>p</mi>
    <mi>i</mi>
  </msub>
  <mo>+</mo>
  <mi>k</mi>
  <mo stretchy="false">)</mo>
  <mi mathvariant="normal">%</mi>
  <mn>26</mn>
</math>*
<br><br>
Implementation details (fully written by me, no pre-filled CS50 code):
- accepts command line argument for cipher key, with input validation and error checking
- prompts user for string of plaintext, uses key to encrypt it preserving case, prints ciphertext.
<br><br>

**Problem Set 2d: Substitution**<br>
*Encrypts messages using a substitution cipher*
<br><br>
Implementation details (fully written by me, no pre-filled CS50 code apart from library inclusions and main function parameters):
- accepts command line argument for cipher key, with input validation and error checking
- prompts user for string of plaintext, uses key to encrypt it preserving case, prints ciphertext.
<br><br>

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


