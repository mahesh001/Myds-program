#ifndef IntCell_H
#define IntCell_H

class IntCell{
	public:
		explicit IntCell(int initialvalue=0);
		void write(int x);
		int read();
		
	private:
		int storedValue;
	
};
