#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <algorithm>
#include <functional>
#include <cstring>
#include <vector>

using namespace std;

// struct compartor{
//    bool operator()()
// };
class user{
	public: 
		string userid,uid,gid,gecos,home_dir,shell;
	  	//string uid,gid;
} ;


bool compuFunc(pair<string,user> ob1,pair<string,user> ob2)
{
	return stoi(ob1.second.uid) < stoi(ob2.second.uid);
};
 

bool compuFunc1(pair<string,user> ob1,pair<string,user> ob2)
{
	return stoi(ob1.second.gid) < stoi(ob2.second.gid);
};
 
void write_to_file(FILE *fp,vector<pair<string,user> > sortedVector); 

int main()
{
    map<string,user> user_accounts;
    string s;
 
 	FILE *fp,*fp1;
	char c[5000];
	char *token;
	int cnt=0;
	string userid,uid,gid,gecos,home_dir,shell;
	//string uid,gid;


	fp=fopen("passwd","r");
	    	while(fgets(c,sizeof(c),fp) != NULL) {
        		token = strtok(c,":");
        		cnt=0;
        		while(token!=NULL){
        			if(strcmp(token,"*")==0){
        				token = strtok(NULL,":");
        				continue;
        			}
        			if(cnt==0)
        				userid=token;
        			else if(cnt==1)
        				uid=token;
        			else if(cnt==2)
						gid=token;
        			else if(cnt==3)
        				gecos=token;
        			else if(cnt==4)
        				home_dir=token;
        			else{
        				shell=token;
        			}
        			cnt++;
        			token = strtok(NULL,":");
        		}
        			user temp;
        			temp.userid=userid;
        			temp.uid=uid;
        			temp.gid=gid;
        			temp.gecos=gecos;
        			temp.home_dir=home_dir;
        			temp.shell=shell;
     	        	user_accounts[userid]=temp;
    		}

// Sorting
  vector<pair<string,user> > users(user_accounts.begin(),user_accounts.end());
  sort(users.begin(),users.end(),compuFunc);
  vector<pair<string,user> > users2(user_accounts.begin(),user_accounts.end());
  sort(users2.begin(),users2.end(),compuFunc1);

  fp=fopen("a3p2task2.txt","w+");
 		 fputs("Sorted based on uid:\n",fp);
         write_to_file(fp,users);
         fclose(fp);

         fp=fopen("a3p2task2.txt","a");
 		 fputs("Sorted based on gid:\n",fp);
 		 write_to_file(fp,users2);
         fclose(fp);
// Done sorting 
         

//Writing to binary file    		
         	cout<<"\n  Writting on file: a3p2task3.bin \n";
         	ofstream osfile("a3p2task3.bin",ios::binary|ios::app);
    		for(map<string,user>::iterator it=user_accounts.begin();it!=user_accounts.end();++it)
    		{
    			user *temp=new user;
    			temp=&it->second;
        		osfile.write((char *)temp,sizeof(user));
    	 	}
    	osfile.close();    
//Done writing

//Deleting contents of map
    	user_accounts.clear();
    	cout<<user_accounts.size()<<endl;
//Done Deleting

//Read into map from binary file
    	cout<<"\n  reading from file: a3p2task3.bin \n";
         	ifstream isfile("a3p2task3.bin",ios::binary|ios::in);
    		int size=sizeof(user);
  			while(isfile)
            {
    			user *temp=new user;
    			isfile.read((char *)temp,sizeof(user));
    			user_accounts[temp->userid]=*temp;
    			size+=sizeof(user);
				isfile.seekg(size);
		 	}
    	isfile.close();
    	fp=fopen("a3p2task4.txt","w+");
    	for(map<string,user>::iterator it=++user_accounts.begin();it!=user_accounts.end();++it)
    		{
    	        fputs("userid:",fp);
         	    fputs(it->second.userid.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("uid:",fp);
         	    fputs(it->second.uid.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("gid:",fp);
         	    fputs(it->second.gid.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("gecos:",fp);
         	    fputs(it->second.gecos.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("Home Directory:",fp);
         	    fputs(it->second.home_dir.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("Shell:",fp);
         	    fputs(it->second.shell.c_str(),fp);
         	    fputs("\n",fp);
    	  	}
    	  	fclose(fp);
 	
//Done Reading    	

   return 0;
}
void write_to_file(FILE *fp,vector<pair<string,user> > sortedVector)
{
 for(pair<string,user> tempi : sortedVector )
         {
         	    fputs("userid:",fp);
         	    fputs(tempi.second.userid.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("uid:",fp);
         	    fputs(tempi.second.uid.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("gid:",fp);
         	    fputs(tempi.second.gid.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("gecos:",fp);
         	    fputs(tempi.second.gecos.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("Home Directory:",fp);
         	    fputs(tempi.second.home_dir.c_str(),fp);
         	    fputs("\n",fp);
         	    fputs("Shell:",fp);
         	    fputs(tempi.second.shell.c_str(),fp);
         	    fputs("\n",fp);
         	 
         }
}
