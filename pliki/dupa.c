#include <lcd.h>
#include <reg515.h>

void opoznienie(int liczba)
{
	int licznik = 0;
    int i;
    for (i = 0; i < liczba; i++) {
		licznik++;
    }
}
int komutacje[3][8] = {{8,2,4,1,8,2,4,1},{9,10,6,5,9,10,6,5},{8,10,2,6,4,5,1,9}};
int typKomutacji = 0;
int licznikKomutacji = 0;

unsigned long int czasKomutacji = 2000;

int adres = 0;
int wartosc = 0;
	
void przerwanie(void) interrupt 5
{

		if (licznikKomutacji > 7)
			licznikKomutacji = 0;
		P1 = komutacje[typKomutacji][licznikKomutacji];
		licznikKomutacji++;

	TF2 = 0;
}

void main() {
    init();
	
	IEN0 = 160;
	T2CON = 17;
	
	CRCL = czasKomutacji;
	CRCH = czasKomutacji >> 8;
	
		
	while(1) {
		char sign = readkb();
		
		if (sign != '\0') {
			switch(sign)
			{
				case '1':            
				case '2':            
				case '3':            
				case '4':            
				case '5':            
				case '6':            
				case '7':            
				case '8':            
				case '9':    
				case '0':
					chartype(sign);
				
					wartosc = wartosc * 10;
					wartosc += sign - 48;
				
					adres++;
					break;
						
				case 'g':
					
					if (typKomutacji + 1 > 2)
					{
						typKomutacji = 0;
					}
					typKomutacji++;
					
					break;
							
				case 'l':
					
					break;
		
				case 'p':
					
					break;
							
				case 'd':
					
					break;
							
				case 'b':
					lcdcmd(0x01);
					adres = 0;
					wartosc = 0;
					break;
						
				case 'e':
					
					czasKomutacji = 0xFFFF - (1000000 / wartosc);
					CRCL = czasKomutacji;
					CRCH = czasKomutacji >> 8;
					
					wartosc = 0;
				
					lcdcmd(0x01);
				
					break;
			}
		opoznienie(20000);
		}
	}
}


