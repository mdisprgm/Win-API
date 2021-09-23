#include <Windows.h>//�������

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//���� �۾�, ���ν���
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ� �ڵ�
LPCSTR lpszClass = "HelloWorld";//�� ������ ��Ʈ�� ���� Ŭ����

int APIENTRY WinMain(HINSTANCE hInstance/*���α׷� �ν��Ͻ� �ڵ�*/, HINSTANCE hPrevInstance/*���� �ν��Ͻ� �ڵ�, ���� ��� NULL*/, LPSTR lpszCmdParam/*�ܼ־��� argv*/, int nCmdShow/*���α׷��� ����� ����(���)*/) {//������ ���� �Լ�
	HWND hWnd;//������(â) �ڵ�
	MSG Message;//�޽���(�ü���� ������)
	WNDCLASS WndClass;//������ �Ӽ�
	g_hInst = hInstance;//�۷ι��� ����� �ڵ鿡 �� �ν��Ͻ��� �ڵ��� ����
	/***/
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	//���� ����, Ư���� ��� �ܿ��� ����� ���������θ� �����. ���α׷��Ӱ� ������� ���� ��� 0;
	/***/

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//�귯�� ��׶���, �������� ��� ������ �����Ѵ�

	/***/
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ����
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//�������� �ڵ�
	//���� ����� ���� �� �� ������ �ϴ� �⺻ ����
	/***/

	WndClass.hInstance = hInstance;//�ν��Ͻ� �ڵ�
	WndClass.lpfnWndProc = WndProc;//���� �۾��� �̷������ ���ν��� �Լ� ������
	WndClass.lpszClassName = lpszClass;//������ Ŭ������ �̸�, �� �̸��� CreateWindow���� �̷� Ư������ �����Ͽ� �����츦 ������
	WndClass.lpszMenuName = NULL;//�޴� �̸�, �ҽ��ڵ尡 �ƴ϶� ���ҽ� �����Ϳ��� ����� ��Ŀ�� �����ϴµ� ������� ���� ��� NULL
	WndClass.style = CS_HREDRAW | CS_VREDRAW;//��Ÿ��, HREDRAW�� VREDRAW�� ���� ����, ���� ũ�Ⱑ �����Ǹ� �����츦 �ٽ� �׸��ٴ� ��ũ���̴�.
	RegisterClass(&WndClass);//������ Ŭ������ ����Ͽ� ����� �� �ְ� ���ش�. ��Ȯ�� ��� ����Ѵٴ� ����..

	hWnd = CreateWindow(lpszClass, "HelloWorld", WS_VSCROLL | WS_HSCROLL | WS_SYSMENU | WS_MAXIMIZEBOX , 860, 340, 800, 500, NULL, (HMENU)NULL, hInstance, NULL);//Ŭ���� �̸�, Ÿ��Ʋ �̸�, ũ��, ��ġ ��� ������ ���ڷ� �ѱ��. ���� �� �������� ���ߴ�.
	ShowWindow(hWnd, nCmdShow);//â�� ����, �ڵ�� ���¸� �����ϴµ� ���´� nCmdShow�� �׳� �־��ش�.

	while (GetMessage(&Message, 0, 0, 0)) {//�޽��� ����
		//���⼭ �޽����� �ް� ó���Ѵ�.
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	//���ν��� �Լ��� �� �����̴�.
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}