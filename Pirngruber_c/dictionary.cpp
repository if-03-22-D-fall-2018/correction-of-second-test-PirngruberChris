/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.cpp
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of dictionary.h.
 * ----------------------------------------------------------
 */
#include "dictionary.h"
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include <stdio.h>

struct NodeImplementation{
  const char* word;
  Node next;
};

struct DictionaryImplementation{
  int length;
  Node head;
  bool isIterating;
};

 Dictionary new_dictionary(){
   Dictionary dictionary = (Dictionary) malloc(sizeof(struct DictionaryImplementation));
   dictionary->length = 0;
   dictionary->head = 0;
   dictionary->isIterating = false;
   return dictionary;
 }

 int get_size(Dictionary dictionary){
   Node current = dictionary->head;
   dictionary->length = 0;    //ToDO adDed Line
   while (current != 0) {
     dictionary->length++;
     current = current->next;
   }
   return dictionary->length;
 }

 void delete_dictionary(Dictionary dictionary){
   Node current = dictionary->head;
   while (current != 0) {
     Node node_to_delete = current;
     current = current->next;
     sfree(node_to_delete);
   }
   sfree(dictionary);
 }

 void add(Dictionary dictionary, const char* word){
   Node node_to_add =(Node) malloc(sizeof(struct NodeImplementation));
   node_to_add->word = word;
   node_to_add->next = 0;
   Node current = dictionary->head;
   if(is_in_dict(dictionary, word))return;
   if (dictionary->head == 0) {
     dictionary->head = node_to_add;
   }
   else{
     while (current->next != 0) {
       current = current->next;
     }
     current->next = node_to_add;
   }
 }

 bool is_in_dict(Dictionary dictionary, const char* word){
     Node current = dictionary->head;

     while (current != 0) {
       if (strcasecmp(current->word, word) == 0) {
         return true;
       }
       current = current->next;
     }
       return false;
 }

 void start_iterating(Dictionary dictionary){
   dictionary->isIterating = true;
 }

 bool has_next(Dictionary dictionary){
   if (dictionary->head != 0 && dictionary->isIterating == true) {
     return true;
   }
    return false;
 }

 const char* get_next_entry(Dictionary dictionary){
   if (has_next(dictionary) == true && dictionary->isIterating == true) {
     const char* word = dictionary->head->word;
     dictionary->head = dictionary->head->next;
     return word;
   }
    return 0;
 }

 void insert_sorted(Dictionary dictionary, const char* word){
  Node current = dictionary->head;           //ToDo funktion made
  Node node_to_add = (Node) malloc(sizeof(struct NodeImplementation));
  node_to_add->word = word;
  node_to_add->next = 0;
  if(dictionary->head == 0){
    add(dictionary, word);
  }
  else{
    if(is_in_dict(dictionary, word)){
      return;
    }

    if(strcasecmp(dictionary->head->word, word) > 0){
      node_to_add->next = dictionary->head;
      dictionary->head = node_to_add;
      dictionary->length++;
    }
    else{
      while(current->next != 0 && strcasecmp(current->next->word, word) < 0){
        current = current->next;
      }
      if(current->next == 0){
        add(dictionary, word);
      }

      if(strcasecmp(current->next->word, word) > 0){
        node_to_add->next = current->next;
        current->next = node_to_add;
        dictionary->length++;
      }
    }
  }
}
