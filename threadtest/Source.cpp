#include <thread>
#include "stdio.h"
#include <string.h>
#include <list>
#include <algorithm>
#include <dxlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "vegeclass.h"
#include "linecontrol.h"



//メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	ChangeWindowMode(TRUE);//ウィンドウモード
	SetGraphMode(640, 481, 16);
	//初期化と裏画面化
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;
	LineControl line;
	while (ProcessMessage()==0 && ClearDrawScreen()==0){
		line.main();
		ScreenFlip();
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)break;
	}
	DxLib_End();        // ＤＸライブラリ使用の終了処理

	return 0;        // ソフトの終了

}