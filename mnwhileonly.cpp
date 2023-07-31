#include <iostream>
//code used to determine which number is bigger.

using namespace std;
int main (){
    int n, c, maior;
    maior = 0;
    c = 5;
    cin >> n;
    while (n > 0 && c != 0){
            cin >> n;
        if (n > maior){
            maior = n;
        }
            c--;
    }
    cout << maior << endl;
    return 0;
}
