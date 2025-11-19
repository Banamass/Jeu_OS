/*
 * memoire.cpp
 *
 *  Created on: 27 août 2008
 *      Author: jmenaud
 */
#include "memoire.h"

void *debut;
int taille;
Ecran *ec;

void mem_setup(void * begin, int size,Ecran *ecran) {
	debut=begin;
	taille=size;
	ec=ecran;
}


void * getmem(size_t nbytes)
{
	void *adresse;
	char *temp;
	int i = (int) debut;
/*
	ec->sautDeLigne();
	ec->afficherMot("Adresse de debut : ");
	ec->afficherBase((unsigned int) i,10,BLANC);
	ec->sautDeLigne();
	ec->afficherMot("Taille passee en param de getmem : ");
	ec->afficherBase((unsigned int) nbytes,10,BLANC);
	ec->sautDeLigne();*/
	i=i+nbytes;
/*	ec->afficherMot("Adresse de fin : ");
	ec->afficherBase((unsigned int) i,10,BLANC);
	ec->sautDeLigne();*/

	adresse = debut;
	debut = (void *) i;
	return adresse;

}

void* operator new(size_t taille) {
	// return (void*)malloc((size_t)taille);
	void * temp;
	temp = getmem(taille);

	/*
	ec->afficherMot("Entree dans constructeur, adresse :  ",BLANC);
	ec->afficherBase((unsigned int) temp,10,BLANC);
	ec->sautDeLigne();
	ec->afficherMot("Entree dans constructeur, taille :  ",BLANC);
	//ec->afficherChiffre(taille);
	ec->afficherBase((unsigned int) taille,10,BLANC);
	ec->sautDeLigne();*/

	return temp;
}
