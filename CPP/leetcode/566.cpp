#include<iostream>
#include<vector>
using namespace std;

//tC:O(R*c)
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
     vector<vector<int>>res(r,vector<int>(c));

     if(mat.size()*mat[0].size() !=r*c) {
        return mat;
     }

     int row=0;
     int col=0;
     for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            res[row][col]=mat[i][j];
            col++;
            if(col==c){
                row++;
                col=0;
            }
        }
     }
     return res;
        
    }

int main(){

    int m,n;
    cin>>m>>n;

    vector<vector<int>>mat(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    int r,c;
    cin>>r>>c;

    vector<vector<int>>res=matrixReshape(mat,r,c);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}