# Assignment 1 - Scanner                            
**CIS 4650 - Compilers, University of Guelph**         
**Joshua Bunt**                                        
*******************************************************

## Compilation steps:
To create java files from flex files and compile all java code from src/ to bytecode in build/.

  ```bash
  make (all)
  ```

To delete the build folder and generated java code enter the following:

```bash    
  make clean
```

## Run steps

I have included a small script to call the main function for this assignment. One note: there appears to be 
a line ending issue as my text editor keeps setting the line endings to CRLF instead of LF. I have tried
to fix this, but for whatever reason it doesn't seem to stick. Some setting must be automatically changing
this. If the script wont run properly, this is most likely the issue. 

```bash
chmod +x a1.sh
./a1 > newsdata.txt
```

## Testing
I have included the files I used to test the program. Each file has some cases based on the filename. Some of
the edge cases include:
 - ensuring that open tags can have optional args
 - testing that open/close tags can have alphanumerical identifiers
 - test that words can be alphanumerical
 - test that real numbers can be represented along with integers
 - test that a hyphenated word with a contraction, such as father-in-law's is in the apostriphized regex
 - testing that hyphenated words are identified as such
 - testing that mismatched open close pairs are identified and reported
 - testing that filtering is working as expected

## Improvements
 - With more time, I would try to do the filtering at the flex level. I had solved this part of the assignment before 
   reading the marking scheme and thus didn't realize this was possible with a single flex file. 
 - I would increase the testing amount, more cases, perhaps make an automated test script. I'm sure there are edge
   cases I have not accounted for yet. 
 - I would better comment the code