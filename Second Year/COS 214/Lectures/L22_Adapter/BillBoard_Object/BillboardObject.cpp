#include <iostream>

using namespace std;


// Adaptee
class ElectronicBillboard {
    public:
        ElectronicBillboard(string msg = "no message", int s = 0) : message(msg), state(s) {};
        void onof() { if (state == 0) state = 1; else state = 0;};
        void updateBoard() { if (state == 1) cout << message << endl; };
        void updateMessage(string msg) { message = msg; }; 
        bool ison() {return state == 1; };
    private:
        string message;
        int    state;
};

// Target
class Billboard {
public:
	virtual void changeState() = 0;
	virtual void changeMessage(int) = 0;
	virtual void displayMessage() = 0;
};


// Adapter
class TrafficBillboard : public Billboard {
    public:
        TrafficBillboard() { board = new ElectronicBillboard("all clear"); };
        virtual void changeState() { board->onof(); };
        virtual void changeMessage(int msgId) { switch (msgId) { 
					case 1: board->updateMessage("slow traffic ahead"); break;
					case 2: board->updateMessage("accident ahead"); break; 
					default: board->updateMessage("all clear"); } };
        virtual void displayMessage() { 
					if (board->ison()) {cout << "Traffic warning: "; board->updateBoard(); cout<<endl;} 
					else cout<<"Board is off"<<endl; };
    private:
        ElectronicBillboard* board;
};

int main() {
    TrafficBillboard tb;
    tb.displayMessage();
    tb.changeState();
    tb.displayMessage();
    tb.changeMessage(2);
    tb.displayMessage();
    tb.changeMessage(1);
    tb.displayMessage();
    tb.changeState();
    tb.displayMessage();
     
    return 0;
}
