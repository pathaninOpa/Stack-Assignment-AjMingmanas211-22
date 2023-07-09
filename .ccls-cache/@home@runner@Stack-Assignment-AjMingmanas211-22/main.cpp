#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int i,open=0,close=0;
  char c;
  s.pPrint();
  for (int j = 1; j < argc; j++){
    int match = 1, popc = 0;
    int len = strlen(argv[j]);
    for(i=0; i<len; i++){
      switch(argv[j][i]){
        case '[':
        case '{':
        case '(':
          s.push(argv[j][i]);
          open++;
        break;
        case ')':
          close++;
          if (s.isEmpty()) {
            match = 0;
            break;
          }
          c=s.pop();
          if(c!='(') {match=0; popc++;} //not match
        break;
        case ']':
          close++;
          if (s.isEmpty()) {
            match = 0;
            break;
          }
          c=s.pop();
          if(c!='[') {match=0; popc++;} //not match
        break;
        case '}':
          close++;
          if (s.isEmpty()) {
            match = 0;
            break;
          }
          c=s.pop();
          if(c!='{') {match=0; popc++;}//not match
        break;
        default: break;
        //if its : close bracket ] } ---> pop n check
      }
    } //inner loop
    if (popc == open) continue;
    if (match == 1 && open == close){
      puts("Match\n");
    }
    else{
        if (open > close) {puts("Not a match: Too many open parentheses.\n"); }
        else if (close > open){ puts("Not a match: Too many close parentheses.\n"); }
        else{
          puts("Not a match\n");
        }
      }
    open = 0; close = 0;
  }
  /*for(i=1; i<argc;i++){
    if(argv[i][0] =='x'){
      s.pop();
    }
    else{
      s.push(atoi(argv[i]));
    }
    s.print();
  }*/
}