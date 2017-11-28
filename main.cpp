#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
std::vector<string> getVector(string fname);
string getRandom(std::vector<string> v,int size);
void drawText(int xpos,int ypos,char const* key,ALLEGRO_FONT *font);
void printText(std::string V,int pos_y,ALLEGRO_FONT *font);
void drawHangman(int screen_w,int screen_h,int n);
void printPressed(const char* pressed,int pos_x,int pos_y,ALLEGRO_FONT *font);
void printWelcome();
void printTriesLeft(); // ?
void printMessage(const char* message,int pos_x,int pos_y, ALLEGRO_FONT *font); // to announce the messages such as win / lose / wrong word.
void refreshScreen(const char* word,const char* pressed, const char* message, int wrong,int width,int height);
string strConcat(string s, string r,string t="",string y="");
char* charConcat(char*  one, const char*  two);
vector <ALLEGRO_BITMAP*> loadBitmaps();
string itos(int i);

int main(void)
{
	srand(time(NULL));	
	int width = 1280;
	int height = 720;
	//vector <ALLEGRO_BITMAP*> image = loadBitmaps();

	bool done = false;
	int pos_x = width / 2;
	int pos_y = height / 2;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	//ALLEGRO_FONT * font24 = al_load_font("Vera.ttf",24,0);
	//ALLEGRO_FONT * font36 = al_load_font("Vera.ttf",36,0);
	//ALLEGRO_FONT * font18 = al_load_font("Vera.ttf",18,0);

	ALLEGRO_BITMAP *image = al_load_bitmap("0.bmp");
	al_draw_bitmap(image,1280/2-30,720/2-270,0);

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//refreshScreen("Awesome","ABCDEF","4 guesses remaining.",4,width,height);

	string keyx;
	const char* z;

	string word;
	string fname = "RandomNames.txt";
	vector <string> v = getVector(fname);

	word = getRandom(v,v.size()); // CHOOSE WORD/PHRASE RANDOMLY FROM DICTIONARY.
	string copy = word;
	string message;
	string Phrase;
	for(int i=0; i!=word.length(); i++)
      Phrase += " ";
	string key;
	std::string pressed="";
	int wrong=0;
	while(!done)
	{
		if(wrong == 6){
			message = strConcat("You Lose! The word was: ",word);
			done=true;
			refreshScreen(Phrase.c_str(),pressed.c_str(),message.c_str(),wrong,width,height);
		}
		refreshScreen(Phrase.c_str(),pressed.c_str(),message.c_str(),wrong,width,height);
		if(Phrase == word){
			message= "You win!";
			done=true;
			refreshScreen(Phrase.c_str(),pressed.c_str(),message.c_str(),wrong,width,height);
		 }

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_A:
					keyx="A";
					break;
				case ALLEGRO_KEY_B:
					keyx="B";
					break;
				case ALLEGRO_KEY_C:
					keyx="C";
					break;
				case ALLEGRO_KEY_D:
					keyx="D";
					break;
				case ALLEGRO_KEY_E:
					keyx="E";
					break;
				case ALLEGRO_KEY_F:
					keyx="F";
					break;
				case ALLEGRO_KEY_G:
					keyx="G";
					break;
				case ALLEGRO_KEY_H:
					keyx="H";
					break;
				case ALLEGRO_KEY_I:
					keyx="I";
					break;
				case ALLEGRO_KEY_J:
					keyx="J";
					break;
				case ALLEGRO_KEY_K:
					keyx="K";
					break;
				case ALLEGRO_KEY_L:
					keyx="L";
					break;
				case ALLEGRO_KEY_M:
					keyx="M";
					break;
				case ALLEGRO_KEY_N:
					keyx="N";
					break;
				case ALLEGRO_KEY_O:
					keyx="O";
					break;
				case ALLEGRO_KEY_P:
					keyx="P";
					break;
				case ALLEGRO_KEY_Q:
					keyx="Q";
					break;
				case ALLEGRO_KEY_R:
					keyx="R";
					break;
				case ALLEGRO_KEY_S:
					keyx="S";
					break;
				case ALLEGRO_KEY_T:
					keyx="T";
					break;
				case ALLEGRO_KEY_U:
					keyx="U";
					break;
				case ALLEGRO_KEY_V:
					keyx="V";
					break;
				case ALLEGRO_KEY_W:
					keyx="W";
					break;
				case ALLEGRO_KEY_X:
					keyx="X";
					break;
				case ALLEGRO_KEY_Y:
					keyx="Y";
					break;
				case ALLEGRO_KEY_Z:
					keyx="Z";
					break;
				default:
					key="*";
					break;
			}
		refreshScreen(Phrase.c_str(),pressed.c_str(),message.c_str(),wrong,width,height);
		}
		if(copy.find(keyx) != -1){
				std::cout<<"Copy Find"<<Phrase<<" - "<<copy<<" : "<<keyx<<std::endl;
				pressed+=keyx;
				while(copy.find(keyx) != -1){
					std::cout<<"WHILE Find"<<Phrase<<" - "<<copy<<" : "<<keyx<<copy.find(keyx)<<keyx<<std::endl;
					Phrase.replace(copy.find(keyx), 1, keyx);
					copy.replace(copy.find(keyx), 1, " ");
				}
			}

		al_flip_display();
		if (pressed.find(keyx) == -1){
				message="That's wrong";
				pressed+=keyx;
				wrong++;
			}	
		if(ev.type == ALLEGRO_EVENT_KEY_UP)
		    {
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					{done = true;
					break;
				}
			}
			if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				break;
			
	}
	al_rest(5.0);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);	
}
void drawText(int xpos,int ypos,char const* key,ALLEGRO_FONT *font)
{
		al_draw_text(font,al_map_rgb(255,255,0), xpos , ypos , ALLEGRO_ALIGN_CENTRE , key);
}

