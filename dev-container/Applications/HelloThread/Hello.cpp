/*
 * Hello.cpp
 *
 *  Created on: 1 oct. 2008
 *      Author: Jean-Marc Menaud
 */
#include "Hello.h"

void Hello::init(){
}

 Hello::Hello(Ecran* ecr,int i){
	e=ecr;
	monNum=i;
}

 Hello::Hello(Ecran* ecr,int i,Semaphore *sm1,Semaphore *sm2,char *chaine){
 	e=ecr;
 	monNum=i;
 	sem1=sm1;
 	sem2=sm2;
 	str=chaine;
 }

void Hello::run(){

	sem1->P();
	for ( ; *str != '\n' ; str++)
	    {
			sem2->P();
			e->afficherCaractere(BLANC,NOIR,*str);
			sem2->V();
	}

}
