#include<iostream>
#include<string>

class Num {
private:
	int num = 0;
public:
	void setValue(int num) {
		this->num = num;
	}
	int getValue() {
		return num;
	}
};

extern "C" {
	Num obj;
	extern "C" __declspec(dllexport) int get_num() {
		return obj.getValue();
	}
	extern "C" __declspec(dllexport)void set_num(int n) {
		obj.setValue(n);
	}
}