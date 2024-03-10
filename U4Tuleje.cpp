#include <iostream>
using namespace std;
int main (void){
	void hanoi(int n,int inic,int tmp,int final);
	int n;
	cout <<"Numero de discos: ";
	cin >> n;
	hanoi(n,1,2,3);
	return 0;
}
void hanoi(int n,int inic,int tmp,int final){
	if(n>0){
		hanoi(n-1,inic,final,tmp);
	cout << "Del poste" << inic << " al " << final <<"\n";
	hanoi(n-1,tmp,inic,final);
	}
}
