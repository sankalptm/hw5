#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void search( std::string& in,
     std::string& floating,
     std::set<std::string>& dict, unsigned int num_empty, unsigned int index, std::set<std::string>&output_words);


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    std::set<std::string> output_words;
  //use the dict provided as a container for all the words
  //input string 
  //string with the letters 
  //size_t num_letters= in.size();
  unsigned int num_empty=0;
  std::set<size_t> empty_pos_numbers;
  for (unsigned int i=0; i<in.size(); i++){
    if (in[i]=='-'){
      num_empty++;
      empty_pos_numbers.insert(i);
    }
  }
  string temp_in=in;
  string temp_float=floating;
  std::set<std::string> temp_dict=dict;
  search(temp_in, temp_float, temp_dict, num_empty, 0, output_words);
  return output_words;

}

void search(std::string& in,
     std::string& floating,
     std::set<std::string>& dict, unsigned int num_empty, unsigned int index, std::set<std::string>&output_words){
       //string combo=in;
       //try adding letters 

       //cout<<in<<endl;
       //auto dash_finder =dict.find(in);
       if (dict.find(in)!=dict.end() && index==in.length() && num_empty==0){
         output_words.insert(in);
         return;
       }
       
         string saved_in=in;
         string saved_float=floating;
         if (floating.size()>num_empty){
           return;
         }
        if (in[index]!= '-'){
          search(in, floating, dict, num_empty, index+1, output_words);
         }
         
           //string::iterator it;
        for(unsigned int i=0; i< floating.length(); i++){
          in[index]=floating[i];
          floating.erase(0, 1);
          search(in, floating, dict, num_empty-1,index+1,output_words);
          in=saved_in;
          floating=saved_float;

        }
        if (num_empty> floating.size()){
             string alpha="abcdefghijklmnopqrstuvwxyz";
             //int alpha_index=0;
             //make recursive call that modifies the floating list
             for (unsigned int alpha_traverse=0; alpha_traverse<alpha.length(); alpha_traverse++){
                //should mirror the above code block
                /*auto float_finder=floating.find(alpha[alpha_traverse]);
                if (saved_float.find(alpha[alpha_traverse])!= std::string::npos){
                  alpha_traverse++;
                }
                else {
                  in[alpha_traverse]=alpha[alpha_traverse];
                  if (floating.length()>0){
                    search(in, floating, dict, num_empty-1,index+1,  output_words);
                    in=combo;
                    floating=saved_float;
                    alpha_traverse++;
                }
                else {
                  return;
                }*/
                if (saved_float.find(alpha[alpha_traverse])!=std::string::npos){
                  alpha_traverse++;
                }
                in[index]=alpha[alpha_traverse];
                search(in, floating, dict, num_empty-1,index+1,  output_words);
                in=saved_in;
                floating=saved_float;

                }
                


             }

           
         
         
       }



  

// Define any helper functions here


/*
-i-- dab 
diab
diba
aidb
aibd
bida
biad

backtrack(in, floating_SET, index, num_empty )
  //one more base case for float greater than number of spaces 
  if index == in.size()
    if in is in dict
      insert in to ouput
    return 
  
  if in at index != '-'
    backtrack(in, floating_SET, index + 1, num_empty)
  else
    for char in floating_SET:
          in[index] = char
          remove char from floating_SET
          //make a copy of the floating set 
          backtrack(in, floating_SET, index + 1, num_empty-1)
          insert char back to floating_SET
          in[index] = '-'
    if num_empty < size of floating_SET
      fo
      //try all letters in the alphabet 
      //try characters not in the floating set 
      
*/