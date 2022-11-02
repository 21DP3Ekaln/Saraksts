#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

string vards[50];
string mobilais[50];
string email[50];
string addrese[50];
int counter = -1;

int validateContact(string tmpName){
    for(int i=0; i<=counter; i++){
        if( vards[i] == tmpName ){
            return 0;
        }
    }
    return 1;
}

void Pievienokont(){
    string tmpName = "";
    cout<<"Ievadi vardu : ";
    cin>>tmpName;
    if( validateContact(tmpName) == 1 ){
        counter++;
        vards[counter] = tmpName;
    }else{
        cout<<endl<<"Kontakts jau eksiste"<<endl;
        return;
    }
    cout<<"Ievadi mobila nummuru : ";
    cin>>mobilais[counter];
    cout<<"ievadi savu email : ";
    cin>>email[counter];
    cout<<"ievadi savu adresi : ";
    cin>>addrese[counter];
}
void print(int tmpCounter){
    if( vards[tmpCounter] == "" )
        return;
    if( counter > -1 ){
        cout<<"vards : "<<vards[tmpCounter]<<endl;
        cout<<"mobila num : "<<mobilais[tmpCounter]<<endl;
        cout<<"Emails : "<<email[tmpCounter]<<endl;
        cout<<"Addresse : "<<addrese[tmpCounter]<<endl<<endl;
        cout<<"Nospied jebko lai turpinatu"<<endl<<endl;
        getch();
    }
}
void printAll(){
    if( counter > -1 ){
        for(int i=0; i<=counter; i++){
            print(i);
        }
    }
}

void Atjaunokont( int tmpCounter ){
    string tmpName = "";
    cout<<"Ievadi vardu : ";
    cin>>tmpName;
    if( validateContact(tmpName) ){
        vards[tmpCounter] = tmpName;
    }else{
        cout<<endl<<"Kontakts ar sadu vardu jau eksiste"<<endl;
        return;
    }
    cout<<"ievadi mobila telefona nummuru : ";
    cin>>mobilais[tmpCounter];
    cout<<"ievadi email : ";
    cin>>email[tmpCounter];
    cout<<"ievadi adresi : ";
    cin>>addrese[tmpCounter];
}
void dzestkont(int tmpCounter){
    vards[tmpCounter] = "";
    mobilais[tmpCounter] = "";
    email[tmpCounter] = "";
    addrese[tmpCounter] = "";
}
int findCounter(){
    if( counter < 0 )
        return -1;

    string tmpName;
    cout<<"ievadi vardu";
    cin>>tmpName;
    for(int i=0; i<=counter; i++){
        if( vards[i] == tmpName ){
            return i;
        }
    }
    return 1;
}

int main(){

    char op;
    do{
        system("cls");
        cout<<"1. Pievieno Kontaktu"<<endl;
        cout<<"2. Visi Kontakti"<<endl;
        cout<<"3. Meklet kontaktu"<<endl;
        cout<<"4. Mainit kontaktu"<<endl;
        cout<<"5. Dzest kontaktu"<<endl;
        cout<<"6. Iziet"<<endl<<endl;
        cout<<"Izveleties opciju (1-6): ";
        cin>>op;

        switch(op){
            case '1':
            {
                Pievienokont();
                cout<<"Kontakts pievienots"<<endl;
                cout<<"Nospied jebko lai turpinatu";
                getch();
                break;
            }
            case '2':
            {
                printAll();
                break;
            }
            case '3':
            {
                int tmpCounter = findCounter();
                if( tmpCounter > -1 ){
                    print(tmpCounter);
                }
                break;
            }
            case '4':
            {
                int tmpCounter = findCounter();
                if( tmpCounter > -1 ){
                    Atjaunokont(tmpCounter);
                }
                break;
            }
            case '5':
            {
                int tmpCounter = findCounter();
                if( tmpCounter > -1 ){
                    dzestkont(tmpCounter);
                }
                break;
            }
            case '6':
            {
                continue;
                break;
            }
        }

    }while(op != '6');

    return 0;

}