#include <iostream>
#include <string>

using namespace std;

bool check_number(string str){
    bool check;
    bool inRange = true;
    bool findDigits = false;
    int countDot = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] < '-' || str[i] > '9' || str[i] == '/' ||
           (str[i] == '-' && i > 0)){
            inRange = false;
            break;
        }else if(str[i] == '.') countDot++;
        else if(str[i] >= '0' && str[i] <= '9'){
            findDigits = true;
        }
    }

    if(countDot > 1) inRange = false;

    (inRange && findDigits) ? check = true : check = false;
    return check;

}

int floor(string str){
    int floor = 0;
    int multiplier = 1;
    int leftBorder;
    bool findDot = false;

    (str[0] == '-') ? leftBorder = 1 : leftBorder = 0;

    for(int i = str.length() - 1; i >= leftBorder; i--){

        if(str[i] == '.') {
            findDot = true;
            floor = 0;
            multiplier = 1;
            i--;
        }
        floor += (str[i] - '0') * multiplier;
        multiplier *= 10;
    }

    if (str[0] == '-') floor = -floor;

    return floor;
}

int fraction(string str){
    int fraction = 0;
    int multiplier = 1;
    bool findDot = false;

    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] == '.') {
            findDot = true;
            break;
        }
        fraction += (str[i] - '0') * multiplier;
        multiplier *= 10;
    }
    if(!findDot) fraction = 0;
    return fraction;
}

int main() {
    string a, b;
    int floor_a, floor_b, fraction_a, fraction_b;
    cout << "Enter two real numbers: ";
    cin >> a >> b;

    if(!check_number(a) || !check_number(b)){
        cout << "Incorrect input!\n";
    }else{
        floor_a = floor(a);
        fraction_a = fraction(a);
        floor_b = floor(b);
        fraction_b = fraction(b);
        if(floor_a > floor_b) cout << "More\n";
        else if(floor_a == floor_b){
            if(fraction_a > fraction_b) cout << "More\n";
            else if(fraction_b == fraction_a) cout << "Equal\n";
            else cout << "Less\n";
        }else cout << "Less\n";

    }

    return 0;
}
