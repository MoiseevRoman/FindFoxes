#include <iostream>

class PoleIgra
{
private:
    int i, j;
public:
    int var1 = 10;
    int var2 = 10;
    int var3 = 0;
    int var4[10][10];
    void obnu(){        //obnulenie igrovoi tablitsi
        for(i = 0; i<10;i++){
            for(j = 0; j<10; j++){
                var4[i][j]=0;
            }
        }
    }

    void table(){     //zpis lis
        j = 0;
        for(i = 0; i<10; i++){
            if(j==10){
                std::cout<<i-1;
            }
            std::cout<<"\n";
            for(j=0; j<10; j++){
                if((var1==i)&&(var2==j)){
                    if(var3 == -1){
                        std::cout<<9<<" ";
                        var4[i][j]=9;
                    }
                    else {
                        std::cout<<var3<<" ";
                        var4[i][j]=var3;
                    }
                }
                else std::cout<<var4[i][j]<<" ";}
        }
        std::cout<<9<<"\n";
        for(j=0; j<10;j++){
            std::cout<<j<<" ";
        }
        std::cout<<"\n\n";
        var3 = 0;
    }
    void koord(){ //vvod koordinat
        std::cin>>var1>>var2;
    }
};
int main()
{
    int pole[10][10];
    int i, k, z;
    int rya;
    int n;
    int m;
    int pov = 0;
    int j=0;
    int fox = 0;

    std::cout<<"9 in the table is fox\n\n";
    for(i=0;i<10;i++){
        for(j = 0; j<10;j++){
            pole[i][j]=0;
        }
    }
    PoleIgra objPoleigra;
    objPoleigra.obnu();
    objPoleigra.table();

    while(fox != 8){  //randomnoe raspolozhenie lis
        i = rand()%10;
        j= rand()%10;
        pole[i][j] +=1;
        fox++;
    }
    while(fox > 0){ //Igra
        std::cout<<"Write number of string and number of column[0-9]:";
        objPoleigra.koord();
        n = objPoleigra.var1;
        m = objPoleigra.var2;
        rya = objPoleigra.var3;
        pov = 0;
        if((pole[n][m] ==  -1)||(pole[n][m] == -2)){//proverka na povtorenie koordinat
            pov++;
        }
        if(pole[n][m]==0){
            for(k = 0; k<9; k++){//stroki
                if(pole[k][m] > 0){
                    rya+= pole[k][m];
                }
                if(pole[n][k] > 0){//stolbi
                    rya += pole[n][k];
                }
            }
            //diagonali
            z = m;
            for(k = n+1; k < 10; k++){
                z++;
                if(z < 10){
                    if(pole[k][z]> 0){
                        rya += pole[k][z];
                    }
                }
            }
            z= m;
            for(k = n-1; k >=0; k--){
                z++;
                if(z < 10){
                    if(pole[k][z]> 0){
                        rya += pole[k][z];
                    }
                }
            }
            z = m;
            for(k = n+1; k < 10; k++){
                 z--;
                if(z>=0){
                    if(pole[k][z]>0){
                        rya += pole[k][z];
                    }
                }
            }
            z= m;
            for(k = n-1; k >=0; k--){
                z--;
                if(z >=0){
                    if(pole[k][z]> 0){
                        rya += pole[k][z];
                    }
                }
            }
            pole[n][m]= -1;
            rya= rya - fox +8;
        }
        else if(pole[n][m] > 0){
            fox-=pole[n][m];
            rya = -1;
            pole[n][m]= -2;
        }
        if(fox!=0){
            objPoleigra.var3=rya;
            if(pov>0){
                std::cout<<"You have already searched here"<<std::endl;
            }
            else{
                system("cls");
                objPoleigra.table();
            }
        }
    }
    std::cout<<"\n\n\nPOBEDA"<<std::endl;
    return 0;
}