void printText(std::string V,int pos_y,ALLEGRO_FONT *font)
{
	const char* keyz;
	int z = pos_y/2+200;
	int r = 0;
	int word_size = V.length()-1;
	int diff = 300/word_size;
	for (int i = 0; i <= word_size; i++)
	{
	al_draw_line(r+15*i,z,r+50+15*i,z,al_map_rgb(255,255,255),5);
	std::string sym(1, V[i]);
	keyz = sym.c_str();
	drawText(r+25+15*i,z-36,keyz,font);
	r=r+100;
	}
}

void printPressed(const char* pressed,int pos_x,int pos_y,ALLEGRO_FONT *font)
{
	al_draw_text(font,al_map_rgb(255,255,255),pos_x,pos_y,ALLEGRO_ALIGN_LEFT,"Letters Guessed so far: ");
	string x = string(pressed);
	const char* keyz;
	//pos_x+=350;
	int xr=pos_x+150;
	int yr = pos_y+50;
	for (int i = 0; i < x.size(); i++)
	{
		std::string sym(1, pressed[i]);
		keyz = sym.c_str();
		drawText(xr+15*i,yr,keyz,font);
		xr=xr+30;
	}
}

void drawHangman(int screen_w,int screen_h,int n)
{
	vector <ALLEGRO_BITMAP*> image = loadBitmaps();
	switch(n)
	{
		case(6):{
			al_draw_bitmap(image[6],screen_w/2-20,screen_h/2-150,0);break;}
		case(5):{
			al_draw_bitmap(image[5],screen_w/2-20,screen_h/2-150,0);break;}
		case(4):{
			al_draw_bitmap(image[4],screen_w/2-20,screen_h/2-150,0);break;}
		case(3):{
			al_draw_bitmap(image[3],screen_w/2-20,screen_h/2-150,0);break;}
		case(2):{
			al_draw_bitmap(image[2],screen_w/2-20,screen_h/2-150,0);break;}
		case(1):{
			al_draw_bitmap(image[1],screen_w/2-20,screen_h/2-150,0);break;}
		default:
			al_draw_bitmap(image[0],screen_w/2-20,screen_h/2-150,0);

}
}
void printMessage(const char* message,int pos_x,int pos_y, ALLEGRO_FONT *font)
{
	al_draw_text(font,al_map_rgb(255,255,255),pos_x,pos_y,0,message);
}

void refreshScreen(const char* word,const char* pressed, const char* message, int wrong,int width,int height)
{
	al_clear_to_color(al_map_rgb(131,131,131));
	ALLEGRO_FONT * font24 = al_load_font("XLines.ttf",24,0);
	ALLEGRO_FONT * font36 = al_load_font("XLines.ttf",36,0);
	ALLEGRO_FONT * font18 = al_load_font("XLines.ttf",18,0);
	int pos_x = width / 2;
	int pos_y = height / 2 ;
	printMessage("WELCOME TO HUNGRY MAN.",pos_x/2+30,50,font36);
	printMessage("FEED ME, MY LIFE DEPENDS ON YOU!",pos_x/2,100,font36);
	printMessage("Press Esc to Exit from the Screen!",pos_x/2+600,300,font18);
	printMessage(message,pos_x/2,height-100,font36);
	printText(word,pos_y+150,font36);
	printPressed(pressed,pos_x-350,pos_y+150,font36);
	drawHangman(width+400,height,wrong);
	al_flip_display();
}
string strConcat(string s, string r,string t,string y)
{
  string z=s;
  z.append(r);
  const char* abc = z.c_str();
  return abc;
}

char* charConcat(char* one, char* two)
{
	char result[100];
	strcpy(result,one);
	strcat(result,two);
	return result;
}

std::vector<string> getVector(string fname)
{
	std::vector<string> v;
	std::ifstream file(fname);
	std::string   line;
	while(std::getline(file, line))
    	v.push_back(line);
    return v;

}

string getRandom(std::vector<string> v,int size)
{
	int a = rand()%size;
	return v[a];
}


vector <ALLEGRO_BITMAP*> loadBitmaps()
{
	vector <ALLEGRO_BITMAP*> bmp;
	
	for (int i = 0; i < 10; ++i)
	{
		string a = itos(i);
		a.append(".bmp");
		bmp.push_back(al_load_bitmap(a.c_str()));
	}
	return bmp;
}

string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}