#!/usr/bin/env python3

import sys

def generate(name): #generate dictionary
    state = {}
    readme = open(name)

    here = False
    for line in readme:
        if(here):
            lits = line[line.index(":")+1:].split(",")
            initial =  line[:line.index(":")]
            state[initial]={}
            for combo in lits:
                transition = combo.strip()[:combo.strip().index(":")] 
                final =  combo.strip()[combo.strip().index(":")+1:]
                if transition in state[initial]: # see if transform is not determinstic
                    print("error: nondeterministic transition from "+initial+" upon input "+transition) # example6.1 anything 
                    sys.exit()
                else:
                    state[initial][transition]=final
        elif(line.strip()[:5] == "start"):
            start = line.split()[len(line.split())-1]
        elif(line.strip()[:3] == "end"):
            end = line.split()[len(line.split())-1]
        elif(line=="[transitions]\n"): #the initial part is not entirely helpful
            here=True
    readme.close()
    return (start,end,state)

def tryy(triple,sequence):
    transitions = triple[2]
    state=triple[0]
    for letter in sequence:
        if letter in transitions[state].keys():
            state=transitions[state][letter]
        elif "*" in transitions[state].keys():
            state=transitions[state]["*"]
        else:
            print("error: machine not fully defined") #example4 abd
            sys.exit()
    if(state== triple[1]):
        print("Accepting state")
    else:
        print("Reject. Final state is "+state )
def main():
    tryy(generate(sys.argv[1]),sys.argv[2])
    print(generate(sys.argv[1]))
if __name__=="__main__":
    main()
