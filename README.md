**Labs and Problem Sets for C**<br>
*from Harvard's CS50 Introduction to Computer Science course - Professional Certificate*
<br><br>
This repository contains the labs and a selection of problem sets for C that I've completed as part of my professional certificate program through Harvardx's CS50: Introduction to Computer Science.
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

***TOPIC 5: DATA STRUCTURES***<br>
*abstract data types // queues, stacks // linked lists // trees, binary search trees // hash tables // tries*
<br><br>

**Lab 5: Inheritance**<br>
*Simulates genetic inheritance of blood type.*
<br><br>
Implementation details for my contribution to code:     
- allocates memory for a new person via malloc
- sets parent pointers of new person
- assigns both alleles for new person by randomly choosing one allele from each parent, or if reaches final generation sets parent pointers to NULL and generates each allele randomly
- returns a pointer for the person that was allocated
- frees memory for the person, then recursively frees memory for all their ancestors.<br><br>

**Problem Set 5: Speller**   
*Implements a dictionary's functionality. Spell-checks a file, using hash table, after loading a dictionary of words from disk into memory (implemented in dictionary.c). Prototypes for functions defined in dictionary.h. Texts for spell-checking in /texts.*
<br><br>
Implementation details for my contribution to code (dictionary.c):   
- implements, in order, load, hash, size, check, and unload as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized.
- uses hash function written by me.


---


***TOPIC 4: MEMORY***<br>
*pointers // segmentation faults // dynamic memory allocation // stack, heap // buffer overflow // file I/O // images*
<br><br><br>
**Problem Set 4: Filter**<br>
*Allows user to apply grayscale, sepia, reflection, or blur filters to their images.*
<br><br>
Implementation details for my contribution to code (wrote all functions in helpers.c):
- wrote functions to allow users to apply the above filters to an existing image.<br><br>  

**Problem Set 4: Recover**<br>
*Iterates over a forensic image of a memory card, looking for JPEG signatures and recovering the images*
<br><br>
Implementation details (code fully written by me; no pre-filled CS50 code apart from library inclusions and main function parameters):
- accepts one command-line argument, the name of the forensic image of memory card from which to recover JPEGs, with input validation checks and error handling
- iterates over the image looking for JPEG signatures
- recovers the images, generating JPEG files
- uses malloc to dynamically allocate memory for output filenames, then frees memory allocation.
<br><br>

**Lab 4: Volume**<br>
*Modifies the volume of an audio file, where INPUT.wav is the name of an original audio file and OUTPUT.wav is the name of an audio file with a volume that has been scaled by the given factor (e.g., 2.0).*
<br><br>
Implementation details for my contribution to code:   
- reads header from input file and writes that header to output file
- reads rest of data from WAV file, one 16-bit (2-byte) sample at a time
- multiplies each sample by the factor and write the new sample to output file.<br><br>   

---

***TOPIC 3: ALGORITHMS***<br>
*searching: linear search, binary search // sorting: bubble sort, selection sort, merge sort // asymptotic notation: <math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi>O</mi>
</math>, <math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi mathvariant="normal">&#x3A9;</mi>
</math>, <math xmlns="http://www.w3.org/1998/Math/MathML">
  <mi mathvariant="normal">&#x398;</mi>
</math> // recursion*
<br><br><br>
**Problem Set 3: Plurality**<br>
*Simulates a plurality vote election*
<br><br>
Implementation details for my contribution to code:
- in vote function, checks for name match in candidate array
- updates matching candidates' vote tallies
- prints name of winner.   
<br>

**Problem Set 3: Runoff**<br>
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

***TOPIC 2: ARRAYS***<br>
*preprocessing // compiling // assembling // linking // debugging // arrays // strings // command-line arguments // cryptography*
<br><br><br>
**Problem Set 2: Bulbs**<br>
*Converts user input message from text to binary using emoji art representing lightbulbs in on or off position*
<br><br>
Implementation details for my contribution to code (wrote main function):
- converts text into decimal numbers using ascii
- converts decimal numbers into equivalent binary numbers
- creates then reverses binary array to print emoji light/dark lightbulbs.
<br><br>

**Problem Set 2: Caesar**<br>
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
Implementation details (fully written by me; no pre-filled CS50 code):
- accepts command line argument for cipher key, with input validation and error checking
- prompts user for string of plaintext, uses key to encrypt it preserving case, prints ciphertext.
<br><br>

**Problem Set 2: Readability**<br>
*Calculates the approximate grade reading level for a text using the Coleman-Liau index*
<br><br>
Implementation details (fully written by me; no pre-filled CS50 code):
- prompts user for a string of text
- counts number of letters, words and sentences in the text
- prints relevant grade reading level.
<br><br>
I also wrote Readability in Python (see repository for Python labs and problem sets from Harvard CS50).

**Problem Set 2: Substitution**<br>
*Encrypts messages using a substitution cipher*
<br><br>
Implementation details (fully written by me; no pre-filled CS50 code apart from library inclusions and main function parameters):
- accepts command line argument for cipher key, with input validation and error checking
- prompts user for string of plaintext, uses key to encrypt it preserving case, prints ciphertext.
<br><br>

---

***TOPIC 1: C***<br>
*C // source code // machine code // compiler // correctness, design, style // Visual Studio Code // syntax highlighting // escape sequences // header files // libraries // manual pages // types // conditionals // variables // loops // Linux // Graphical User Interface (GUI) // Command-Line Interface (CLI) // constants // comments // pseudocode // operators // integer overflow // floating-point imprecision*
<br><br>

**Problem Set 1: Credit**<br>
*Prompts the user for a credit card number, then uses Luhn's algorithm to validate the card number as Visa, MasterCard, American Express or invalid.*<br>
Code fully written by me; no pre-filled CS50 code.
I also wrote Credit in Python (see repository for Python labs and problem sets from Harvard CS50).





