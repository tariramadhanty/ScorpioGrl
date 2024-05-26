#include <iostream>
using namespace std;
int main ()
{
    system ("cls");
    int valpertama, valkedua, digit1,digit2, validasi1, validasi2 , checksum;
    string tipekartu;
    long long int nomorkartu, pembagi, pengelang;

    cout<<"Input Nomor Kartu: ";
    cin>>nomorkartu;
    pembagi=10;
    pengelang=100;
    validasi1 = 0;
    do
    {
        valpertama = (((nomorkartu % pengelang)/ pembagi)*2);
        if ((valpertama>=10) || (valpertama<0))
        {
            digit1= valpertama % 10;
            digit2= valpertama / 10;
            valpertama = digit1 + digit2;
        }
        validasi1 += valpertama;
        pembagi*= 100;
        pengelang*= 100;
    } while ((pengelang<=10000000000000000)||(pembagi<=1000000000000000));

    pengelang = 10;
    pembagi = 1;
    validasi2 = 0;
    do               
    {
        valkedua= ((nomorkartu % pengelang)/ pembagi); 
        validasi2+= valkedua;     
        pengelang*=100;                      
        pembagi*=100;
    } while ((pengelang<=1000000000000000)||(pembagi<=100000000000000));

    checksum = validasi1 + validasi2;
    if ((((nomorkartu%10000000000000000)/1000000000000000)==5)&&(checksum% 10== 0))    
    {
        tipekartu="MASTERCARD";
    }
    else if((((nomorkartu%10000000000000000)/1000000000000000)==4)&&(checksum% 10==0))
    {
        tipekartu="VISA";
    }
    else
    {
        tipekartu="tidak valid";
    }
    cout<<"Nomor Kartu Anda :"<< nomorkartu<<endl; 
    cout<<"Tipe Kartu Anda :"<< tipekartu <<endl;
    cout<<"Checksum: "<<checksum<<endl;

    return 0;
}
