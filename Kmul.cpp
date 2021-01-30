// This file shows how the Karatsuba Multiplication Algorithm works
#include <iostream>
#include <sstream>
#include <math.h>

int Kmul(int x, int y){
    if (x < 10 || y < 10){
        return x*y;
    }
    else{
        // First convert the int to string 
        std::stringstream sx, sy;
        sx << x;
        sy << y;
        std:: string strx, stry;
        sx >> strx;
        sy >> stry;

        // Then extract length of each string 
        int lx = strx.length();
        int ly = stry.length();

        // Then separate each string into substrings
        std::string subx1 = strx.substr(0, lx/2); // a
        std::string subx2 = strx.substr(lx/2); // b
        std::string suby1 = stry.substr(0, ly/2); // c
        std::string suby2 = stry.substr(ly/2); // d

        // Transfer the substring back to int
        std::stringstream sx1, sx2, sy1, sy2;
        int a, b, c, d;
        sx1 << subx1;
        sx2 << subx2;
        sy1 << suby1;
        sy2 << suby2;

        sx1 >> a;
        sx2 >> b;
        sy1 >> c;
        sy2 >> d;

        // Recursively compute a*c
        int ac = Kmul(a,c);

        // Recursively compute a*b
        int ad = Kmul(a,d);

        // Recursively compute c*d
        int bc = Kmul(b,c);

        // Recursively compute b*d
        int bd = Kmul(b,d);

        // return the result
        return pow(10, (lx+ly+1)/2) * ac + pow(10, (lx+1)/2) * ad + pow(10, (ly+1)/2) * bc + bd;
    }  
}

int main(){
    // State your input
    std::cout << "Please enter your first variable: " << std::endl;
    int x;
    std::cin >> x;
    std::cout << "Please enter your second variable: " << std::endl;
    int y;
    std::cin >> y;

    // Run the Karatsuba Multiplication
    int Kresult = Kmul(x,y);

    // Print output and Verification
    std::cout << "The result from Karatsuba Multiplication is: " << Kresult << std::endl;
    int Vresult = x*y;
    std::cout << "The result from normal multiplication is: " << Vresult << std::endl;    

    return 0;
}
