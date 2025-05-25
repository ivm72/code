#include <iostream>
#include <cstring>
using namespace std;

char data[20], divisor[20], temp[4], total[100];
int i, j, datalen, divlen, len, flag = 1;

void check();

int main() {
    cout << "Enter the total bit of data: ";    
    cin >> datalen;
    cout << "Enter the total bit of divisor: ";
    cin >> divlen;

    len = datalen + divlen - 1; 

    cout << "\nEnter the data: ";
    cin >> data;              
    cout << "Enter the divisor: ";
    cin >> divisor;

    for (i = 0; i < datalen; i++) {
        total[i] = data[i]; 
        temp[i] = data[i];         
    }  

    for (i = datalen; i < len; i++) {
        total[i] = '0';   
    }

    check();

    for (i = 0; i < divlen; i++) { 
        temp[i + datalen] = data[i];
    }

    cout << "\nTransmitted Code Word: " << temp << endl;  

    cout << "\nEnter the received code word: ";
    cin >> total; 

    check();    

    for (i = 0; i < divlen - 1; i++) {
        if (data[i] == '1') {
            flag = 0;
            break;
        }        
    }

    if (flag == 1)
        cout << "\nSuccessful! No Errors Found" << endl;
    else
        cout << "\nReceived Code Word Contains Errors..." << endl;  

    return 0;
}

void check() {
    for (j = 0; j < divlen; j++) {
        data[j] = total[j];
    }

    while (j <= len) {
        if (data[0] == '1') {
            for (i = 1; i < divlen; i++) {
                data[i] = (data[i] == divisor[i]) ? '0' : '1';
            }
        }

        for (i = 0; i < divlen - 1; i++) {
            data[i] = data[i + 1];
        }
        data[i] = total[j++];
    }
}  


