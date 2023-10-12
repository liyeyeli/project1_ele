#include"filelist.h"

//简易版本
//通过屏幕点击实现图片切换
int Click_changepic()
{
	int x, y;
	int i = 0;
	char* name = (char*)malloc(sizeof(name));
	while (1)
	{
		if (x > 750 && y < 30)
		{
			break;
		}
		i = i + 1;
		get_coordinate(&x, &y);
		if (x > 400)
		{
			sprintf(name, "%d.bmp", i);
			draw_pic(200, 40, name);
			get_coordinate(&x, &y);
			init_lcd(0x00ffffff);
			printf("x=%d y=%d", x, y);
			continue;
		}
		i = i - 2;
		sprintf(name, "%d.bmp", i);
		draw_pic(200, 40, name);
		get_coordinate(&x, &y);
		init_lcd(0x00ffffff);
		printf("x=%d y=%d", x, y);

	}
}
//使用双向循环链表实现图片切换
//创建一个带头节点的循环双向链表
Bmpfirst* BMPS()
{
	Bmpfirst* B = (Bmpfirst*)malloc(sizeof(*B));
	B->first = NULL;
	return B;
}
int Link_Click_changepic(Bmpfirst* B, int n)//n表示传入几张图片
{
	int x, y;
	BMP* bmp = (BMP*)malloc(sizeof(*bmp));
	bmp->name = (char*)malloc(sizeof(bmp->name));
	bmp->next = NULL;
	bmp->prev = NULL;
	B->first = bmp;
	int i = 5;
	//将名字存入双向循环链表中
	while (n >= i)
	{
		sprintf(bmp->name, "%d.bmp", i);
		if (i == n)
		{
			bmp->next = B->first;
			B->first->prev = bmp;
			break;
		}
		BMP* b = (BMP*)malloc(sizeof(*b));
		b->name = (char*)malloc(sizeof(b->name));
		b->next = NULL;
		b->prev = NULL;
		bmp->next = b;
		b->prev = bmp;
		bmp = b;
		i++;
	}
	bmp = bmp->next;
	//打印图片
	while (1)
	{
		get_coordinate(&x, &y);
		if (x > 750 && y < 20)
		{
			break;
		}
		if (x > 400)
		{
			draw_pic(100, 15, bmp->name);
			bmp = bmp->next;
		}
		else
		{
			draw_pic(100, 15, bmp->prev->name);
			bmp = bmp->prev;
		}
	}
	return 0;
}
//滑动实现图片切换
int Link_Fignle_changepic(Bmpfirst* B, int n)//n表示传入几张图片
{
	int x, y;
	int way;
	BMP* bmp = (BMP*)malloc(sizeof(*bmp));
	bmp->name = (char*)malloc(sizeof(bmp->name));
	bmp->next = NULL;
	bmp->prev = NULL;
	B->first = bmp;
	int i = 5;
	//将名字存入双向循环链表中
	while (n >= i)
	{
		sprintf(bmp->name, "%d.bmp", i);
		if (i == n)
		{
			bmp->next = B->first;
			B->first->prev = bmp;
			break;
		}
		BMP* b = (BMP*)malloc(sizeof(*b));
		b->name = (char*)malloc(sizeof(b->name));
		b->next = NULL;
		b->prev = NULL;
		bmp->next = b;
		b->prev = bmp;
		bmp = b;
		i++;
	}
	bmp = bmp->next;
	draw_pic(100, 15, bmp->name);
	//打印图片
	while (1)
	{
		way = get_fingle_move();
		if (way == RIGHT || way == DOWN)
		{
			bmp = bmp->next;
			draw_pic(100, 15, bmp->name);
		}
		else if(way == LEFT || way == UP)
		{
			bmp = bmp->prev;
			draw_pic(100, 15, bmp->prev->name);
		}
		else
		{
			draw_pic(0, 0, "23.bmp");
			while (1)
			{
				get_coordinate(&x, &y);
				if (x > 150 && x < 300 && y>300 && y < 400)
				{
					break;
				}
				if (x > 450 && x < 600 && y>300 && y < 400)
				{
					break;
				}
			}
			if (x > 150 && x < 300 && y>300 && y < 400)
			{
				break;
			}
			if (x > 450 && x < 600 && y>300 && y < 400)
			{
				init_lcd(0x00ffffff);
				draw_pic(100, 15, bmp->name);
				continue;
			}
		}
	}
	return 0;
}

//