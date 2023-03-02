#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
int fibo(int fb);
int process13(int a, int &c13);
void processFile(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, int &event, int &k, string &mush_ghost, string &asclepius_pack, string &merlin_pack);
string getline2(string file_input);
void mushghost(string &mush_ghost, int &n2, string &mg_line2);
void asclepius(string &asclepius_pack, int &remedy, int &maidenkiss, int &phoenixdown);
void merlin(string &merlin_pack, int &HP, int &MaxHP);
int snt(int a);
void damageperevent(int &event, float &baseDamage, int &levelO, int &level, int &HP, int &damage, int &remedy, int &maidenkiss, int &phoenixdown, int &orglevel, int &MaxHP, int i, int &c6, int &c7, string &mush_ghost, string &line2, string &asclepius_pack, string &merlin_pack, int &rescue);
void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue);

#endif // __KNIGHT_H__