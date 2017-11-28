std::vector<string> getVector(string fname);
/*The function loads files data like list of names
into vector form*/

string getRandom(std::vector<string> v,int size);
/*The functions generate random number and stores into vector
*/
void drawText(int xpos,int ypos,char const* key,ALLEGRO_FONT *font);
/*The function create a text on the GUI of the game*/

void printText(std::string V,int pos_y,ALLEGRO_FONT *font);

/*The function creates specified number of white lined spaces according to the word size 
that is randomly generated according to the loaded word from file*/

void drawHangman(int screen_w,int screen_h,int n);
/*The function draws hangman using bitmaps that was loaded from loadBitmaps fucntion
it have cases which breaks images into 7 pieces on the screen and depending
on the letters u press, the fucntion behaves accordingly and makes images on the screen
*/

void printPressed(const char* pressed,int pos_x,int pos_y,ALLEGRO_FONT *font);
/*The function shows the letters that are drawn on the screen
using al_draw_text commandand.
*/

void printWelcome();
/*The function Prints the main name of the game that is Hangman*/

void printTriesLeft(); // ?
/*The function shows the attempts that are left for the hangman
to be hanged or die*/

void printMessage(const char* message,int pos_x,int pos_y, ALLEGRO_FONT *font); // to announce the messages such as win / lose / wrong word.
/*The function print or shows any message u want on the screen*/

void refreshScreen(const char* word,const char* pressed, const char* message, int wrong,int width,int height);
/*The function takes fucntions that are to be shown the screen such as Welcome screen
, how to exit from screen and the letters that are pressed and the hangman's tries left
*/

string strConcat(string s, string r,string t="",string y="");
/*The function concatenates/joins the two strings */

char* charConcat(char*  one, const char*  two);
/*The function concatenates the characters*/


vector <ALLEGRO_BITMAP*> loadBitmaps();
/*The function loads image into its vector components so that each bit of the image can be loaded into vector
It is easy to break the image like in hangman and then make it work piece by piece like hands and legs and head
*/
string itos(int i);
/*The function converts string type into integer type*/
