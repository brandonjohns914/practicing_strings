//
//  main.cpp
//  lab4
//
//  Created by Brandon Johns on 2/28/18.
//  Copyright © 2018 Brandon Johns. All rights reserved.
//

#include <iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;


void exercise1();
void exercise2();
void exercise1()
{
    char sentence[1000];
    char string[100][100];
    int i=0;
    int j,k,s;
    char last;
    cout<<"Press enter then '!!' to stop writting. "<<endl << ": ";
    
    
    while(cin.getline(string[i],100))
    {
        if(string[i][0]=='!' &&string[i][1]=='!')
        {
            break;
        }
        
        i++;
        
    }
    
    s=0;
    last='.';
    
    for(j=0;j<i;j++)
    {
        
        for(k=0;string[j][k]!='\0'; k++)
        {
            
            if(string[j][k] == ' ' && last == ' ')
            {
                continue;
            }
            if(last == '.')
            {
                sentence[s++]=toupper(string[j][k]);
            }
            
            else
            {
                sentence[s++] = tolower(string[j][k]);
            }
            last = sentence[s-1];
        }
    }
    sentence[s]='\0';
    cout<<"OUTPUT : \n"<<endl;
    cout<<sentence<<endl;
    

}

void exercise2()
{
    char answer = 'y';
    string String1,string2;
    do{
        cout << "Enter sentence: ";
        getline(cin,String1);
      
        
        int length = String1.length();
        
        
        for(int j=0;j<length;j++)
        {
        String1[j]=tolower(String1[j]);
        }
        
        
        if(length <= 3 && length >0)
        {
            cout << "Length <= 3,unable to convert -> may be grammatically incorrect !" << endl;
            for(int k=0;k<length;k++)
            {
                string2 += String1[k];
            }
        };
        for(int i=0; i<length && length>3;i++)
            if((String1[i]=='h') && (String1[i+1]!='\n' && String1[i+2]!='\n'))
            {
                string2 += "h";
                if(i==0)
                {
                    string test = String1.substr(i,4);
                    
                    if((test[1]=='i'&&test[2]=='m')||(test[1]=='e'&&test[2]=='r'))
                    {
                        if(test[3]==' ')
                        {
                            string2 += "im or her";
                            i+=2;
                        }
                    }
                }
                else
                {
                    string test = String1.substr(i-1,5);
                    if((test[2]=='i'&&test[3]=='m')||(test[2]=='e'&&test[3]=='r'))
                    {
                        if(test[0]==' ' && test[0]==' ')
                        {
                            string2 += "im or her";
                            i+=2;
                        }
                    }
                };
            }
            else
            {
            string2 += String1[i];
            }
        
        cout << string2 << endl;
        cout << "Again (Y/N) ?";
        cin >> answer;
    }
    while(answer=='y'|| answer=='Y');
}

    int main()
    {
        
        
       exercise1();
        exercise2();
        
        
        
        
        
        return 0;
    }
