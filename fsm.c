#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct dictNode{
    char *key;
    void *value;
    bool accepting;
    dictNode *next;
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
    FILE *readme = open(argv[1]);
    here = false;
    char *line=fgets(readme);
    do{

        if(here){
            int lits= 0;
            while(line[lits]!=':'){
                lits++;
            } 
            char *initial = strndup(line,lits);
            dictNode newNode=newDictNode(initial,false);
            int lits2=lits;
            while (line[lits2]!='0'){
                while(strcmp(line[lits2],":")!=0){
                    lits2++;
                } 
                int lits3=lits2;
                while(strcmp(line[lits3],",")!=0){
                    lits3++;
                }
		transition = strndup(&initial[lits],lits2-lits);
                final = strndup(&initial[lits2],lits3-lits); 
                //transitions[initial][transition]=final
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
    
    readme.close()
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
