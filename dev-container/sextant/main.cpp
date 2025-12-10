#include <hal/multiboot.h>
#include <drivers/Ecran.h>
#include <drivers/PortSerie.h>

// TP2
#include <sextant/interruptions/idt.h>
#include <sextant/interruptions/irq.h>
#include <sextant/interruptions/handler/handler_tic.h>
#include <sextant/interruptions/handler/handler_clavier.h>
#include <drivers/timer.h>
#include <drivers/Clavier.h>
// TP3
#include <sextant/memoire/memoire.h>

// TP4
#include <sextant/ordonnancements/cpu_context.h>
#include <sextant/ordonnancements/preemptif/thread.h>
#include <sextant/types.h>


#include <sextant/Synchronisation/Spinlock/Spinlock.h>

#include <hal/pci.h>
#include <drivers/vga.h>
#include <drivers/EcranBochs.h>

#include <sextant/sprite.h>
#include <sextant/Sprite/Zelda.h>

#include "Game/Game.h"
#include "Game/MenuMain.h"
#include "Game/MenuCharacters.h"

extern char __e_kernel,__b_kernel, __b_data, __e_data,  __b_stack, __e_load ;
int i;

extern vaddr_t bootstrap_stack_bottom; //Adresse de début de la pile d'exécution
extern size_t bootstrap_stack_size;//Taille de la pile d'exécution

void demo_vga() {
	set_vga_mode13(); // set VGA mode
	set_palette_vga(palette_vga); // set to given palette

	ui16_t offset = 0;
	while(1) {
		clear_vga_screen(0); // put the color 0 on each pixel
		plot_square(offset, 50, 25, 4); // plot a square of 25 width at 50,50 of color 4
		draw_sprite(sprite_zelda_walk, ZELDA_WIDTH, ZELDA_HEIGHT, 100,100); // draw the 32x32 sprite at 100,100
		offset = (offset + 1) % 640;
	}
}

void demo_bochs_8() {
	EcranBochs vga(640, 400, VBE_MODE::_8);

    vga.init();
    vga.clear(0);

    // only usefull in 4 or 8 bits modes
    vga.set_palette(palette_vga);
    vga.plot_palette(0, 0, 25);

	int offset = 0;
	while (true) {
		vga.clear(1);
		vga.plot_sprite(sprite_yoshi_attack2, YOSHI_WIDTH, YOSHI_HEIGHT, offset, 200);
		offset = (offset+1) % (640);
		vga.swapBuffer(); // call this after you finish drawing your frame to display it, it avoids screen tearing
	}
}

void demo_bochs_32() {
	EcranBochs vga(640, 400, VBE_MODE::_32);

	vga.init();
	
	ui8_t offset = 0;
	while(true) {
		
		for (int y = 0; y < vga.getHeight(); y++) {
			for (int x = 0; x < vga.getWidth(); x++) {
				vga.paint(x, y, 
					(~x << y%3) + offset & y, 
					~offset * (x & ~y), 
					offset | (~y < 2 - x % 16));
			}
		}
		++offset;
	}
}

extern "C" void Sextant_main(unsigned long magic, unsigned long addr){
	Ecran ecran;
	Timer timer;

	idt_setup();
	irq_setup();
	//Initialisation de la frequence de l'horloge

	timer.i8254_set_frequency(1000);
	irq_set_routine(IRQ_TIMER, ticTac);

	asm volatile("sti\n");//Autorise les interruptions

	irq_set_routine(IRQ_KEYBOARD, handler_clavier);

	multiboot_info_t* mbi;
	mbi = (multiboot_info_t*)addr;

	mem_setup(& __e_kernel,(mbi->mem_upper<<10) + (1<<20),&ecran);

	ecran.effacerEcran(NOIR);

	thread_subsystem_setup(bootstrap_stack_bottom,bootstrap_stack_size);
	sched_subsystem_setup();

	irq_set_routine(IRQ_TIMER, sched_clk);

	// initialize pci bus to detect GPU address
	checkBus(0);
	
    MenuMain mm;
    int choice = mm.run();
	/*
    switch (choice)
    {
    case 0:
        ecran.effacerEcran(NOIR);
        ecran.afficherMot(5,10,"START");
        //break;
    case 1:
        ecran.effacerEcran(NOIR);
        ecran.afficherMot(5,10,"QUIT");
        //break;
    default:
        ecran.effacerEcran(NOIR);
        ecran.afficherMot(5,10,"ERREUR");
        //break;
    }
	*/
	
	MenuCharacters mc;
	int choiceP1 = mc.run(1);
	int choiceP2 = mc.run(2);

	Game game(choiceP1, choiceP2);
	game.run();

	// demo_vga();

	// demo_bochs_8();

	// demo_bochs_32();
}
