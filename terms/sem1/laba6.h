/*int main() {
    // Variant 1 \\
    cout << "Enter symbols of 7 digits";
    double n;
    int i = 0;
    cin >> n;
    for (i; n>1.0; i++){
        n = n/52.7;
        cout<<cout.setf(ios::fixed, ios:: floatfield)<<setprecision(3)<<n<<endl;
    }
    cout << i << endl;

}*/
/*int main(){

    double fact = 1;
    double fact_prev = 1;


    for (int i = 1; fact>=fact_prev; i++){
        fact *= i;
        fact_prev = fact - fact*(i-1);
        cout<<i<<" "<<fact<<endl;
    }
}*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;


/*int main()
{   double x;
    cin >> x;
    int i;
    double mod;
    double result = 0;
    if (x>0 && x<1) {
        for (i = 0; x > 0; i++) {

            mod = x / 2.0;
            x = (x - mod) / 2;
            result += mod * pow((double) 10, i);
        }
        cout << result << endl;
    }*/
/*
    double res=0, cur, n;
    cin >> n;
    cur = n;
    if (n > 0 && n < 1) {
        for (int i = 1; i < 23; i++) {
            cur = cur * 2;
            if (cur > 1) {
                cur=cur-1;
                res += 1 * pow(0.1, i);
            }



        cout<<cout.setf(ios::fixed, ios:: floatfield)<<setprecision(21)<<res<<endl;
        }
}
*/

int main() {
    char a[1000000][1000000];
    for (int i = 0; i<1000000; i++){
        for (int j = 0; j<1000000; j++){
            cin>>a[i][j];
        }
    }
    for (int i = 0; i<1000000; i++){
        for (int j = 0; j<1000000; j++){
            if (a[i][j] > '0' || a[i][j] < '9' )

        }
    }

}


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a = 0;
    float n;
    cout << "Enter variable n = ";
    cin >> n;
    if (n > 0) {
        int i = 1;
        /*
           for ( i = 1; n >= a; i++) {
               a += 1.0 / i;
           }
           cout.setf(ios::fixed, ios::floatfield);
           cout << std::setprecision(3) << a << endl;
           cout<< i - 1;*/

        do {
            a +=1.0/i;
            i++;

        }while (n>=a);
        cout.setf(ios::fixed, ios::floatfield);
        cout << std::setprecision(3) << a << endl;
        cout<< i - 1;

    }
    else cout << "Enter variable n > 0" << endl;
}
