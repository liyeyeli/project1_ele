#ifndef __FILELIST_H__
#define __FILELIST_H__
#include"touch.h"

typedef struct circle_bmp
{
	char* name;
	struct circle_bmp* prev;
	struct circle_bmp* next;

}BMP;
typedef struct bmp_first
{
	struct circle_bmp* first;
}Bmpfirst;
int Click_changepic();
Bmpfirst* BMPS();
int Link_Click_changepic(Bmpfirst* B, int n);//n表示传入几张图片
int Link_Fignle_changepic(Bmpfirst* B, int n);


#endif 

