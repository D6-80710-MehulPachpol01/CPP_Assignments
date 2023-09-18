
#include<iostream>
using namespace std;

class Matrix
{
    private:
        int rows;
        int cols;
        int** data;
    public:
        Matrix(){
            this->rows = 0;
            this->cols = 0;
            this->data = NULL;
        }

        Matrix(int rows, int cols){
            this->rows = rows;
            this->cols  =cols;
            this->data = new int*[rows];
            for(int i=0; i<rows; i++){
                this->data[i] = new int[this->cols];
            }
        }

        void accept(){
            cout<<"Enter matrix elements: "<<endl;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    cout<<"matrix["<<i<<"]["<<j<<"] = ";
                    cin>>this->data[i][j];
                }
            }
        }

        void print(){
            cout<<"Matrix elements: "<<endl;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    cout<<"matrix["<<i<<"]["<<j<<"] = "<<this->data[i][j]<<endl;
                }
            }
        }
//Add func
        Matrix& add(Matrix &other) {
            if (this->rows != other.rows || this->cols != other.cols) {
                cout << "Can't able to perform addition on matrix..."<<endl;
                static Matrix m1;
                return m1;
            }

            static Matrix result(this->rows, this->cols);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = this->data[i][j] + other.data[i][j];
                }
            }

            return result;
        }
//Subtract Func
        Matrix& subtract(Matrix &other) {
            if (this->rows != other.rows || this->cols != other.cols) {
                cout << "Can't able to perform subtraction on matrix..."<<endl;
                static Matrix m1;
                return m1;
            }

            static Matrix result(this->rows, this->cols);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = this->data[i][j] - other.data[i][j];
                }
            }

            return result;
        }

        Matrix& multiply(Matrix &other) {
            if (this->cols != other.rows) {
                cout << "Can't able to perform subtraction on matrix..."<<endl;
                static Matrix m1;
                return m1;
            }

            static Matrix result(this->rows, other.cols);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    result.data[i][j] = 0;
                    for (int k = 0; k < cols; k++) {
                        result.data[i][j] += this->data[i][k] * other.data[k][j];
                    }
                }
            }

            return result;
        }
//Transpose

        Matrix& transpose() {
            static Matrix result(cols, rows);

            for (int i = 0; i < cols; i++) {
                for (int j = 0; j < rows; j++) {
                    result.data[i][j] = this->data[j][i];
                }
            }

            return result;
        }

        ~Matrix(){
            if(this->data != NULL)
            {
                for(int i=0; i<rows; i++){
                    delete[] this->data[i];
                }
                delete[] this->data;
            }
        }
};

enum EMainMenu{
    EXIT,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    TRANSPOSE,
    MATRIXA,
    MATRIXB
};

EMainMenu menu(){
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. ADDITION"<<endl;
    cout<<"2. SUBTRACTION"<<endl;
    cout<<"3. MULTIPLICATION"<<endl;
    cout<<"4. TRANSPOSE"<<endl;
    cout<<"5. DISPLAY MATRIX A"<<endl;
    cout<<"6. DISPLAY MATRIX B"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    return (EMainMenu)choice;
}

int main() {
    int numRows, numCols;

    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> numRows >> numCols;

    Matrix matrixA(numRows, numCols);
    matrixA.accept();

    cout << "Enter the number of rows and columns for Matrix B: ";
    cin >> numRows >> numCols;

    Matrix matrixB(numRows, numCols);
    matrixB.accept();

    Matrix result;
    Matrix& res=result;
    EMainMenu choice;

    while((choice = menu()) != EXIT)
    {
        switch(choice)
        {
            case ADDITION: 
                res = matrixA.add(matrixB);
                cout << "Addition of matrix:"<<endl;
                res.print();
                break;
            case SUBTRACTION: 
                result = matrixA.subtract(matrixB);
                cout << "Subtraction of matrix:"<<endl;
                result.print();
                break;
            case MULTIPLICATION: 
                result = matrixA.multiply(matrixB);
                cout << "Multiplication of matrix:"<<endl;
                result.print();
                break;
            case TRANSPOSE:
                result = matrixA.transpose();
                cout << "Transpose of Matrix:"<<endl;
                result.print(); 
                break;
            case MATRIXA: 
                cout << "Matrix A:"<<endl;
                matrixA.print();
                break;
            case MATRIXB: 
                cout << "Matrix B:"<<endl;
                matrixB.print();
                break;
            default:
                cout<<"Enter correct choice..."<<endl;
                break;
        }
    }

    cout<<"Exiting..."<<endl;

    return 0;
}
