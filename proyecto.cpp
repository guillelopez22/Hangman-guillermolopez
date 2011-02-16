#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iomanip>
using namespace std;
int SizeofCharArray(char*);
void printHanged(int);
int main(int argv, char* argc[]){
	int const MAX=50;
	char secret[MAX];
	char letra[MAX];
	char word[MAX];
	char *String, *letter, *looking, *look;
	int size;
	int resp=3;
	
	
	int r=4;
	
	while(resp!=2){
		int adivinadas=0;
		int comparar=adivinadas;
		int intentos=6;
		bool win=false;
		cout << endl << endl << endl << setw(15) << "HANGMAN" << endl;
		cout << "1. Jugar" << endl;
		cout << "2. No Jugar" << endl;
		cin >> resp;
		if (resp==1)
			{
			cout << "--------------------HANGMAN--------------------" << endl;
			printHanged(6);
			cout << endl << endl << endl << endl << endl;
			cout << "Antes de empezar necesitamos sabes la palabra secreta :O!!!" << endl;
			cout << "Pero es un secreto shhhhhhhhh!!!" << endl << endl << endl << endl;
			cout << "ingrese la palabra secreta ;)" << endl << "AHORA: ";
			cin >> secret;
			String=secret;
			int const tam=SizeofCharArray(String)-1;
			char guessed[tam];
			for (int i = 0; i < tam; ++i)
			{
				guessed[i]='_';
			}
			cout << "MUY BIEN !!" << endl;
			while(r!=3 ){
					if (intentos==0)
					{
						cout << "PERDIOOOOOOO" << endl;
						break;
						
					}
					if (adivinadas==tam){
						cout << "GANADOOOOR" << endl;
						break;
					}
					if (win)
					{
						break;
					}
					cout << "TIENES " << intentos << " VIDAS!" << endl;	
					cout << "1. adivinar por letra" << endl;
					cout << "2. adivinar la palabra" << endl;
					cout << "3. Rendirse" << endl;
					cin >> r;

					switch(r){
						case 1:{
							cout << "ingrese la letra que quieres adivinar: " << endl;
							cin >> letra;
							letter=letra;
							size=SizeofCharArray(letter);
							
							while(size>2){
								cout << "no sea tramposo -.-, ingrese solo una letra" << endl;
								cout << "ahorita ingresela tramposo...:";
								cin >> letra;
								size=SizeofCharArray(letter);
							}
							letter=letra;
							
							
							for (int i = 0; i < sizeof(String); ++i)
							{
								if (String[i]==letter[0])
								{

									adivinadas++;
									
								}
							}
							looking=strchr(secret,letter[0]);
							while(looking!=NULL){
								guessed[looking-secret]=letter[0];
								looking=strchr(looking+1,letter[0]);
							}

							if (comparar==adivinadas)
							{
								intentos--;

							}
							
							
							cout << endl << endl;
							printHanged(intentos);
							
							for (int i = 0; i < tam; ++i)
							{
								cout << " " << guessed[i] << " ";
							}
							cout << endl << "TIENES " << adivinadas << " adivinadas" << endl;


							comparar=adivinadas;

							break;
						}
						case 2:{
								cout << "Bueno si crees que sabes la palabra pues ingresala: ";
								cin >> word;
								look=word;
								int cont=0;
								int s=SizeofCharArray(look);
								if (s>SizeofCharArray(String) || s<SizeofCharArray(String))
								{
									cout << "Lo siento, no es la palabra" << endl;
									intentos--;
								}else{
									for (int i = 0; i < SizeofCharArray(String); ++i)
									{
										if (look[i]==String[i])
										{
											cont++;
										}
									}
								}
								if (cont==SizeofCharArray(String))
								{
									for (int i = 0; i < SizeofCharArray(String); ++i)
									{
										cout << " " << String[i] << " ";
									}
									cout << endl << "Buen Trabajo!" << endl << "Ganaste" << endl;
									win=true;
								}
								
							cout << endl << endl;
							printHanged(intentos);



							break;
						}
						case 3:{
							cout << "Bueno queridisimo cobarde, se acaba de rendir."  << endl;
							printHanged(0);
							intentos=0;
							break;
						}
					}
				
			}

		}	
	}
	return 0;
}
int SizeofCharArray(char* phrase){
	int size=0;

	int value= phrase[size];

	while(value != 0){
		value = phrase[size];
		size++;
	}

	return size;
}
void printHanged(int State){
	if(State==0)
 {
  
  cout<<endl<<endl
   <<"   +----+     "<<endl
   <<"   |    |     "<<endl
   <<"   |    O     "<<endl
   <<"   |   /|\\   "<<endl
   <<"   |   / \\   "<<endl
   <<"   |PERDISTE! "<<endl
   <<"  ============"<<endl<<endl;
 }
 else if(State==1)
 {
  cout<<endl<<endl
   <<"   +----+  "<<endl
   <<"   |    |  "<<endl
   <<"   |    O  "<<endl
   <<"   |   /|\\ "<<endl
   <<"   |     \\ "<<endl
   <<"   |       "<<endl
   <<"  ============"<<endl<<endl;
 }
 else if(State==2)
 {
  cout<<endl<<endl
   <<"   +----+  "<<endl
   <<"   |    |  "<<endl
   <<"   |    O  "<<endl
   <<"   |   /|\\ "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"  ============="<<endl<<endl;
 }
 else if(State==3)
 {
  cout<<endl<<endl
   <<"   +----+  "<<endl
   <<"   |    |  "<<endl
   <<"   |    O  "<<endl
   <<"   |   /|  "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"  ============="<<endl<<endl;
 }
 else if(State==4)
 {
  cout<<endl<<endl
   <<"   +----+  "<<endl
   <<"   |    |  "<<endl
   <<"   |    O  "<<endl
   <<"   |    |  "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"  ============="<<endl<<endl;
 }
 else if(State==5)
 {
  cout<<endl<<endl
   <<"   +----+  "<<endl
   <<"   |    |  "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"  ============="<<endl<<endl;
 }else if (State==6)
 {
 cout<<endl<<endl
   <<"   +----+  "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"   |       "<<endl
   <<"  ============="<<endl<<endl;
 }
}