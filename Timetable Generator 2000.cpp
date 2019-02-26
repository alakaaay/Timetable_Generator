#include<iostream>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<fstream>
using namespace std;

#define pb push_back
#define ff first
#define ss second

struct timetable{
    string crs,prof,rm;
} table[100][100];


bool t[100][100]={0},t_prof[100][100]={0},t_group[100][100]={0};

int c_sz=0,f_sz=0,r_sz=0,g_sz=0;

vector<int> hours[100];

vector<string> course[100],faculty[100];
string abbr[100];

pair<string, int > room[100],group[100];

int findprof(int tm,string cr){
    int i=rand()%f_sz;
    bool us[100]={0};
    for(int l=0;l<f_sz;l++){
        while(us[i]==1)i=rand()%f_sz;
        us[i]=1;
        bool is=0;
        if(t_prof[i][tm]==1)continue;

        for(int j=1;j<faculty[i].size();j++){
            if(faculty[i][j]==cr){
                is=1;
                break;
            }
        }

        if(is==1)return i;
    }
    return -1;
}

int findcourse(string s){
    for(int i=0;i<c_sz;i++){
        if(course[i][0]==s)return i;
    }
    return -1;
}

int main(){

    ifstream coursefile;
    coursefile.open("courses.txt");

    int d=0;
    char c;
    string s;
    while(coursefile>>c){
        if(c=='-'){
            course[d].pb(s);
            s.clear();
        }
        else if(c==','){
            course[d].pb(s);
            s.clear();
        }
        else if(c=='.'){
            course[d].pb(s);
            d++;
            s.clear();
        }
        else s.pb(c);
    }
    c_sz=d;
    coursefile.close();

    ifstream abbrfile;
    abbrfile.open("abb_hours.txt");

    int idcourse=0;
    while(abbrfile>>c){

        if(c=='-'){
            idcourse=findcourse(s);
            if(idcourse==-1){
                cout<<"The course "<<s<<" was no found!!! (The input file is wrong)";
                return 0;
            }
            abbrfile>>abbr[idcourse];
            s.clear();
            do{
                abbrfile>>c;
                if(c>'0' && c<'5')hours[idcourse].pb(c-48);
            }while(c>'0' && c<'5');
        }
        else s.pb(c);
    }
    abbrfile.close();



    ifstream facultyfile;
    facultyfile.open("faculty.txt");

    d=0;
    while(facultyfile>>c){
        if(c=='-' || c==','){
            faculty[d].pb(s);
            s.clear();
        }
        else if(c=='.'){
            faculty[d].pb(s);
            d++;
            s.clear();
        }
        else if(c!=' ')s.pb(c);
    }
    facultyfile.close();

    f_sz=d;


    ifstream roomfile;
    roomfile.open("rooms.txt");
    d=0;
    while(roomfile>>room[d].ff){
        roomfile>>room[d].ss;
        d++;
    }

    r_sz=d;
    roomfile.close();

    ifstream groupfile;
    groupfile.open("groups.txt");
    d=0;
    while(groupfile>>group[d].ff){
        groupfile>>group[d].ss;
        d++;
    }

    g_sz=d;
    groupfile.close();

    vector<int> req;

    srand(time(NULL));

    for(int i=0;i<g_sz;i++){
        for(int j=0;j<c_sz;j++){
            for(int l=1;l<course[j].size();l++){
                if(course[j][l]==group[i].ff){
                    req.pb(j);
                    break;
                }
            }
        }
        for(int j=0;j<req.size();j++){
            int idCRS=req[j];
            string curCRSname=course[idCRS][0];
            for(int l=0;l<hours[idCRS].size();l++){
                int r=(rand()%r_sz),tm=(rand()%40),stp=0;
                bool used[50][50]={0};
                int fcl;
                while(true){
                    if(used[r][tm]==1){
                            r=(rand()%r_sz),tm=(rand()%40);
                            continue;
                    }

                    used[r][tm]=1;
                    bool IsFound=1;
                    for(int k=0;k<hours[idCRS][l];k++){
                        if((tm%4)+hours[idCRS][l]>4 ||(hours[idCRS][l]==2 && tm%2!=0)){
                            IsFound=0;
                            break;
                        }

                        if(t[r][tm+k]==0 && room[r].ss>=group[i].ss && t_group[i][tm+k]==0){
                            fcl=findprof(tm+k, curCRSname);
                            if(fcl==-1){
                                IsFound=0;
                                break;
                            }
                        }
                        else {
                            IsFound=0;
                            break;
                        }
                    }

                    if(IsFound==1)break;

                    r=(rand()%r_sz),tm=(rand()%40);

                    stp++;
                    if(stp==1000000){
                        cout<<"Your input is wrong!!!";
                        return 0;
                    }
                }

                for(int k=0;k<hours[idCRS][l];k++){
                    t[r][tm+k]=1;
                    t_group[i][tm+k]=1;
                    t_prof[i][tm+k]=1;
                    table[i][tm+k].crs=abbr[idCRS];
                    table[i][tm+k].rm=room[r].ff;
                    table[i][tm+k].prof=faculty[fcl][0];
                }
            }
        }
        req.clear();
    }

    string week[]={" Monday"," Tuesday"," Wednesday"," Thursday"," Friday"};
    string duration[]={"09:00-09:50","10:00-10:50","11:00-11:50","12:00-12:50","14:00-14:50","15:00-15:50","16:00-16:50","17:00-17:50"};

    ofstream tableForAll;
    tableForAll.open("Timetable for All Groups.txt");

    for(int i=0;i<g_sz;i++){
        string grp=group[i].ff;
        bool check=0;
        tableForAll<<endl<<"Timetable for student of group "<<grp<<endl<<setw(12)<<" ";
        for(int j=0;j<5;j++){
            tableForAll<<setw(40)<<left<<week[j];
        }
        tableForAll<<endl;
        for(int j=0;j<8;j++){
            tableForAll<<duration[j]<<" ";
                for(int k=0;k<5;k++){
                    string s;
                    int tm=(k*8)+j;
                    s="| "+table[i][tm].crs+" | "+table[i][tm].rm+" | "+table[i][tm].prof;
                    if(table[i][tm].crs.empty()==1)s="|";
                    tableForAll<<setw(40)<<left<<s;
                }
                tableForAll<<endl;
            }
        tableForAll<<endl;
    }


    ofstream ti_table;
    ti_table.open("TimeTable.txt");
    string grp;
    cout<<"Please, enter the name of the groups to access their Timetable: "<<endl;
    do{

        cin>>grp;
        bool check=0;
        for(int i=0;i<g_sz;i++){
            if(group[i].ff==grp){
                check=1;
                ti_table<<endl<<"Timetable for student of group "<<grp<<endl<<setw(12)<<" ";
                for(int j=0;j<5;j++){
                    ti_table<<setw(40)<<left<<week[j];
                }
                ti_table<<endl;
                for(int j=0;j<8;j++){
                    ti_table<<duration[j]<<" ";
                    for(int k=0;k<5;k++){
                        string s;
                        int tm=(k*8)+j;
                        s="| "+table[i][tm].crs+" | "+table[i][tm].rm+" | "+table[i][tm].prof;
                        if(table[i][tm].crs.empty()==1)s="|";
                        ti_table<<setw(40)<<left<<s;
                    }
                    ti_table<<endl;
                }
                break;
            }
        }
        ti_table<<endl;
        if(check==0 && grp!="End")ti_table<<"404| The group "<<grp<<" is not found!"<<endl;
    }while(grp!="End");
    return 0;
}
