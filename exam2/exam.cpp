// Your code here!
#include <iostream>
#include "exam.h"
//#include "matrix.h"

using namespace exam;
//using namespace std;

/*#define ROWS 5
#define COLUMNS 5

int main() {
    Matrix m(ROWS, COLUMNS);

    for(int i=0; i<ROWS; i++) 
        for(int j=0; j<COLUMNS; j++) 
            m.set_coord(i,j,(i + j) % 10);

    m.display();

    flip_horiz(m).display();
}*/
/*int flip(Matrix &m){
return 420;
}*/
Matrix flip_horiz(Matrix &m){
int rows=m.get_num_rows();
int cols=m.get_num_columns();
Matrix output(rows,cols);
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			output.set_coord(i,j,m.get_coord(rows-1-i,j));
		}
	}
//m.display();
//output.display();
return output;
}
