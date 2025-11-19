/*
 * memoire.h
 *
 *  Created on: 27 août 2008
 *      Author: jmenaud
 */

#ifndef MEMOIRE_H_
#define MEMOIRE_H_
#include <drivers/Ecran.h>

 void mem_setup(void * begin, int size,Ecran *ec);
 void *getmem(size_t nbytes);


void* operator new(size_t taille);

#endif /* MEMOIRE_H_ */
