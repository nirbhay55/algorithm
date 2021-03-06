#include <iostream>
using namespace std;

bool rat_path(char a[][1001],int b[][1001],int row,int col,int er,int ec){
	if (row==er and col==ec){
		b[er][ec] = 1;
		for (int i = 0; i < er+1 ; ++i){
			for (int j = 0; j < ec+1; ++j){
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
		exit(0);
	}
	
	if (row>er or col>ec){
		return false;
	}

	if (a[row][col] == 'X'){
		return false;
	}
	bool ans=false;
	b[row][col] = 1;
	ans = rat_path(a,b,row,col+1,er,ec);
	ans = rat_path(a,b,row+1,col,er,ec);
	b[row][col] = 0;
	return ans;
}

int main(int argc, char const *argv[])
{
	int row,col;
	cin>>row>>col;
	char a[1001][1001];
	for (int i = 0; i <row ; ++i){
		for (int j = 0; j < col; ++j){
			cin>>a[i][j];
		}
	}
	int b[1001][1001] = {0};
	if(rat_path(a,b,0,0,row-1,col-1) == 0){
		cout<<"-1";
	}
	return 0;
}