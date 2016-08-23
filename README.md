# finiteStateAutomata
I wrote, in Python and C, programs to analyze Acceptors and determine their functionality given specific inputs 

## Python

This file has two main methods

### generate
generate is responsible for building a dictionary representation of the state and simply requires the name of the state's specification file as a parameter

### tryy
tryy is responsible for running the user's input through the representation, and takes a 3-tuple from generate, as well as the user's input from argv. The 3-tuple consists of a dictionary, and the names of the "accept" and "start" states

## C
In my C program, these methods are put together in main for simplicity of handling memory between functions

I also added a new method for generating a new dictNode,  a struct I defined to replicate the functionality of a python dictionary. A dictNode has a key, value, and next node.

This sequencing of nodes means that finding a specific node is a process in iterating through nodes from the head

# Usage

The programs in Python and C should both be called with two arguments: an fsm file and the sequence of transitions to analyze. Possible transitions can be found in the fsm file. A call would be e.g.

./fsm.py example1.fsm abc
./fsm.py example2.fsm abcdef
