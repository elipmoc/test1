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



//���C���֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	SetGraphMode(640, 481, 16);
	//�������Ɨ���ʉ�
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;
	LineControl line;
	while (ProcessMessage()==0 && ClearDrawScreen()==0){
		line.main();
		ScreenFlip();
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)break;
	}
	DxLib_End();        // �c�w���C�u�����g�p�̏I������

	return 0;        // �\�t�g�̏I��

}