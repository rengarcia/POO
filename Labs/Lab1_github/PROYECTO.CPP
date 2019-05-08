/***
**
*
Proyecto final del primer semestre
Elaborado por: 
			   Sebastian Alavrez
			   Carlos Puco
Carrera de Ingenieria de Software
Materias:
		  Fundamentos de Ingenieria de Software
		  Fundamentos de programacion
*
**
***/
#include <winbgim.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

/* Estructura para las posiciones x,y del personaje y enemigos */
struct posicion{
	int x,y;
};

/* Variables gloables que controlan la impresion de billetes durante el juego */
bool b1=true;int cb1=1;
bool b2=true;int cb2=1;
bool b3=true;int cb3=1;
bool b4=true;int cb4=1;
bool b5=true;int cb5=1;
bool b6=true;int cb6=1;
bool b7=true;int cb7=1;
bool b8=true;int cb8=1;
bool b9=true;int cb9=1;
bool b10=true;int cb10=1;
bool b11=true;int cb11=1;
bool b12=true;int cb12=1;
bool b13=true;int cb13=1;
bool b14=true;int cb14=1;
bool b15=true;int cb15=1;
bool b16=true;int cb16=1;
bool b17=true;int cb17=1;
bool b18=true;int cb18=1;
/* Variable global que controla el puntaje del jugador mientras juega */
int score=0;

void space_menu (void);                    /* refiere a la interfaz del menu de inicio*/
void letras (void);                        /* refiere al nombre del juego, version y numero de demo dentro del menu de inicio*/
void figure1 (void);                       /* refiere al modelo del enemigo (policia) en el menu de inicio (estatico)*/
void figure2 (void);                       /* refiere al modelo del personaje (ladron) en el menu de inicio (estatico)*/
void space (void);                         /* refiere a la interfaz del fondo dentro de la opcion "Iniciar juego"*/
void bills (void);                         /* refiere a los billetes regados en la opcion "Iniciar juego"*/
void personaje (posicion);                 /* refiere al modelo jugable del personaje (ladron)*/
void personaje_clear (posicion);		   /* refiere al mismo modelo del personaje pero en negro*** utilidad=limpiar al personaje para cada movimiento*/	
void salida (void);                        /* refiere a la interfaz de de opcion "salir"*/
void felicitaciones (void);				   /* refiere a el mensaje de felicitaciones al terminar el juego*/
void historia (void);			   		   /* refiere a una introduccion antes de inicializar la opcion "iniciar juego"*/								
int poner_color (void);                    /* refiere a una funcion auxiliar al diseño de la opcion "salir"*** utilidad=pinta pixeles de colores en el fondo*/
void creditos (void);                      /* refiere a la interfaz de la opcion "creditos"*/
void letras_2 (void);                      /* refiere a las letras dentro de la funcion "historia"*/
void letras3 (void);					   /* refiere a las letras dentro de la interfaz "como jugar"*/
void mensaje1 (void);					   /* refiere al mensaje emergente al presionar una tecla erronea en el menu de inicio*/
void mensaje2 (void);					   /* refiere al mensaje emergente al presionar esc durante el juego*/
void mensaje3 (void);					   /* refiere al mensaje cuando el policia atrapa al ladron*/
void mensaje_final (void);				   /* refiere al mensaje cuando el usuario atrapa todos los billetes y gana el juego*/
void comojugar (void);					   /* refiere a una inferfaz que muestra al usuarios como jugar previo al juego*/
void mensajetutorial (void);			   /* refiere a un mensaje de opcion que indica si quieres ver historia, como jugar o saltartelo*/
void policia (posicion);				   /* refiere al modelo jugable del enemigo (policia)*/
void enemigo_clear (posicion);      	   /* refiere al mismo modelo del enemigo pero en negro*** utilidad=limpia el enemigo para cada movimiento*/
void *jugar_EDLL (void *);	   		       /* refiere a la funcion que controla el movimiento de los personajes, colisiones y puntajes.*/
void bills (posicion);					   /* refiere a la funcion que imprime billetes y verifica si el usuario los recogio*/

