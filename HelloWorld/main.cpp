#include <Windows.h>//헤더파일

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//실제 작업, 프로시저
HINSTANCE g_hInst;//글로벌 인스턴스 핸들
LPCSTR lpszClass = "HelloWorld";//롱 포인터 스트링 제로 클래스

int APIENTRY WinMain(HINSTANCE hInstance/*프로그램 인스턴스 핸들*/, HINSTANCE hPrevInstance/*이전 인스턴스 핸들, 없을 경우 NULL*/, LPSTR lpszCmdParam/*콘솔앱의 argv*/, int nCmdShow/*프로그램이 실행될 형태(모양)*/) {//윈도우 생성 함수
	HWND hWnd;//윈도우(창) 핸들
	MSG Message;//메시지(운영체제가 보내는)
	WNDCLASS WndClass;//윈도우 속성
	g_hInst = hInstance;//글로벌로 선언된 핸들에 본 인스턴스의 핸들을 저장
	/***/
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	//예약 영역, 특수한 경우 외에는 운영제가 내부적으로만 사용함. 프로그래머가 사용하지 않을 경우 0;
	/***/

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//브러쉬 백그라운드, 윈도우의 배경 색상을 지정한다

	/***/
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//커서와
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//아이콘의 핸들
	//직접 사용자 지정 할 수 있지만 일단 기본 형태
	/***/

	WndClass.hInstance = hInstance;//인스턴스 핸들
	WndClass.lpfnWndProc = WndProc;//실제 작업이 이루어지는 프로시저 함수 포인터
	WndClass.lpszClassName = lpszClass;//윈도우 클래스의 이름, 이 이름이 CreateWindow에서 이런 특성들을 참조하여 윈도우를 생성함
	WndClass.lpszMenuName = NULL;//메뉴 이름, 소스코드가 아니라 리소스 에디터에서 만들고 링커가 조합하는데 사용하지 않을 경우 NULL
	WndClass.style = CS_HREDRAW | CS_VREDRAW;//스타일, HREDRAW와 VREDRAW는 각각 수평, 수직 크기가 변동되면 윈도우를 다시 그린다는 매크로이다.
	RegisterClass(&WndClass);//윈도우 클래스를 등록하여 사용할 수 있게 해준다. 정확히 어디 등록한다는 건지..

	hWnd = CreateWindow(lpszClass, "HelloWorld", WS_VSCROLL | WS_HSCROLL | WS_SYSMENU | WS_MAXIMIZEBOX , 860, 340, 800, 500, NULL, (HMENU)NULL, hInstance, NULL);//클래스 이름, 타이틀 이름, 크기, 위치 등등 정보를 인자로 넘긴다. 아직 다 이해하지 못했다.
	ShowWindow(hWnd, nCmdShow);//창을 띄운다, 핸들과 형태를 지정하는데 형태는 nCmdShow를 그냥 넣어준다.

	while (GetMessage(&Message, 0, 0, 0)) {//메시지 루프
		//여기서 메시지를 받고 처리한다.
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	//프로시저 함수의 실 구현이다.
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}