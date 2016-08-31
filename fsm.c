#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct dictNode{
    char *key;
    void *value;
    bool accepting;
    struct dictNode *next;
} dictNode;

dictNode *newDictNode(char *me, bool accept){
    dictNode *toreturn = (dictNode *)malloc(sizeof(dictNode));
    toreturn->key=me;
    toreturn->value=NULL;
    toreturn->accepting=accept;
    toreturn->next=NULL;
    return toreturn;
}
void main(int argc, char **argv){
    dictNode *head = (dictNode *) malloc(sizeof(dictNode));
    dictNode **transitions = &head; // to keep track of dictionary for access throughout main
    FILE *readme = fopen(argv[1], "r");
    char here = false;
    char *line=fgets(readme);
    do{

        if(here){
            int lits= 0;
            while(line[lits]!=':'){
                lits++;
            } 
            char *initial = strndup(line,lits);
            dictNode *newNode = newDictNode(initial,false);
            int lits2=lits;
            while (line[lits2]!='0'){
                while(line[lits2] != ':'){
                    lits2++;
                } 
                int lits3=lits2;
                while(line[lits3] != ','){
                    lits3++;
                }
		char *transition = strndup(&initial[lits],lits2-lits);
                char *final = strndup(&initial[lits2],lits3-lits); 
                //transitions[initial][transition]=final;
            }
        }
        elif(line.strip()[:5] == "start"){
            state = line.split()[len(line.split())-1];
        }
        elif(line.strip()[:3] == "end"){
            line.split()[len(line.split())-1];
            //accepting=true;
        }
        elif(strcmp(line,"[transitions]\n")==0){
            here=true;
        }
        line=fgets(readme);
    }while(line!=NULL);
    
    fclose(readme);
    line=argv[2];
    int count=0;
    for(int i=0;i<sizeof(line);i++){
        if letter in transitions[state].keys(){
                    state=transitions[state][letter]
        }        
        elif "*" in transitions[state].keys(){     
               state=transitions[state]["*"]
        }        
    if(state== argv[1]):
        printf("Accepting state");
    else{
        printf("Reject. Final state is %s ", state );
    }
}
