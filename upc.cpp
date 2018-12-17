#include <iostream>
#include <cstdlib>

int cdOddSum(long long *upc){
    //steps 1 n 2
    int i, sum =0;   long long upcd = *upc;
    std::lldiv_t digits;
    while (upcd >0){
        if (i % 2 == 0){
            digits = std::lldiv(upcd,10);
            sum += digits.rem;
            upcd = digits.quot;
        } else {
            digits = std::lldiv(upcd,10);
            upcd = digits.quot;
        }
        i++;
    }
    return (sum*3);
}

int cdEvenSum(long long *upc){
      //step 3
    int i=0;
    long long upcd = *upc; int step1 = cdOddSum(upc);
    int sum = 0;
    std::lldiv_t digits;
    while (upcd !=0){
        if (i % 2 != 0){
            digits = std::lldiv(upcd,10);
            sum += digits.rem;
            upcd = digits.quot;
        } else {
            digits = std::lldiv(upcd,10);
            upcd = digits.quot;
        }
        i++;
    }
    return (sum+step1);
}

int calccheckdigit(long long *upc){
    //steps 4 n 5
    int M = cdEvenSum(upc) % 10;
    std::cout << "M: " << M << std::endl;
    if (M == 0 )
        return M;
    else
        return 10-M;
}

int main(){
    long long upc;
    std::cout << "enter UPC : ";
    std::cin >> upc;

    int checkdigit = calccheckdigit(&upc);
    std::cout << "The check digit is => " << checkdigit << std::endl;

    return 0;
}
/*results
enter UPC : 12345678910
M: 6
The check digit is => 4
enter UPC : 04210000526
M: 6
The check digit is => 4
enter UPC : 1234567
M: 0
The check digit is => 0
*/