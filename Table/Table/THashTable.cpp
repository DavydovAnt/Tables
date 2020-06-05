#include "THashTable.h"

unsigned int THashTable::HashFunc(const TKey key) {
	unsigned int hashval = key;
	return hashval;
}