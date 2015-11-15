#include<iostream>
#include<vector>
using namespace std;

int no_of_moves=1000;
vector <string> move_list_shortest;

void clean_cells(int posr, int posc, vector <string> board, vector<string> move_list);
bool check_if_all_cleaned(vector<string> board);


void next_move(int posr, int posc, vector <string> board) {
    //add logic here
	cout<<"Row of bot:"<<posr<<"\nColumn of bot:"<<posc<<endl;
	cout<<"Board before cleaning:"<<endl;
	for(int j=0;j<board.size();j++){
		string s=board[j];
		for(int i=0;i<s.length();i++){
			cout<<s.at(i);
	
		}
		cout<<endl;
	}
	vector<string> move_list;
	clean_cells(posr,posc, board, move_list);
	cout<<"Minimum number of moves:"<<no_of_moves;
	cout<<"Best route:"<<endl;
	for(int i=0;i<move_list_shortest.size();i++){
		cout<<move_list_shortest[i]<<'\t';
	}

}

void clean_cells(int posr, int posc, vector <string> board, vector<string> move_list){
	//cout<<"Posr:"<<posr<<"Posc:"<<posc;

	
	
	for(int row=0;row<board.size();row++){
		string s=board[row];
		
		for(int col=0;col<s.length();col++){
			if(posr==row && posc==col){
				if(s.at(col)=='d'){
					move_list.push_back("CLEAN");
				//	cout<<"Cleaning/checking:row:"<<row<<";column:"<<col<<endl;
					board[row].replace(col,1,"-");
				}
			
			}
		
		}
		
		
	}
	if(move_list.size()>30)
		return;
	if(check_if_all_cleaned(board)){
		if(move_list.size()<no_of_moves){
			move_list_shortest=move_list;
			no_of_moves=move_list.size();
			cout<<"Better route found with "<<no_of_moves<<" moves"<<endl;		
		}
		cout<<"All cleaned here!"<<endl;
		
// Dumping board
	for(int j=0;j<board.size();j++){
		string s=board[j];
		for(int i=0;i<s.length();i++){
			cout<<s.at(i);
	
		}
		cout<<endl;
	}

//

		return;
	}

	if(posc<4){
		move_list.push_back("RIGHT");
		clean_cells(posr,posc+1,board,move_list);
		move_list.pop_back();

	}
	if(posc>0){	
		move_list.push_back("LEFT");
		clean_cells(posr,posc-1,board,move_list);
		move_list.pop_back();
	}	
	if(posr>0){
		move_list.push_back("UP");
		clean_cells(posr-1,posc,board,move_list);
		move_list.pop_back();

	}
	if(posr<4){
		move_list.push_back("DOWN");
		clean_cells(posr+1,posc,board,move_list);
		move_list.pop_back();
	}
}

bool check_if_all_cleaned(vector<string> board){
	for (int row=0;row<board.size();row++){
		string r=board[row];
		for(int col=0;col<r.length();col++){
			if(r.at(col) == 'd')
				return false;
		}
	}
//	for(int j=0;j<board.size();j++){
//		string s=board[j];
//		for(int i=0;i<s.length();i++){
//			cout<<s.at(i);
//	
//		}
//		cout<<endl;
//	}
	return true;
}


int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
