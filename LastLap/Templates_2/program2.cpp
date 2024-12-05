#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Matrix{
    int rows, cols;
    vector<vector<T>> m;

    public:
    Matrix(){}

    Matrix(int rows, int cols){
        this->rows = rows;
        this->cols = cols;
        m.resize(rows, vector<T>(cols));
    }

    void setValues(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>m[i][j];
            }
        }
    }

    void getValues(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<m[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    Matrix<T> add(Matrix<T> &m2){
        if(rows!=m2.rows || cols!=m2.cols){
            throw "Rows and Cols are not equal";
        }

        Matrix<T> result(rows, cols);

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                result.m[i][j] = m[i][j]+m2.m[i][j];
            }
        }

        return result;
    }
};

int main(){
    Matrix<int> M1(2, 2), M2(2, 2);
    M1.setValues();
    M1.getValues();

    M2.setValues();
    M2.getValues();

    try{
        Matrix<int> M3 = M1.add(M2);
        M3.getValues();
    }catch(const char* c){
        cout<<c<<endl;
    }
}