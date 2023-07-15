    #include <iostream>
#include <string>

using namespace std;
enum gender {
    male, female
};
struct Lecturer {
    string name;
    gender pol;
    int kaf;
    string *lessons;
};

int main() {
    cout << "THIS IS A TEST PROPGRAM\n";
    cout << "Enter number of lecturer" << endl;
    int n;
    cin >> n;
    int *num;
    num = new int[n];
    Lecturer *data;
    data = new Lecturer[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter name #" + to_string(i + 1)  << endl;
        getline(cin, data[i].name);
        cout << "Enter kaf #" + to_string(i + 1) << endl;
        cin >> data[i].kaf;
        int l;
        cout << "Enter gender (0 - is male, 1 -is  female) #" + to_string(i + 1) << endl;
        cin >> l;
        data[i].pol = gender(l);
        cout << "Cicle to enter disciplines \n" << endl;
        cout << "Enter number of disciplines for lecturer #"+ to_string(i + 1)  << endl;
        int m;
        cin>>m;
        cin.ignore();
        num[i] = m;
        data[i].lessons = new string[m];
        for (int j = 0; j < num[i]; j++) {

            cout << "Enter discipline #" + to_string(j + 1)<<endl;
            getline(cin, data[i].lessons[j]);
        }
        cout<<'\n';

    }
    cout<<'\n';
    int tmp;
    cout<<"Enter number of kaf"<<endl;
    cin>>tmp;
    cout<<'\n';
    for (int i = 0; i < n; i++) {
        if (tmp == data[i].kaf){
            cout << "Lecturer is "<<data[i].name << endl;
            cout<< "Kaf is "<<data[i].kaf <<endl;
            for (int j = 0; j < num[i]; j++) {
                cout << "Lesson # "+ to_string(j)+" of lecture #"+ to_string(i)
                        + " is "<<data[i].lessons[j]<<endl;
            }
            cout<<'\n';
        }
    }
    cout<<"Press any key to exit"<<endl;
    system("pause");

    delete [] data;
    delete [] num;
    return 0;
}