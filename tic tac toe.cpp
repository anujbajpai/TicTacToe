#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void draw(int x, int y, vector<vector<char> > &CC, int Mod){
    if(Mod)
        CC[x][y] = 'X';
    else
        CC[x][y] = 'O';
    cout<<endl<<endl;
    cout<<" "<<CC[0][0]<<" "<<"| "<<CC[0][1]<<" | "<<CC[0][2]<<" "<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"--- --- ---"<<endl;
    cout<<" "<<CC[1][0]<<" "<<"| "<<CC[1][1]<<" | "<<CC[1][2]<<" "<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"--- --- ---"<<endl;
    cout<<" "<<CC[2][0]<<" "<<"| "<<CC[2][1]<<" | "<<CC[2][2]<<" "<<endl;
    cout<<"   |   |   "<<endl;
    printf("\n\n\n");
}

void prepareImage(vector<char> &T, vector<vector<char> > &C){
    T.push_back('91');
    T.push_back('92');
    T.push_back('93');
    C.push_back(T);
    T.clear();
    T.push_back('94');
    T.push_back('95');
    T.push_back('96');
    C.push_back(T);
    T.clear();
    T.push_back('97');
    T.push_back('98');
    T.push_back('99');
    C.push_back(T);
    cout<<" "<<C[0][0]<<" "<<"| "<<C[0][1]<<" | "<<C[0][2]<<" "<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"--- --- ---"<<endl;
    cout<<" "<<C[1][0]<<" "<<"| "<<C[1][1]<<" | "<<C[1][2]<<" "<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"--- --- ---"<<endl;
    cout<<" "<<C[2][0]<<" "<<"| "<<C[2][1]<<" | "<<C[2][2]<<" "<<endl;
    cout<<"   |   |   "<<endl<<endl<<endl;
}

void playerDetail(vector<string> &name){
    printf("Enter Details OF Legends=>>xx\n\n");
    for(int i = 0; i < 2; i++){
        printf("%d. Traitor %d  => ", i+1, i+1);
        string S;
        getline(cin, S);
        name.push_back(S);
    }
}

int main(){
    int Chances = 0, second, First = rand() % 2;
    char enter;
    vector<string> name;
    vector<int> temp(3);
    vector<char> T;
    vector<vector<int> > A, B;
    vector<vector<char> > C;
    A.push_back(temp);
    A.push_back(temp);
    B.push_back(temp);
    B.push_back(temp);
    vector<bool> V(10, false);
    printf("          !!!!xxxxxxxxxxxBATTLE OF CROSSESxxxxxxxxxxxx!!!!\n\n\n");
    prepareImage(T, C);
    int flag = 0, C1 = 0, C2 = 0, C3 = 0, C4 = 0;
    playerDetail(name);
    printf("\n\n             Have Luck To Drew First Blood Of The Day ;)      \n");
    scanf("%c", &enter);
    if(First)
        second = 0;
    else
        second = 1;
    cout<<"xxxxx  "<<name[First]<<"=>  Got His Day To Get First Red  xxxxx"<<endl<<endl;
    while(Chances < 9){
        Chances++;
        int Mod = Chances % 2, x, y, input;
        cout<<name[Mod]<<" HAVE A KILL xxxxxxxxxx"<<endl<<endl;
        scanf("%d", &input);
        printf("\n\n\n\n\n\n\n\n\n");
        if(!V[input]){
            V[input] = true;
            if(!(input % 3)){
                y = 2;
                x = input / 3 - 1;
            }
            else{
                y = (input % 3) - 1;
                x = input / 3;
            }
            draw(x, y, C, Mod);
            if(Mod){
                A[0][x]++;
                A[1][y]++;
                if((x == 0 && y == 2 ) || ( x == 2 && y == 0 ) || ( x == 1 && y == 1))
                    C3++;
                if(x == y)
                    C1++;
                if((A[0][x] == 3) || (A[1][y] == 3) || (C1 == 3) || (C3 == 3)){
                    flag = 1;
                    break;
                }
            }
            else{
                B[0][x]++;
                B[1][y]++;
                if((x == 0 && y == 2 ) || ( x == 2 && y == 0 ) || ( x == 1 && y == 1))
                    C4++;
                if(x == y)
                    C2++;
                if((B[0][x] == 3) || (B[1][y] == 3) || (C2 == 3) || (C4 == 3) ){
                    flag = 2;
                    break;
                }
            }
        }
        else{
            Chances--;
            cout<<"Invalid Input"<<endl;
        }
    }
    if(flag == 1)
        cout<<name[First] << "  Upholds THE TRUE TRAITOR SOUL xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl<<endl;
    else if(flag == 2)
        cout<<name[second]<< "  Upholds THE TRUE TRAITOR SOUL xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl<<endl;
    else
        printf("No REAL TRAITOR");
    return 0;
}
