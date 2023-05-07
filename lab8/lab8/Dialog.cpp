#include "Dialog.h"

//êîíñòðóêòîð
Dialog::Dialog(void) :Vector() {
	EndState = 0;
}
//äåñòðóêòîð 
Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
	string OpInt = "m+-szq"; //ñòðîêà ñîäåðæèò êîäû îïåðàöèé 
	string s;
	char code;
	cout << '>';
	cin >> s; code = s[0];//ïåðâûé ñèìâîë êîìàíäû 
	if (OpInt.find(code) >= 0) { //ÿâëÿåòñÿ ëè ñèìâîë êîäîì îïåðàöèè
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break;//ñîçäàòü ãðóïïó
		case '+': event.command = cmAdd; break;//äîáàâèòü îáúåêò â ãðóïïó 
		case '-': event.command = cmDel; break;//óäàëèòü îáúåêò èç ãðóïïû 
		case 's': event.command = cmShow; break;//ïðîñìîòð ãðóïïû 
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break; //êîíåö ðàáîòû
		}
	}
	else event.what = evNothing;//ïóñòîå ñîáûòèå 
}

void Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //ïîëó÷èòü ñîáûòèå 
		HandleEvent(event); //îáðàáîòàòü ñîáûòèå
	} while (Valid());
}

bool Dialog::Valid() {
	return EndState == 0;
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;//ïóñòîå ñîáûòèå 
}

void Dialog::EndExec() {
	EndState = 1;
}
//îáðàáîò÷èê ñîáûòèé
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake://ñîçäàíèå ãðóïïû 
			cout << "Enter size: ";
			cin >> size;
			beg = new Object * [size];//âûäåëÿåì ïàìÿòü ïîä ìàññèâ óêàçàòåëåé 
			cur = 0; //òåêóùàÿ ïîçèöèÿ
			ClearEvent(event);//î÷èùàåì ñîáûòèå 
			break;
		case cmAdd://äîáàâëåíèå 
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del(); //óäàëåíèå 
			ClearEvent(event);
			break;
		case cmShow:
			Show(); //ïðîñìîòð 
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec(); //âûõîä 
			ClearEvent(event);
			break;
		case cmGet:
			Get_Name();
			ClearEvent(event);
			break;
		};
	};
}