main(){
	initwindow(1350,700);
	
	for(;;) /* Un ciclo for infinito cuyo proposito es
			   que el menu de inicio solo pueda finalizar
			   el juego al presionar "salir" */
	{
		cleardevice();
		
		/* Se utiliza las funciones de interfaz del menu de inicio */
		space_menu();
		letras();
		figure1();
		figure2();

		PlaySound("8bit.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
		
		char opcion;
		
		do /* Ciclo do while que controla las opciones a elegir
		     dentro del menu de inicio */
		{
			opcion=getch();
		
			switch(opcion)
			{
				case 49: /* En el caso de presionar 1 (Iniciar juego) */
					PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
					char tecla;
					char teclasalida;
					char pie;
	
					posicion usuario,enemigo,enemigo2;
					
					/* Se declaran las posiciones iniciales del personaje y enemigos */
					usuario.x=675;
					usuario.y=600;
				
					enemigo.x=100;
					enemigo.y=100;
					
					enemigo2.x=1250;
					enemigo2.y=100;
					
					cleardevice();
					mensajetutorial();
					
					do /* Ciclo do while que controla las opciones a elegir
					      si quieres ver el tutorial o saltar directo al juego */
					{
  						
						void *arg;
						pie=getch();
						
						switch(pie)
						{
							case 49: /* En el caso de presionar "Ver tutorial" */
								PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
								cleardevice();
								PlaySound("music1.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
								/* Se usan las funciones "historia" y "comojugar" porque
								   muestran la historia del juego y los controles para jugar */
								historia();
								cleardevice();
								comojugar();
								Sleep(8000);
								cleardevice();
								PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
								space();
								bills(usuario);
								personaje(usuario);
								policia(enemigo);
								policia(enemigo2);
								
								/* La funcion jugar_EDLL domina los controles del personaje y enemigos durante el juego */
								jugar_EDLL(arg);	
								break;	
							case 50: /* En el caso de oprimir "Saltar historia" */
								PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
								cleardevice();
								PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
								space();
								bills(usuario);
								personaje(usuario);
								policia(enemigo);
								policia(enemigo2);
								   
								/* La funcion jugar_EDLL domina los controles del personaje y enemigos durante el juego */
								jugar_EDLL(arg);	
								break;										
						}
					}while(pie!=27); /* Si se presiona ESC el juego finaliza */
					cleardevice();
					PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
					PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					mensaje2();
					exit(1);
				case 51: /* En el caso de presionar la opcion "Salir" en el menu de inicio */
					PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
					cleardevice();
					PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					salida();
					Sleep(4000);
					exit(1);	
				case 50: /* En el caso de presionar la opcion "creditos" en el menu de inicio */
					PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
					cleardevice();
					PlaySound("music1.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					creditos();	
					break;	
				default: /* En el caso de no presionar ninguna tecla pertinente
				            el videjuego va a saltar un mensaje indicandole que 
							presione una tecla correcta */
					PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
					mensaje1();
					PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					break;
			}
		}while(opcion!=27);	/* Si se presiona ESC en el menu de inicio
		   					   se devuelve al ciclo for infinito que vuelve
							   a cargar el menu de inicio, se usa como control
							   en la funcion "creditos" y en el mensaje
							   emergente cuando se presiona una tecla erronea
							   en el menu de inicio */
	}
}

void bills (posicion usuario){	
	char puntaje[40];
	
	if(usuario.y>50 && usuario.y<150){
		if(usuario.x>240 && usuario.x<300){
			b1=false;
			if(cb1==1){
				score=score+100;
				setcolor(0);
				rectangle(248,88,292,112);
				setfillstyle(1,0);
				floodfill(260,100,0);
				cb1=0;
			}
		}
		if(usuario.x>420 && usuario.x<480){
			b2=false;
			if(cb2==1){
				score=score+100;
				setcolor(0);
				rectangle(428,88,472,112);
				setfillstyle(1,0);
				floodfill(440,100,0);
				cb2=0;
			}
		}
		if(usuario.x>640 && usuario.x<700){
			b3=false;
			if(cb3==1){
				score=score+100;
				setcolor(0);
				rectangle(648,88,692,112);
				setfillstyle(1,0);
				floodfill(660,100,0);
				cb3=0;
			}
		}
		if(usuario.x>870 && usuario.x<930){
			b4=false;
			if(cb4==1){
				score=score+100;
				setcolor(0);
				rectangle(878,88,922,112);
				setfillstyle(1,0);
				floodfill(890,100,0);
				cb4=0;
			}
		}
		if(usuario.x>1050 && usuario.x<1110){
			b5=false;
			if(cb5==1){
				score=score+100;
				setcolor(0);
				rectangle(1058,88,1102,112);
				setfillstyle(1,0);
				floodfill(1070,100,0);
				cb5=0;
			}
		}
	}
	if(usuario.y>550 && usuario.y<650){
		if(usuario.x>240 && usuario.x<300){
			b6=false;
			if(cb6==1){
				score=score+100;
				setcolor(0);
				rectangle(248,588,292,612);
				setfillstyle(1,0);
				floodfill(260,600,0);
				cb6=0;
			}
		}
		if(usuario.x>420 && usuario.x<480){
			b7=false;
			if(cb7==1){
				score=score+100;
				setcolor(0);
				rectangle(428,588,472,612);
				setfillstyle(1,0);
				floodfill(440,600,0);
				cb7=0;
			}
		}
		if(usuario.x>870 && usuario.x<930){
			b8=false;
			if(cb8==1){
				score=score+100;
				setcolor(0);
				rectangle(878,588,922,612);
				setfillstyle(1,0);
				floodfill(890,600,0);
				cb8=0;
			}
		}
		if(usuario.x>1050 && usuario.x<1110){
			b9=false;
			if(cb9==1){
				score=score+100;
				setcolor(0);
				rectangle(1058,588,1102,612);
				setfillstyle(1,0);
				floodfill(1070,600,0);
				cb9=0;
			}
		}
	}
	if(usuario.x>50 && usuario.x<150){
		if(usuario.y>210 && usuario.y<250){
			b10=false;
			if(cb10==1){
				score=score+100;
				setcolor(0);
				rectangle(78,218,122,242);
				setfillstyle(1,0);
				floodfill(100,230,0);
				cb10=0;
			}
		}
		if(usuario.y>460 && usuario.y<500){
			b11=false;
			if(cb11==1){
				score=score+100;
				setcolor(0);
				rectangle(78,468,122,492);
				setfillstyle(1,0);
				floodfill(100,480,0);
				cb11=0;
			}
		}
	}
	if(usuario.x>410 && usuario.x<490){
		if(usuario.y>250 && usuario.y<290){
			b12=false;
			if(cb12==1){
				score=score+100;
				setcolor(0);
				rectangle(428,258,472,282);
				setfillstyle(1,0);
				floodfill(440,270,0);
				cb12=0;
			}
		}
		if(usuario.y>400 && usuario.y<440){
			b13=false;
			if(cb13==1){
				score=score+100;
				setcolor(0);
				rectangle(428,408,472,432);
				setfillstyle(1,0);
				floodfill(440,420,0);
				cb13=0;
			}
		}
	}
	if(usuario.x>860 && usuario.x<940){
		if(usuario.y>250 && usuario.y<290){
			b14=false;
			if(cb14==1){
				score=score+100;
				setcolor(0);
				rectangle(878,258,922,282);
				setfillstyle(1,0);
				floodfill(900,270,0);
				cb14=0;
			}
		}
		if(usuario.y>400 && usuario.y<440){
			b15=false;
			if(cb15==1){
				score=score+100;
				setcolor(0);
				rectangle(878,408,922,432);
				setfillstyle(1,0);
				floodfill(900,420,0);
				cb15=0;
			}
		}
	}
	if(usuario.x>1210 && usuario.x<1290){
		if(usuario.y>210 && usuario.y<250){
			b16=false;
			if(cb16==1){
				score=score+100;
				setcolor(0);
				rectangle(1228,218,1272,242);
				setfillstyle(1,0);
				floodfill(1250,230,0);
				cb16=0;
			}
		}
		if(usuario.y>460 && usuario.y<500){
			b17=false;
			if(cb17==1){
				score=score+100;
				setcolor(0);
				rectangle(1228,468,1272,492);
				setfillstyle(1,0);
				floodfill(1250,480,0);
				cb17=0;
			}
		}
	}
	if(usuario.y>320 && usuario.y<380){
		if(usuario.x>640 && usuario.x<700){
			b18=false;
			if(cb18==1){
				score=score+100;
				setcolor(0);
				rectangle(648,338,692,362);
				setfillstyle(1,0);
				floodfill(660,350,0);
				cb18=0;
			}
		}
	}
	sprintf(puntaje,"%d",score);
	setcolor(0);
	rectangle(1255,25,1300,45);
	setfillstyle(1,0);
	floodfill(1270,30,0);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(1255,25,puntaje);
	if(score==1800){
		PlaySound("music1.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
		personaje(usuario);
		mensaje_final();
		salida();
		Sleep(4000);
		exit(1);
	}
	if(b1==true){
		setcolor(2);
		rectangle(250,90,290,110);
		setfillstyle(1,2);
		floodfill(260,100,2);
		setcolor(10);
		rectangle(252,92,288,108);
	}
	if(b2==true){
		setcolor(2);
		rectangle(430,90,470,110);
		setfillstyle(1,2);
		floodfill(440,100,2);
		setcolor(10);
		rectangle(432,92,468,108);
	}
	if(b3==true){
		setcolor(2);
		rectangle(650,90,690,110);
		setfillstyle(1,2);
		floodfill(660,100,2);
		setcolor(10);
		rectangle(652,92,688,108);
	}
	if(b4==true){
		setcolor(2);
		rectangle(880,90,920,110);
		setfillstyle(1,2);
		floodfill(890,100,2);
		setcolor(10);
		rectangle(882,92,918,108);
	}
	if(b5==true){
		setcolor(2);
		rectangle(1060,90,1100,110);
		setfillstyle(1,2);
		floodfill(1070,100,2);
		setcolor(10);
		rectangle(1062,92,1098,108);
	}
	if(b6==true){
		setcolor(2);
		rectangle(250,590,290,610);
		setfillstyle(1,2);
		floodfill(260,600,2);
		setcolor(10);
		rectangle(252,592,288,608);
	}
	if(b7==true){
		setcolor(2);
		rectangle(430,590,470,610);
		setfillstyle(1,2);
		floodfill(440,600,2);
		setcolor(10);
		rectangle(432,592,468,608);
	}
	if(b8==true){
		setcolor(2);
		rectangle(880,590,920,610);
		setfillstyle(1,2);
		floodfill(890,600,2);
		setcolor(10);
		rectangle(882,592,918,608);
	}
	if(b9==true){
		setcolor(2);
		rectangle(1060,590,1100,610);
		setfillstyle(1,2);
		floodfill(1070,600,2);
		setcolor(10);
		rectangle(1062,592,1098,608);
	}
	if(b10==true){
		setcolor(2);
		rectangle(80,220,120,240);
		setfillstyle(1,2);
		floodfill(100,230,2);
		setcolor(10);
		rectangle(82,222,118,238);
	}
	if(b11==true){
		setcolor(2);
		rectangle(80,470,120,490);
		setfillstyle(1,2);
		floodfill(100,480,2);
		setcolor(10);
		rectangle(82,472,118,488);
	}
	if(b12==true){
		setcolor(2);
		rectangle(430,260,470,280);
		setfillstyle(1,2);
		floodfill(440,270,2);
		setcolor(10);
		rectangle(432,262,468,278);
	}
	if(b13==true){
		setcolor(2);
		rectangle(430,410,470,430);
		setfillstyle(1,2);
		floodfill(440,420,2);
		setcolor(10);
		rectangle(432,412,468,428);
	}
	if(b14==true){
		setcolor(2);
		rectangle(880,260,920,280);
		setfillstyle(1,2);
		floodfill(900,270,2);
		setcolor(10);
		rectangle(882,262,918,278);
	}
	if(b15==true){
		setcolor(2);
		rectangle(880,410,920,430);
		setfillstyle(1,2);
		floodfill(900,420,2);
		setcolor(10);
		rectangle(882,412,918,428);
	}
	if(b16==true){
		setcolor(2);
		rectangle(1230,220,1270,240);
		setfillstyle(1,2);
		floodfill(1250,230,2);
		setcolor(10);
		rectangle(1232,222,1268,238);
	}
	if(b17==true){
		setcolor(2);
		rectangle(1230,470,1270,490);
		setfillstyle(1,2);
		floodfill(1250,480,2);
		setcolor(10);
		rectangle(1232,472,1268,488);
	}
	if(b18==true){
		setcolor(2);
		rectangle(650,340,690,360);
		setfillstyle(1,2);
		floodfill(660,350,2);
		setcolor(10);
		rectangle(652,342,688,358);
	}
}

void space_menu (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(8);
	rectangle(525,230,825,330);
	rectangle(525,355,825,455);
	rectangle(525,480,825,580);
	setcolor(3);
	rectangle(527,232,823,328);
	rectangle(527,357,823,453);
	rectangle(527,482,823,578);
	setfillstyle(1,3);
	floodfill(530,235,3);
	floodfill(530,360,3);
	floodfill(530,485,3);
}

void figure1 (void){
	setcolor(14);
	circle(300,425,150);
	setfillstyle(1,14);
	fillellipse(300,425,150,150);
	setcolor(8);
	sector(300,425,180,360,150,150);
	setcolor(1);
	rectangle(150,425,450,550);
	setfillstyle(1,1);
	floodfill(300,450,1);
	setcolor(1);
	rectangle(285,255,365,300);
	setfillstyle(1,1);
	floodfill(300,270,1);
	setcolor(4);
	settextstyle(4,0,6);
	outtextxy(220,260,"!!");
	setcolor(14);
	circle(325,270,10);
	setfillstyle(1,14);
	fillellipse(325,270,10,10);
	setcolor(6);
	circle(325,270,6);
	circle(325,270,5);
	setcolor(8);
	moveto(300,425);
	lineto(275,445);
	lineto(250,425);
	moveto(301,425);
	lineto(276,445);
	lineto(251,425);
	moveto(300,425);
	lineto(250,425);
	moveto(300,425);
	lineto(325,445);
	lineto(350,425);
	moveto(299,425);
	lineto(324,445);
	lineto(349,425);
	moveto(300,425);
	lineto(350,425);
	setfillstyle(1,8);
	floodfill(275,430,8);
	floodfill(325,430,8);
}

void figure2 (void){
	setcolor(14);
	circle(1050,425,150);
	setfillstyle(1,14);
	fillellipse(1050,425,150,150);
	setcolor(8);
	sector(1050,425,180,360,150,150);
	setcolor(15);
	rectangle(900,425,1200,550);
	setfillstyle(1,15);
	floodfill(1050,450,15);
	setcolor(14);
	circle(1070,290,45);
	setcolor(15);
	sector(1070,290,0,180,45,45);
	setcolor(0);
	rectangle(915,425,945,550);
	rectangle(975,425,1005,550);
	rectangle(1035,425,1065,550);
	rectangle(1095,425,1125,550);
	rectangle(1155,425,1185,550);
	setfillstyle(1,0);
	floodfill(920,430,0);
	floodfill(980,430,0);
	floodfill(1040,430,0);
	floodfill(1100,430,0);
	floodfill(1160,430,0);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(1045,265,"USER");
}

void letras (void){
	setcolor(15);
	settextstyle(2,0,9);
	outtextxy(527,265,"1. INICIAR JUEGO");
	outtextxy(563,390,"2. CREDITOS");	
	outtextxy(610,515,"3. SALIR");
	settextstyle(3,0,9);
	outtextxy(120,100,"ESCAPE DE LA LEY");
	settextstyle(7,0,4);
	outtextxy(900,200,"DEMO JUGABLE");
	settextstyle(7,0,3);
	outtextxy(60,615,"V:2.1.1");
	settextstyle(2,0,7);
}

void personaje (posicion usuario){
	setcolor(14);
	circle(usuario.x,usuario.y,30);
	setfillstyle(1,14);
	fillellipse(usuario.x,usuario.y,30,30);
	setcolor(8);
	sector(usuario.x,usuario.y,180,360,30,30);
	setcolor(15);
	rectangle(usuario.x-29,usuario.y,usuario.x+29,usuario.y+20);
	setfillstyle(1,15);
	floodfill(usuario.x,usuario.y+10,15);
	setcolor(14);
	circle(usuario.x+5,usuario.y-25,12);
	setcolor(15);
	sector(usuario.x+5,usuario.y-25,0,-180,12,12);
	setcolor(0);
	rectangle(usuario.x-25,usuario.y,usuario.x-15,usuario.y+20);
	rectangle(usuario.x-5,usuario.y,usuario.x+5,usuario.y+20);
	rectangle(usuario.x+15,usuario.y,usuario.x+25,usuario.y+20);
	rectangle(usuario.x,usuario.y-30,usuario.x+10,usuario.y-35);
	setfillstyle(1,0);
	floodfill(usuario.x-22,usuario.y+3,0);
	floodfill(usuario.x-2,usuario.y+3,0);
	floodfill(usuario.x+17,usuario.y+3,0);
	floodfill(usuario.x+2,usuario.y-32,0);
}

void policia (posicion enemigo){
	setcolor(14);
	circle(enemigo.x,enemigo.y,30);
	setfillstyle(1,14);
	fillellipse(enemigo.x,enemigo.y,30,30);
	setcolor(8);
	sector(enemigo.x,enemigo.y,180,360,30,30);
	setcolor(1);
	rectangle(enemigo.x-30,enemigo.y,enemigo.x+30,enemigo.y+20);
	setfillstyle(1,1);
	floodfill(enemigo.x,enemigo.y+10,1);
	rectangle(enemigo.x-3,enemigo.y-35,enemigo.x+15,enemigo.y-25);
	setfillstyle(1,1);
	floodfill(enemigo.x+2,enemigo.y-30,1);
}

void personaje_clear (posicion usuario){
	setcolor(0);
	circle(usuario.x,usuario.y,30);
	setfillstyle(1,0);
	fillellipse(usuario.x,usuario.y,30,30);
	rectangle(usuario.x-32,usuario.y-2,usuario.x+32,usuario.y+22);
	setfillstyle(1,0);
	floodfill(usuario.x,usuario.y+10,0);
	floodfill(usuario.x-29,usuario.y+10,0);
	floodfill(usuario.x+28,usuario.y+10,0);
	circle(usuario.x+5,usuario.y-25,13);
	sector(usuario.x+5,usuario.y-25,0,-180,13,13);
}

void enemigo_clear (posicion enemigo){
	setcolor(0);
	circle(enemigo.x,enemigo.y,32);
	setfillstyle(1,0);
	fillellipse(enemigo.x,enemigo.y,32,32);
	sector(enemigo.x,enemigo.y,180,360,32,32);
	rectangle(enemigo.x-32,enemigo.y-2,enemigo.x+32,enemigo.y+22);
	setfillstyle(1,0);
	floodfill(enemigo.x,enemigo.y+10,0);
	floodfill(enemigo.x-30,enemigo.y+20,0);
	floodfill(enemigo.x+30,enemigo.y+20,0);
	floodfill(enemigo.x+30,enemigo.y+21,0);
	rectangle(enemigo.x-9,enemigo.y-39,enemigo.x+19,enemigo.y-5);
	setfillstyle(1,0);
	floodfill(enemigo.x+12,enemigo.y-30,0);
	floodfill(enemigo.x-7,enemigo.y-37,0);
}

void space (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(8);
	rectangle(150,150,400,550);
	rectangle(950,150,1200,550);
	rectangle(500,150,850,300);
	rectangle(500,400,850,550);
    setfillstyle(1,8);
	floodfill(200,200,8);
	floodfill(1000,200,8);
	floodfill(550,200,8);
	floodfill(550,450,8);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(50,25,"VIDAS RESTANTES: 3");
	outtextxy(1180,25,"SCORE: ");
	setcolor(15);
	rectangle(150,150,400,550);
	rectangle(950,150,1200,550);
	rectangle(500,150,850,300);
	rectangle(500,400,850,550);
	
	line(150,500,400,500);
	line(150,450,400,450);
	line(150,400,400,400);
	line(150,350,400,350);
	line(150,300,400,300);
	line(150,250,400,250);
	line(150,200,400,200);
	line(180,450,180,400);//arriba de abajo
	line(280,450,280,400);
	line(380,450,380,400);
	line(195,500,195,450);
	line(250,500,250,450);//medio de abajo
	line(310,500,310,450);
	line(365,500,365,450);
	line(180,550,180,500);//abajo de abajo
	line(280,550,280,500);
	line(380,550,380,500);
	line(195,400,195,350);
	line(250,400,250,350);//medio de abajo
	line(310,400,310,350);
	line(365,400,365,350);
	line(180,350,180,300);//arriba de abajo
	line(280,350,280,300);
	line(380,350,380,300);
	line(195,300,195,250);
	line(250,300,250,250);//medio de abajo
	line(310,300,310,250);
	line(365,300,365,250);
	line(180,250,180,200);//arriba de abajo
	line(280,250,280,200);
	line(380,250,380,200);
	line(195,200,195,150);
	line(250,200,250,150);//medio de abajo
	line(310,200,310,150);
	line(365,200,365,150);
	line(950,500,1200,500);
	line(950,450,1200,450);
	line(950,400,1200,400);
	line(950,350,1200,350);
	line(950,300,1200,300);
	line(950,250,1200,250);
	line(950,200,1200,200);
    line(965,200,965,150);//arriba de arriba
	line(1040,200,1040,150);
	line(1120,200,1120,150);
	line(1185,200,1185,150);
	line(1000,250,1000,200);//medio de arriba
	line(1080,250,1080,200);
	line(1160,250,1160,200);
	line(965,300,965,250);//arriba de arriba
	line(1040,300,1040,250);
	line(1120,300,1120,250);
	line(1185,300,1185,250);
	line(1000,350,1000,300);//medio de arriba
	line(1080,350,1080,300);
	line(1160,350,1160,300);
	line(965,400,965,350);//arriba de arriba
	line(1040,400,1040,350);
	line(1120,400,1120,350);
	line(1185,400,1185,350);
	line(1000,450,1000,400);//medio de arriba
	line(1080,450,1080,400);
	line(1160,450,1160,400);
	line(965,500,965,450);//arriba de arriba
	line(1040,500,1040,450);
	line(1120,500,1120,450);
	line(1185,500,1185,450);
	line(1000,550,1000,500);//medio de arriba
	line(1080,550,1080,500);
	line(1160,550,1160,500);
	line(850,500,500,500);
	line(850,450,500,450);
	line(500,200,850,200);
	line(500,250,850,250);
	line(780,250,780,200);//medio de arriba
	line(672,250,672,200);
	line(552,250,552,200);
	line(800,200,800,150);//arriba de arriba
	line(572,200,572,150);
	line(642,200,642,150);
	line(722,200,722,150);
	line(800,300,800,250);//arriba de abajo
	line(572,300,572,250);
	line(642,300,642,250);
	line(722,300,722,250);
	line(790,500,790,450);
	line(700,500,700,450);//medio de abajo
	line(620,500,620,450);
	line(540,500,540,450);
	line(770,550,770,500);//abajo de abajo
	line(680,550,680,500);
	line(580,550,580,500);
	line(770,450,770,400);//arriba de abajo
	line(680,450,680,400);
	line(580,450,580,400);
}

void salida (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	
	setcolor(15);
	settextstyle(2,0,10);
	outtextxy(400,300,"GRACIAS POR JUGAR :)");
	
	int x,y,i,color;
	setcolor(15);
	
	for(i=1;i<=200;i++)
	{
		x=rand()%1200;
		y=rand()%800;
		color=poner_color();
		putpixel(x,y,color);
	}
}

void felicitaciones (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	
	setcolor(15);
	settextstyle(2,0,10);
	outtextxy(450,300,"FELICIDADES!");
	
	int x,y,i,color;
	setcolor(15);
	
	for(i=1;i<=200;i++)
	{
		x=rand()%1200;
		y=rand()%800;
		color=poner_color();
		putpixel(x,y,color);
	}
}

void historia (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(400,250,"...");
	cleardevice();
	letras_2();
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(150,500,"POR EL MOMENTO ERES UN LADRON QUE ACABA DE ESCAPAR DE PRISION...");
	figure2();
	Sleep(4000);
	cleardevice();
	letras_2();
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(500,500,"RECOGE TUS BILLETES EN EL MENOR TIEMPO POSIBLE Y ESCAPA DE LA LEY!");
	figure1();
	Sleep(4000);
	cleardevice();
	letras_2();
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(600,600,"...");
	cleardevice();
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
}

int poner_color(void){
	int c;
	c=rand()%4;
	
	switch(c)
	{
		case 0:c=1;break;
		case 1:c=14;break;
		case 2:c=4;break;
		case 3:c=15;break;
	}
	return c;
}

void creditos (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	
	setcolor(3);
	rectangle(450,90,860,150);
	rectangle(100,600,400,635);
	rectangle(950,260,1200,550);
	rectangle(140,260,400,550);
	setfillstyle(1,3);
	floodfill(500,100,3);
	floodfill(150,610,3);
	floodfill(1000,300,3);
	floodfill(200,300,3);
	setcolor(7);
	rectangle(448,88,862,152);
	rectangle(98,598,402,637);
	rectangle(948,258,1202,552);
	rectangle(138,258,402,552);
	setcolor(15);
	settextstyle(2,0,10);
	outtextxy(540,100,"CREDITOS");
	settextstyle(2,0,9);
	outtextxy(235,180,"UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	settextstyle(2,0,8);
	outtextxy(335,220,"CARRERA DE INGENIERIA DE SOFTWARE");
	outtextxy(495,260,"PRIMER SEMESTRE");
	outtextxy(480,330,"DESARROLLADO POR: ");
	outtextxy(555,460,"MUSICA POR: ");
	outtextxy(957,280,"DEDICATORIA");
	outtextxy(985,310,"ESPECIAL");
	outtextxy(149,280,"INFORMACION");
	outtextxy(172,310,"DEL JUEGO");
	settextstyle(2,0,7);
	outtextxy(555,380,"- SEBASTIAN ALVAREZ -");
	outtextxy(590,410,"- RENAN GARCIA -");
	outtextxy(575,510,"- BRIAN LEBARTON -");
	outtextxy(535,540,"THRESHOLD (VERSION 8 BITS)");
	outtextxy(420,570,"SCOTT PILGRIM VS. THE WORLD (ORIGINAL SOUNDTRACK)");
	outtextxy(110,607,"Presione ESC para volver al menu");
	outtextxy(960,360,"ESTE VIDEOJUEGO NO");
	outtextxy(960,380,"HUBIERA SIDO POSIBLE");
	outtextxy(960,400,"SIN LA AYUDA MORAL DE");
	outtextxy(960,420,"FABIAN VALENCIA QUE");
	outtextxy(960,440,"MENTALMENTE SIEMPRE");
	outtextxy(960,460,"NOS AYUDO Y ESTUVO");
	outtextxy(960,480,"AHI PARA APOYARNOS");
	outtextxy(960,510,"LE AGRADECEMOS...");
	outtextxy(150,350,"ESTE VIDEOJUEGO FUE");
	outtextxy(150,370,"GENERADO EN LENGUAJE");
	outtextxy(150,390,"C COMO PROYECTO FINAL");
	outtextxy(150,410,"DEL PRIMER SEMESTRE");
	outtextxy(150,430,"CON LA FINALIDAD DE");
	outtextxy(150,450,"USAR LO APRENDIDO");
	outtextxy(150,470,"EN CLASE Y PODER");
	outtextxy(150,490,"PREPARANDONOS PARA");
	outtextxy(150,510,"EL FUTURO...");
}

void letras_2 (void){
	setcolor(15);
	settextstyle(2,0,10);
	outtextxy(150,150,"HISTORIA");
}

void mensaje1 (void){
	setcolor(15);
	rectangle(400,200,950,550);
	setcolor(15);
	rectangle(401,201,949,549);
	setcolor(4);
	rectangle(404,204,946,546);
	setfillstyle(1,4);
	floodfill(410,210,4);
	setcolor(15);
	settextstyle(2,0,9);
	outtextxy(470,270,"INGRESE UNA OPCION");
	settextstyle(2,0,10);
	outtextxy(530,310,"CORRECTA!!!");
	settextstyle(2,0,7);
	outtextxy(520,465,"Presione esc para volver al menu...");
	settextstyle(2,0,10);
	outtextxy(640,380,":'(");
}

void mensaje2 (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	
	setcolor(15);
	rectangle(400,200,950,550);
	setcolor(15);
	rectangle(401,201,949,549);
	setcolor(4);
	rectangle(404,204,946,546);
	setfillstyle(1,4);
	floodfill(410,210,4);
	setcolor(15);
	settextstyle(2,0,9);
	outtextxy(485,350,"Finalizando el juego...");
	settextstyle(2,0,7);
	outtextxy(530,420,"Esperamos que vuelva pronto :)");
	setcolor(0);
	settextstyle(2,0,10);
	outtextxy(400,460,"");
	Sleep(3000);
	cleardevice();
	salida();
	Sleep(4000);
}

void mensaje3 (void){
	setcolor(15);
	rectangle(400,200,950,550);
	setcolor(15);
	rectangle(401,201,949,549);
	setcolor(4);
	rectangle(404,204,946,546);
	setfillstyle(1,4);
	floodfill(410,210,4);
	setcolor(15);
	settextstyle(2,0,9);
	outtextxy(485,350,"Usted ha sido capturado...");
	settextstyle(2,0,7);
	outtextxy(550,420,"Finalizando el juego :(");
	setcolor(0);
	settextstyle(2,0,10);
	outtextxy(400,460,"");
	Sleep(5000);
	cleardevice();
	salida();
	Sleep(4000);
}

void mensaje_final (void){
	setcolor(15);
	rectangle(400,200,950,550);
	setcolor(15);
	rectangle(401,201,949,549);
	setcolor(4);
	rectangle(404,204,946,546);
	setfillstyle(1,4);
	floodfill(410,210,4);
	setcolor(15);
	settextstyle(2,0,9);
	outtextxy(485,260,"Usted ha recogido");
	outtextxy(485,320,"todos los billetes");
	settextstyle(2,0,7);
	outtextxy(550,500,"Ha escapado de la ley!!!");
	setcolor(0);
	settextstyle(2,0,10);
	outtextxy(400,460,"");
	Sleep(5000);
	cleardevice();
	felicitaciones();
	Sleep(6000);
}

void comojugar (void){
	letras3();
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(4);
	rectangle(750,200,1155,260);
	setfillstyle(1,4);
	floodfill(800,250,4);
	setcolor(15);
	rectangle(748,198,1157,262);
	settextstyle(2,0,9);
	outtextxy(150,300,"CONTROLES:");
	settextstyle(2,0,8);
	outtextxy(150,400,"PRESIONE EL NUMERO 8 PARA MOVERSE HACIA ARRIBA");
	outtextxy(150,450,"PRESIONE EL NUMERO 4 PARA MOVERSE HACIA LA IZQUIERDA");
	outtextxy(150,500,"PRESIONE EL NUMERO 5 PARA MOVERSE HACIA ABAJO");
	outtextxy(150,550,"PRESIONE EL NUMERO 6 PARA MOVERSE HACIA LA DERECHA");
	setcolor(0);
	settextstyle(2,0,10);
	outtextxy(150,600,"");
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(770,210,"Recuerda: Puedes salir del juego en cualquier");
	outtextxy(770,230,"momento presionando la tecla esc :D");
	setcolor(0); 
	settextstyle(2,0,10);
	outtextxy(150,600,"");
	Sleep(10000);
	cleardevice();
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	setcolor(15);
	settextstyle(2,0,7);
	outtextxy(600,600,"CARGANDO...");
	setcolor(0);
	settextstyle(2,0,10);
	outtextxy(150,150,"");
}

void letras3(void){
	setcolor(15);
	settextstyle(2,0,10);
	outtextxy(150,150,"COMO JUGAR?");	
}

void mensajetutorial (void){
	setcolor(1);
	rectangle(50,50,1300,650);
	rectangle(49,49,1299,649);
	setcolor(7);
	rectangle(47,47,1302,652);
	
	setcolor(15);
	rectangle(400,200,950,550);
	setcolor(15);
	rectangle(401,201,949,549);
	setcolor(4);
	rectangle(404,204,946,546);
	setfillstyle(1,4);
	floodfill(410,210,4);
	setcolor(15);
	settextstyle(2,0,9);
	outtextxy(480,270,"DESEA CONOCER LA");
	outtextxy(480,300,"HISTORIA DEL JUEGO");
	outtextxy(460,330,"Y SABER COMO JUGAR?");
	settextstyle(2,0,7);
	outtextxy(420,440,"Presione 1 para mostrar el tutorial");
	outtextxy(420,470,"Presione 2 para saltarte el tutorial");
	outtextxy(420,500,"Presione esc para salir del juego");
	settextstyle(2,0,10);
	outtextxy(640,380,":)");
}

void *jugar_EDLL (void *arg){
	posicion usuario,enemigo,enemigo2,vidas;
	
	int cont=3;
	char mensaje[40];
	
	usuario.x=675;
	usuario.y=600;
	
	enemigo.x=100;
	enemigo.y=100;
	
	enemigo2.x=1250;
	enemigo2.y=100;
	
	vidas.x=50;
	vidas.y=25;
	
	char tecla;
	do
	{							
		tecla=getch();
		switch(tecla)
		{
		case 56: //PERSONAJE HACIA ARRIBA
			if(usuario.y<105)
			{
				usuario.y=107;
			}
			if((usuario.x>=120 && usuario.x<=430) || (usuario.x>=470 && usuario.x<=880) || (usuario.x>=920 && usuario.x<=1230))
				{
				if(usuario.y<600 && usuario.y>500)
				{
					usuario.y=600;
				}
			}
			if(usuario.x>=470 && usuario.x<=880)
			{
				if(usuario.y<350 && usuario.y>245)
				{
					usuario.y=350;
				}
			}
			personaje_clear(usuario);
			bills(usuario);
			moveto(usuario.x,usuario.y-=10);
			personaje(usuario);
			if(usuario.y>enemigo.y) //ENEMIGO HACIA ABAJO
			{
				if(enemigo.y>605)
				{
					enemigo.y=600;
				}
				if((enemigo.x>=120 && enemigo.x<=430) || (enemigo.x>=470 && enemigo.x<=880) || (enemigo.x>=920 && enemigo.x<=1230))
				{
					if(enemigo.y>100 && enemigo.y<200)
					{
						enemigo.y=100;
					}
				}
				if(enemigo.x>=470 && enemigo.x<=880)
				{
					if(enemigo.y>360 && enemigo.y<460)
					{
						enemigo.y=360;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x,enemigo.y+=10);
				policia(enemigo);
			}
			if(usuario.y<enemigo.y) //ENEMIGO HACIA ARRIBA
			{
				if(enemigo.y<105)
				{
					enemigo.y=107;
				}
				if((enemigo.x>=120 && enemigo.x<=430) || (enemigo.x>=470 && enemigo.x<=880) || (enemigo.x>=920 && enemigo.x<=1230))
					{
					if(enemigo.y<600 && enemigo.y>500)
					{
						enemigo.y=600;
					}
				}
				if(enemigo.x>=470 && enemigo.x<=880)
				{
					if(enemigo.y<350 && enemigo.y>245)
					{
						enemigo.y=350;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x,enemigo.y-=10);
				policia(enemigo);
			}
			if(usuario.x>enemigo2.x) //ENEMIGO 2 HACIA DERECHA
			{
				if(enemigo2.x>=1250)
				{
					enemigo2.x=1248;
				}
				if(enemigo2.y>=120 && enemigo2.y<=580)
				{
					if(enemigo2.x>105 && enemigo2.x<215)
					{
						enemigo2.x=105;
					}
					if(enemigo2.x>905 && enemigo2.x<1015)
					{
						enemigo2.x=905;
					}
				}
				if((enemigo2.y>=120 && enemigo2.y<=330) || (enemigo2.y>=370 && enemigo2.y<=580))
				{
					if(enemigo2.x>455 && enemigo2.x<565)
					{
						enemigo2.x=455;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x+=10,enemigo2.y);
				policia(enemigo2);
			}
			if(usuario.x<enemigo2.x) //ENEMIGO 2 HACIA IZQUIERDA
			{
				if(enemigo2.x<=100)
				{
					enemigo2.x=102;
				}
				if(enemigo2.y>=120 && enemigo2.y<=580)
				{
					if(enemigo2.x<445 && enemigo2.x>145)
					{
						enemigo2.x=445;
					}
					if(enemigo2.x<1245 && enemigo2.x>955)
					{
						enemigo2.x=1245;
					}
				}
				if((enemigo2.y>=120 && enemigo2.y<=330) || (enemigo2.y>=370 && enemigo2.y<=580))
				{
					if(enemigo2.x<895 && enemigo2.x>750)
					{
						enemigo2.x=895;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x-=10,enemigo2.y);
				policia(enemigo2);
			}
			if(((usuario.x+30>enemigo.x-30) && (usuario.x+30<enemigo.x+30)) || ((usuario.x-30>enemigo.x-30) && (usuario.x-30<enemigo.x+30)) || usuario.x==enemigo.x)
			{
				if(((usuario.y-30>enemigo.y-30) && (usuario.y-30<enemigo.y+30)) || usuario.y==enemigo.y)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x,vidas.y,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo);
						mensaje3();
						exit(1);
					}
				}
			}
			if(((usuario.y+30>enemigo2.y-30) && (usuario.y+30<enemigo2.y+30)) || ((usuario.y-30>enemigo2.y-30) && (usuario.y-30<enemigo2.y+30)) || usuario.y==enemigo2.y)
			{
				if(((usuario.x+30>enemigo2.x-30) && (usuario.x+30<enemigo2.x+30)) || usuario.x==enemigo2.x)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x-5,vidas.y-5,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo2);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo2);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo2);
						mensaje3();
						exit(1);
					}
				}
			}
			break;
		case 53: //PERSONAJE HACIA ABAJO
			if(usuario.y>605)
			{
				usuario.y=600;
			}
			if((usuario.x>=120 && usuario.x<=430) || (usuario.x>=470 && usuario.x<=880) || (usuario.x>=920 && usuario.x<=1230))
			{
				if(usuario.y>100 && usuario.y<200)
				{
					usuario.y=100;
				}
			}
			if(usuario.x>=470 && usuario.x<=880)
			{
				if(usuario.y>360 && usuario.y<460)
				{
					usuario.y=360;
				}
			}
			personaje_clear(usuario);
			bills(usuario);
			moveto(usuario.x,usuario.y+=10);
			personaje(usuario);
			if(usuario.y>enemigo.y) //ENEMIGO HACIA ABAJO
			{
				if(enemigo.y>605)
				{
					enemigo.y=600;
				}
				if((enemigo.x>=120 && enemigo.x<=430) || (enemigo.x>=470 && enemigo.x<=880) || (enemigo.x>=920 && enemigo.x<=1230))
				{
					if(enemigo.y>100 && enemigo.y<200)
					{
						enemigo.y=100;
					}
				}
				if(enemigo.x>=470 && enemigo.x<=880)
				{
					if(enemigo.y>360 && enemigo.y<460)
					{
						enemigo.y=360;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x,enemigo.y+=10);
				policia(enemigo);
			}
			if(usuario.y<enemigo.y) //ENEMIGO HACIA ARRIBA
			{
				if(enemigo.y<105)
				{
					enemigo.y=107;
				}
				if((enemigo.x>=120 && enemigo.x<=430) || (enemigo.x>=470 && enemigo.x<=880) || (enemigo.x>=920 && enemigo.x<=1230))
					{
					if(enemigo.y<600 && enemigo.y>500)
					{
						enemigo.y=600;
					}
				}
				if(enemigo.x>=470 && enemigo.x<=880)
				{
					if(enemigo.y<350 && enemigo.y>245)
					{
						enemigo.y=350;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x,enemigo.y-=10);
				policia(enemigo);
			}
			if(usuario.x>enemigo2.x) //ENEMIGO 2 HACIA DERECHA
			{
				if(enemigo2.x>=1250)
				{
					enemigo2.x=1248;
				}
				if(enemigo2.y>=120 && enemigo2.y<=580)
				{
					if(enemigo2.x>105 && enemigo2.x<215)
					{
						enemigo2.x=105;
					}
					if(enemigo2.x>905 && enemigo2.x<1015)
					{
						enemigo2.x=905;
					}
				}
				if((enemigo2.y>=120 && enemigo2.y<=330) || (enemigo2.y>=370 && enemigo2.y<=580))
				{
					if(enemigo2.x>455 && enemigo2.x<565)
					{
						enemigo2.x=455;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x+=10,enemigo2.y);
				policia(enemigo2);
			}
			if(usuario.x<enemigo2.x) //ENEMIGO 2 HACIA IZQUIERDA
			{
				if(enemigo2.x<=100)
				{
					enemigo2.x=102;
				}
				if(enemigo2.y>=120 && enemigo2.y<=580)
				{
					if(enemigo2.x<445 && enemigo2.x>145)
					{
						enemigo2.x=445;
					}
					if(enemigo2.x<1245 && enemigo2.x>955)
					{
						enemigo2.x=1245;
					}
				}
				if((enemigo2.y>=120 && enemigo2.y<=330) || (enemigo2.y>=370 && enemigo2.y<=580))
				{
					if(enemigo2.x<895 && enemigo2.x>750)
					{
						enemigo2.x=895;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x-=10,enemigo2.y);
				policia(enemigo2);
			}
			if(((usuario.x-30>enemigo.x-30) && (usuario.x-30<enemigo.x+30)) || ((usuario.x+30>enemigo.x-30) && (usuario.x+30<enemigo.x+30)) || usuario.x==enemigo.x)
			{
				if(((usuario.y+30>enemigo.y-30) && (usuario.y+30<enemigo.y+30)) || usuario.y==enemigo.y)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x-5,vidas.y-5,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo);
						mensaje3();
						exit(1);
					}
				}
			}
			if(((usuario.y+30>enemigo2.y-30) && (usuario.y+30<enemigo2.y+30)) || ((usuario.y-30>enemigo2.y-30) && (usuario.y-30<enemigo2.y+30)) || usuario.y==enemigo2.y)
			{
				if(((usuario.x-30>enemigo2.x-30) && (usuario.x-30<enemigo2.x+30)) || usuario.x==enemigo2.x)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x-5,vidas.y-5,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo2);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo2);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);		
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo2);
						mensaje3();
						exit(1);
					}
				}
			}
			break;
		case 52: //PERSONAJE HACIA IZQUIERDA
			if(usuario.x<=100)
			{
				usuario.x=102;
			}
			if(usuario.y>=120 && usuario.y<=580)
			{
				if(usuario.x<445 && usuario.x>145)
				{
					usuario.x=445;
				}
				if(usuario.x<1245 && usuario.x>955)
				{
					usuario.x=1245;
				}
			}
			if((usuario.y>=120 && usuario.y<=330) || (usuario.y>=370 && usuario.y<=580))
			{
				if(usuario.x<895 && usuario.x>750)
				{
					usuario.x=895;
				}
			}
			personaje_clear(usuario);
			bills(usuario);
			moveto(usuario.x-=10,usuario.y);
			personaje(usuario);
			if(usuario.x>enemigo.x) //ENEMIGO HACIA DERECHA
			{
				if(enemigo.x>=1250)
				{
					enemigo.x=1248;
				}
				if(enemigo.y>=120 && enemigo.y<=580)
				{
					if(enemigo.x>105 && enemigo.x<215)
					{
						enemigo.x=105;
					}
					if(enemigo.x>905 && enemigo.x<1015)
					{
						enemigo.x=905;
					}
				}
				if((enemigo.y>=120 && enemigo.y<=330) || (enemigo.y>=370 && enemigo.y<=580))
				{
					if(enemigo.x>455 && enemigo.x<565)
					{
						enemigo.x=455;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x+=10,enemigo.y);
				policia(enemigo);
			}
			if(usuario.x<enemigo.x) //ENEMIGO HACIA IZQUIERDA
			{
				if(enemigo.x<=100)
				{
					enemigo.x=102;
				}
				if(enemigo.y>=120 && enemigo.y<=580)
				{
					if(enemigo.x<445 && enemigo.x>145)
					{
						enemigo.x=445;
					}
					if(enemigo.x<1245 && enemigo.x>955)
					{
						enemigo.x=1245;
					}
				}
				if((enemigo.y>=120 && enemigo.y<=330) || (enemigo.y>=370 && enemigo.y<=580))
				{
					if(enemigo.x<895 && enemigo.x>750)
					{
						enemigo.x=895;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x-=10,enemigo.y);
				policia(enemigo);
			}
			if(usuario.y>enemigo2.y) //ENEMIGO 2 HACIA ABAJO
			{
				if(enemigo2.y>605)
				{
					enemigo2.y=600;
				}
				if((enemigo2.x>=120 && enemigo2.x<=430) || (enemigo2.x>=470 && enemigo2.x<=880) || (enemigo2.x>=920 && enemigo2.x<=1230))
				{
					if(enemigo2.y>100 && enemigo2.y<200)
					{
						enemigo2.y=100;
					}
				}
				if(enemigo2.x>=470 && enemigo2.x<=880)
				{
					if(enemigo2.y>360 && enemigo2.y<460)
					{
						enemigo2.y=360;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x,enemigo2.y+=10);
				policia(enemigo2);
			}
			if(usuario.y<enemigo2.y) //ENEMIGO 2 HACIA ARRIBA
			{
				if(enemigo2.y<105)
				{
					enemigo2.y=107;
				}
				if((enemigo2.x>=120 && enemigo2.x<=430) || (enemigo2.x>=470 && enemigo2.x<=880) || (enemigo2.x>=920 && enemigo2.x<=1230))
					{
					if(enemigo2.y<600 && enemigo2.y>500)
					{
						enemigo2.y=600;
					}
				}
				if(enemigo2.x>=470 && enemigo2.x<=880)
				{
					if(enemigo2.y<350 && enemigo2.y>245)
					{
						enemigo2.y=350;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x,enemigo2.y-=10);
				policia(enemigo2);
			}
			if(((usuario.y+30>enemigo.y-30) && (usuario.y+30<enemigo.y+30)) || ((usuario.y-30>enemigo.y-30) && (usuario.y-30<enemigo.y+30)) || usuario.y==enemigo.y)
			{
				if(((usuario.x-30>enemigo.x-30) && (usuario.x-30<enemigo.x+30)) || usuario.x==enemigo.x)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x-5,vidas.y-5,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);		
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo);
						mensaje3();
						exit(1);
					}
				}
			}
			if(((usuario.x+30>enemigo2.x-30) && (usuario.x+30<enemigo2.x+30)) || ((usuario.x-30>enemigo2.x-30) && (usuario.x-30<enemigo2.x+30)) || usuario.x==enemigo2.x)
			{
				if(((usuario.y-30>enemigo2.y-30) && (usuario.y-30<enemigo2.y+30)) || usuario.y==enemigo2.y)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x,vidas.y,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo2);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						enemigo_clear(enemigo2);
						bills(usuario);
						mensaje3();
						exit(1);
					}
				}
			}
			break;
		case 54: //PERSONAJE HACIA DERECHA
			if(usuario.x>=1250)
			{
				usuario.x=1248;
			}
			if(usuario.y>=120 && usuario.y<=580)
			{
				if(usuario.x>105 && usuario.x<215)
				{
					usuario.x=105;
				}
				if(usuario.x>905 && usuario.x<1015)
				{
					usuario.x=905;
				}
			}
			if((usuario.y>=120 && usuario.y<=330) || (usuario.y>=370 && usuario.y<=580))
			{
				if(usuario.x>455 && usuario.x<565)
				{
					usuario.x=455;
				}
			}
			personaje_clear(usuario);
			bills(usuario);
			moveto(usuario.x+=10,usuario.y);
			personaje(usuario);
			if(usuario.x>enemigo.x) //ENEMIGO HACIA DERECHA
			{
				if(enemigo.x>=1250)
				{
					enemigo.x=1248;
				}
				if(enemigo.y>=120 && enemigo.y<=580)
				{
					if(enemigo.x>105 && enemigo.x<215)
					{
						enemigo.x=105;
					}
					if(enemigo.x>905 && enemigo.x<1015)
					{
						enemigo.x=905;
					}
				}
				if((enemigo.y>=120 && enemigo.y<=330) || (enemigo.y>=370 && enemigo.y<=580))
				{
					if(enemigo.x>455 && enemigo.x<565)
					{
						enemigo.x=455;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x+=10,enemigo.y);
				policia(enemigo);
			}
			if(usuario.x<enemigo.x) //ENEMIGO HACIA IZQUIERDA
			{
				if(enemigo.x<=100)
				{
					enemigo.x=102;
				}
				if(enemigo.y>=120 && enemigo.y<=580)
				{
					if(enemigo.x<445 && enemigo.x>145)
					{
						enemigo.x=445;
					}
					if(enemigo.x<1245 && enemigo.x>955)
					{
						enemigo.x=1245;
					}
				}
				if((enemigo.y>=120 && enemigo.y<=330) || (enemigo.y>=370 && enemigo.y<=580))
				{
					if(enemigo.x<895 && enemigo.x>750)
					{
						enemigo.x=895;
					}
				}
				enemigo_clear(enemigo);
				bills(usuario);
				moveto(enemigo.x-=10,enemigo.y);
				policia(enemigo);
			}
			if(usuario.y>enemigo2.y) //ENEMIGO HACIA ABAJO
			{
				if(enemigo2.y>605)
				{
					enemigo2.y=600;
				}
				if((enemigo2.x>=120 && enemigo2.x<=430) || (enemigo2.x>=470 && enemigo2.x<=880) || (enemigo2.x>=920 && enemigo2.x<=1230))
				{
					if(enemigo2.y>100 && enemigo2.y<200)
					{
						enemigo2.y=100;
					}
				}
				if(enemigo2.x>=470 && enemigo2.x<=880)
				{
					if(enemigo2.y>360 && enemigo2.y<460)
					{
						enemigo2.y=360;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x,enemigo2.y+=10);
				policia(enemigo2);
			}
			if(usuario.y<enemigo2.y) //ENEMIGO HACIA ARRIBA
			{
				if(enemigo2.y<105)
				{
					enemigo2.y=107;
				}
				if((enemigo2.x>=120 && enemigo2.x<=430) || (enemigo2.x>=470 && enemigo2.x<=880) || (enemigo2.x>=920 && enemigo2.x<=1230))
					{
					if(enemigo2.y<600 && enemigo2.y>500)
					{
						enemigo2.y=600;
					}
				}
				if(enemigo2.x>=470 && enemigo2.x<=880)
				{
					if(enemigo2.y<350 && enemigo2.y>245)
					{
						enemigo2.y=350;
					}
				}
				enemigo_clear(enemigo2);
				bills(usuario);
				moveto(enemigo2.x,enemigo2.y-=10);
				policia(enemigo2);
			}
			if(((usuario.y+30>enemigo.y-30) && (usuario.y+30<enemigo.y+30)) || ((usuario.y-30>enemigo.y-30) && (usuario.y-30<enemigo.y+30)) || usuario.y==enemigo.y)
			{
				if(((usuario.x+30>enemigo.x-30) && (usuario.x+30<enemigo.x+30)) || usuario.x==enemigo.x)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x-5,vidas.y-5,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo);
						mensaje3();
						exit(1);
					}
				}
			}
			if(((usuario.x+30>enemigo2.x-30) && (usuario.x+30<enemigo2.x+30)) || ((usuario.x-30>enemigo2.x-30) && (usuario.x-30<enemigo2.x+30)) || usuario.x==enemigo2.x)
			{
				if(((usuario.y-30>enemigo2.y-30) && (usuario.y-30<enemigo2.y+30)) || usuario.y==enemigo2.y)
				{
					cont--;
					sprintf(mensaje,"VIDAS RESTANTES: %d", cont);
					setcolor(0);
					rectangle(vidas.x,vidas.y,300,55);
					setfillstyle(1,0);
					floodfill(vidas.x+10,vidas.y+10,0);
					setcolor(15);
					settextstyle(2,0,7);
					outtextxy(vidas.x,vidas.y,mensaje);
					personaje_clear(usuario);
					policia(enemigo2);
					bills(usuario);
					if(cont!=0){
						usuario.x=675;
						usuario.y=600;
						personaje(usuario);
					}
					PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
					policia(enemigo);
					Sleep(1500);
					PlaySound("music2.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
					if(cont==0)
					{
						PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
						personaje_clear(usuario);
						bills(usuario);
						policia(enemigo2);
						mensaje3();
						exit(1);
					}
				}
			}
			break;
		default:
			Beep(400,200);
			break;
		}
	}while(tecla!=27);
	PlaySound("select.wav",NULL,SND_FILENAME|SND_ASYNC);
	Sleep(1000);
	PlaySound("gameover.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	mensaje2();
	Sleep(2000);
	exit(1);
}
