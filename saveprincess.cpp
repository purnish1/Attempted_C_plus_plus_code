#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    	int bot[2];
	int princess[2];
    	for(int i=0;i<grid.size();i++){
		string s=grid[i];
		for(int j=0;j<s.length();j++){
			if(s.at(j) == 'm'){
				//cout<<"Bot is at:"<<i<<','<<j<<endl;
				bot[0]=j;
				bot[1]=i;
			}
			if(s.at(j) == 'p'){
				//cout<<"Princess is at :"<<i<<","<<j<<endl;
				princess[0]=j;
				princess[1]=i;			
			}
		}
	}
	while(!(bot[0]==princess[0] && bot[1] == princess[1])){
		if(bot[0]<princess[0]){
			cout<<"RIGHT"<<endl;
			bot[0]++;
		}
		else if (bot[0]>princess[0]){
			cout<<"LEFT"<<endl;
			bot[0]--;
		}
		if(bot[1]<princess[1]){
			cout<<"DOWN"<<endl;
			bot[1]++;
		}
		else if(bot[1]>princess[1]){
			cout<<"UP"<<endl;
			bot[1]--;		
		}
	}

}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
