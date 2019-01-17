/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.h
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * dictionary.h defines functions to maintain a simple
 * dictionary.
 * ----------------------------------------------------------
 */
#ifndef ___DICTIONARY_H
#define ___DICTIONARY_H

#include "general.h"

typedef struct NodeImplementation* Node;
typedef struct DictionaryImplementation* Dictionary;

Dictionary new_dictionary();
int get_size(Dictionary dictionary);
void delete_dictionary(Dictionary dictionary);
void add(Dictionary dictionary, const char* word);
bool is_in_dict(Dictionary dictionary, const char* word);
void start_iterating(Dictionary dictionary);
bool has_next(Dictionary dictionary);
const char* get_next_entry(Dictionary dictionary);
void insert_sorted(Dictionary dictionary, const char* word);

#endif
