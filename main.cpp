#include <iostream>
#include <cmath>

using namespace std;

bool check_number(string str){
    bool inRange = true;
    bool findDigits = false;
    int countDot = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.') {
            countDot++;
            inRange = true;
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            findDigits = true;
            inRange = true;
        }
        else if(str[i] == '-'){
            if(i > 0){
                inRange = false;
                break;
            }
        }else{
            inRange = false;
        }
    }
    if(countDot > 1) inRange = false;
    return (inRange && findDigits);

}

int main() {
    string a, b;
    float floor_a, floor_b, fraction_a, fraction_b;
    cout << "Enter two real numbers: ";
    cin >> a >> b;

    float x, y;

    x = stod(a);
    y = stod(b);

    fraction_a = modf(x, &floor_a);
    fraction_b = modf(y, &floor_b);


    if(!check_number(a) || !check_number(b)){
        cout << "Incorrect input!\n";
    }else{
        if(floor_a > floor_b) cout << "More\n";
        else if(floor_a == floor_b){
            if(fraction_a > fraction_b) cout << "More\n";
            else if(fraction_b == fraction_a) cout << "Equal\n";
            else cout << "Less\n";
        }else cout << "Less\n";

    }

    return 0;
}
