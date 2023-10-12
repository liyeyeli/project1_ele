#include"filelist.h"
int main()
{
	int x, y;
	init_lcd(0x00ffffff);
	
	////»­±³¾°Í¼
	//draw_pic(0, 0, "17.bmp");
	//draw_pic(225, 60, "18.bmp");
	//draw_pic(300, 280, "16.bmp");
	//draw_pic(300, 380, "15.bmp");
	//while (1)
	//{
	//	get_coordinate(&x, &y);
	//	if (x > 300 && x < 500 && y>280 && y < 340)
	//	{
	//		draw_pic(0, 0, "19.bmp");
	//		draw_pic(760, 0, "21.bmp");
	//	}
	//	if (x > 300 && x < 500 && y>380 && y < 444)
	//	{
	//		init_lcd(0x00000000);
	//		draw_pic(0, 15, "20.bmp");
	//		break;
	//	}
	//	if (x > 760 && x < 800 && y>0 && y < 25)
	//	{
	//		draw_pic(0, 0, "17.bmp");
	//		draw_pic(225, 60, "18.bmp");
	//		draw_pic(300, 280, "16.bmp");
	//		draw_pic(300, 380, "15.bmp");
	//	}
	//}
	
	//ShowBmp();
	//Click_changepic();
	Bmpfirst* B = BMPS();
	Link_Fignle_changepic(B,12);
	int ret = execl("/IOT/yeli/IntelSystem/main", "main", NULL);
	if (ret == -1)
	{
		perror("execl error");
		return -1;
	}
	//Link_Click_changepic(B, 13);
	
	close_lcd();
	return 0;
}