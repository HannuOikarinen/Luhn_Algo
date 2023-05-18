#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Calculated check digit 10-(s mod10) where s is the sum of payload
int calulatedDigit(int number) {
    int num = 0;
    num=10-(number%10);
    return num;
}
//Sum operations
int sumDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    string card;
    cout << "Enter your card number here: ";
    getline(cin, card);
    vector<int> numbersArray;

    // Convert characters to integer
    for (char digit : card) {
        if (isdigit(digit)){
        int number = digit - '0';
        numbersArray.push_back(number);
      }
    }

    // Prepare payload by removing check digit and saving it as a variable
    int checkdigit = 0;
    if (!numbersArray.empty()) {
      checkdigit = numbersArray.back();
      numbersArray.pop_back();
    }

    // Double every second number of the payload
    for (int i = numbersArray.size() - 1; i >= 0; i -= 2) {
      numbersArray[i] *= 2;
      if (numbersArray[i] >= 10) {
        numbersArray[i] = sumDigits(numbersArray[i]);
      }
    }
    // Sum new numbers in payload
    int sum = 0;
    for (int number : numbersArray) {
      sum += sumDigits(number);
    }
    // Check if sum of payload equals checkdigit
    if(calulatedDigit(sum)==checkdigit){
      cout<<"Your card number is valid"<<endl;
    }
    else{
      cout<<"Card number is invalid"<<endl;
    }

    return 0;
}
