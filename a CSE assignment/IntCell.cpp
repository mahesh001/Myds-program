#include "IntCell.h"

IntCell::IntCell(int initailvalue=0):storedValue(initailValue){
}

int IntCell::read(){
	return storedValue;
}

void IntCell::write(int x){
	storedValue=x;
}
