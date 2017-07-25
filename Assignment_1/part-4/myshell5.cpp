#include <iostream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;
void display(vector<string> tokens);
int main(){
    while(true)
    {
        string myText;
        cout<<"Please enter a command : ";
        getline(cin,myText);
        if(myText=="exit")
        {
            break;
        }
        istringstream iss(myText);
        string token;
        vector<string> tokens;
        
        while (std::getline(iss, token, ' '))
      {
            tokens.push_back(token);
       }
       display(tokens);
    
    }
    return 0;
}
void display(vector<string> tokens)
{
    int flag_command=0,flag_file=0,flag_argument=0;
    for(int i=0;i<tokens.size();++i)
     {
         if(flag_argument==1)
         {
             cout<<"Argument:"<<tokens[i]<<endl;
             flag_argument=0;
             continue;
         }
         if(flag_file==1)
         {
             flag_file=0;
             cout<<"File:"<<tokens[i]<<endl;
             continue;
         }
         if(flag_command==1)
         {
             flag_command=0;
             cout<<"Command:"<<tokens[i]<<endl;
             continue;
         }
         if(i==0)
         {
             
             cout<<"Command:"<<tokens[i]<<endl;
             continue;
         }
         string temp=tokens[i];
         if(temp[0]=='-')
         {
             cout<<"options:"<<tokens[i]<<endl;
             flag_argument=1;
             continue;
         }
         if(tokens[i]=="<" or tokens[i]==">")
         {
             cout<<"File redirection:"<<tokens[i]<<endl;
             flag_file=1;
             continue;
         }
         if(tokens[i]=="|")
         {
             cout<<"pipe"<<endl;
             flag_command=true;
             continue;
         }
    }
}
