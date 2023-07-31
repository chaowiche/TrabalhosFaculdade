#include <iostream>
//code used to determine which number is bigger.
using namespace std;
int main (){
    int n, c, maior;
    maior = 0;
    c = 5;
    
    do {
        cin >> n;
        if (n > maior){
            maior = n;
        }
        c--;
    } while (n > 0 && c != 0);
        
    cout << maior << endl;
    return 0;
}
