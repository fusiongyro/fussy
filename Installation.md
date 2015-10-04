# Instructions for Compiling #

This software has been tested to compile on Linux operating system
with GCC 3.2.3.  The software utilizes a few routines from the [http://star-www.rl.ac.uk/  Star
link Astronomy library].  The software can be compiled on Linux with the
command
```
	gmake check
```

Use "gmake allclean" to clean up any previous builds (.o, .a and
executable binary files).

You might need to set the CCPATH, CC and CCINCL variables in the
makefile to use the right compiler.

Finally issue the command:
```
	cp exit.dat ~/.exit.dat
```
The functions used from the StarLink Astronomy Library are in the
directory "sla" and the class used for the extended numbers which
holds the value and associated random error is in the directory
"emath".  The mathematical operators and other mathematical functions
for the extended numbers are overloaded here.

The lexical analyzer uses the GNU Readline library for commandline
editing features.

## Units tests ##

The "gmake check" command will build and check the interpretor (use
"gmake fussy" if you only want to build it).

A test script, with the test programs and their expected outputs are
in the test directory.  Simple tests can be run on fussy by running
the script "fussytest" from the test directory (the only argument to
this script is the name of the binary executable which needs to be
tested).  If the tests pass, the output of the script should look
like:

```
Testing fussy ...
Unit test (fussy test.general quit 2> /dev/null ) | diff - test.general.out...         [PASSED]
Unit test (fussy test.func quit 2> /dev/null ) | diff - test.func.out...                    [PASSED]
Unit test (fussy test.builtins quit 2> /dev/null ) | diff - test.builtins.out...            [PASSED]
Unit test (fussy test.subtree.builtins quit 2> /dev/null ) | diff - test.subtree.builtins.out...[PASSED]
Unit test (fussy test.pow quit 2> /dev/null ) | diff - test.pow.out...                    [PASSED]
Unit test (fussy test.factorial quit 2> /dev/null ) | diff - test.factorial.out...        [PASSED]
Unit test (fussy test.laguerre quit 2> /dev/null ) | diff - test.laguerre.out...       [PASSED]
```

If the tests pass, that's it!  Usher yourself into the fussy world.

# Files #

```
AngFmt.cc,AngFmt.h:     Class to print the numbers in angular or time
                        formats.

BitField.cc,BitField.h: Implements a BitField type and methods to
                                 manipulate bits.
                        
calc.h
calc_lex_bison.h:       The header file for various forward declarations.

calcinit.cc,calcinit.h:    Functions to initialize the VM

defns.h:                      Various type definitions.

emath:                        Directory for extended number format and
                                  related overloaded math functions and operators.

ErrorObj.cc,ErrorObj.h: Object thrown to report errors via the
                                    ErrorObj exception.
ExitMsg.cc:                   Function to print a message if an
                                    inappropriate exit is attempted (e.g. via a
                                    Ctrl-C from the user).
                        
func.cc,func.h:               Functions for jumping the VM execution to a
                                     sub-program. 

fussy.cc:                       The main program which drives the VM.

fussy.l:                          The fussy lexical analyzer Flex code.

fussy.y:                          The fussy parser Bison code.

IDResource.cc,             The global resource to manage the
IDResource.h:               allocation and releasing the unique IDs of
                                     fussy variables.
                        
namespace.h:               Defines the namespaces used from the Standard
                                    C++ libraries.

prtVM.cc:                      Functions to print the symbol tables and the
                                    complied VM code from the memory.

sla:                               Has the required routines from the StarLink
                                    Astronomy Library.

tables.h,                       Implements the functions to manipulate the
tables.cc:                     various symbol tables.
                        
test:                              Scripts to test the fussy interpretor.
                        
typeMake,vmMake:       Scripts to automatically make tables of VM
                                    types and VM functions to be included in the
                                    prtVM code.

units.h:                         Enumerations for various physical units
                                   definitions. 
                        
vcode.cc:                     The code for various function calls for the
                                    execution of the VM code.
                        
yyerror.c:                      Functions used by the lexical analyzer to
                                     report lexical errors.
```