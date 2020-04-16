# Decision Tree - CIS 3700 - Introduction to Intelligent Systems  

**University of Guelph**  
**Joshua Bunt**  

-------------------------------------------------------------------  

## Overview  

This assignment required me to implement a machine learning algorithm
to generate decision trees from an example set of inputs. The generated
decision tree can then make a decision given any input within the
problem space. The program program parses a scheme file that defines the
problem space, and a data file to define the example set. Once the needed
data is parsed, it begins generating the decision tree. Intermediate values
are printed to the console, to trace execution of the algorithm. Once the
decision tree is generated, it is printed to the console using the Visitor
pattern.

## Compile and Run Instructions  

The code can be compiled into byte code with the following command
(from the project's root directory):  

```bash
javac *.java
```  

The program takes two arguments, a file path to the schema file that
defines the problem space and a file path to the example set that specifies
the vector ordering as well as values in the example set.

For example:

```bash
java DTLearn <Scheme_file> <Data_File>
```

Included in the Assets folder are some matching Scheme-Data files. For
example: Scheme.txt goes with Data.txt, Loan_sche.txt goes with Loan.txt.

## To clean code

The following code will clean up the compiled byte code from the project.  

```bash
#Using sh
rm *.class

#Using Powershell
Remove-Item *.class -Force
```  
