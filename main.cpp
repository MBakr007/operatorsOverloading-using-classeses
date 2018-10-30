#include <iostream>

using namespace std;

class Matrix
{
private:
    int row, col ;
    int* data ;
public:
    Matrix(int row, int col, int num[] )
    {
        this-> row = row ;
        this-> col = col ;
        data = new int [row * col] ;
        for ( int i = 0 ; i < row * col ; i++ )
            data [i] = num [i] ;
    }


    Matrix ()
    {
        row = 0 ;
        col = 0 ;
        data = new int [row * col] ;
        for ( int i = 0 ; i < row * col ; i++ )
            data [i] = 0 ;
    }
    friend ostream& operator<< ( ostream& out , Matrix mat );
    friend Matrix operator+ (Matrix mat1, Matrix mat2 );
    friend Matrix operator- (Matrix mat1, Matrix mat2 );
    friend Matrix operator-  ( Matrix mat1 , int scalar );
    friend Matrix operator+  ( Matrix mat1 , int scalar );
    friend Matrix operator*  ( Matrix mat1 , int scalar );
    friend Matrix operator+= ( Matrix& mat1 , Matrix mat2 );
    friend Matrix operator-= ( Matrix& mat1 , Matrix mat2 );
    friend Matrix operator+= ( Matrix& mat, int scalar );
    friend Matrix operator-= ( Matrix& mat, int scalar );
    friend void   operator++ ( Matrix& mat );
    friend void   operator-- ( Matrix& mat );
    friend istream& operator>> ( istream& in , Matrix& mat );
};

Matrix operator+ ( Matrix mat1 , Matrix mat2 )
{
    Matrix mat3 ;
    if( mat1.col == mat2.col && mat1.row == mat2.row )
    {
        mat3.row=mat1.row;
        mat3.col=mat1.col;
        for(int i=0 ; i< mat1.col * mat1.row ; i++)
        {
            mat3.data[i]=mat1.data[i]+mat2.data[i];
        }
    }
    return mat3;
}

Matrix operator- (Matrix mat1, Matrix mat2 )
{
    Matrix mat3  ;
    if (mat1.col==mat2.col && mat1.row == mat2.row )
    {
        mat3.col=mat1.col;
        mat3.row=mat1.row;
        for(int i=0 ; i<mat1.col*mat1.row ; i++)
        {
            mat3.data[i]=mat1.data[i]-mat2.data[i];
        }
    }
    return mat3 ;
}

Matrix operator+  ( Matrix mat1 , int scalar )  /// Add a scalar
{
    Matrix mat2 ;
    mat2.col=mat1.col;
    mat2.row=mat1.row;
    for ( int i = 0 ; i < mat1.col * mat1.row ; i++ )
    {
        mat2.data[i] = mat1.data[i] + scalar ;
    }
    return mat2 ;
}

Matrix operator-  ( Matrix mat1 , int scalar )  /// Add a scalar
{
    Matrix mat2 ;
    mat2.col=mat1.col;
    mat2.row=mat1.row;
    for ( int i = 0 ; i < mat1.col * mat1.row ; i++ )
    {
        mat2.data[i] = mat1.data[i] - scalar ;
    }
    return mat2 ;
}

Matrix operator*  ( Matrix mat1 , int scalar )  /// Multiple by scalar
{
    Matrix mat2;
    mat2.col=mat1.col;
    mat2.row=mat1.row;
    for ( int i = 0 ; i < mat1.col * mat1.row ; i++ )
    {
        mat2.data[i] = mat1.data[i] * scalar ;
    }
    return mat2 ;
}
 /// #Student_2 :

 Matrix operator+= ( Matrix& mat1 , Matrix mat2 ) /// mat1 changes & return new matrix with the sum
{
    if ( mat1.col == mat2.col && mat1.row == mat2.row )
    {
        for ( int i = 0 ; i < mat1.col * mat1.row ; i++ )
        {
            mat1.data[i] +=mat2.data[i] ;
        }
    }
    return mat1 ;
}

Matrix operator-= ( Matrix& mat1 , Matrix mat2 ) /// mat1 changes & return new matrix with the sum
{
    if ( mat1.col == mat2.col && mat1.row == mat2.row )
    {
        for ( int i = 0 ; i < mat1.col * mat1.row ; i++ )
        {
            mat1.data[i] -= mat2.data[i] ;
        }
    }
    return mat1 ;
}

Matrix operator+= ( Matrix& mat, int scalar )   /// change mat & return new matrix
{
    for ( int i = 0 ; i < mat.col * mat.row ; i++ )
    {
        mat.data[i] += scalar ;
    }
    return mat ;
}


Matrix operator-= ( Matrix& mat , int scalar )   /// change mat & return new matrix
{
    for ( int i = 0 ; i < mat.col * mat.row ; i++)
    {
        mat.data[i] -= scalar ;
    }
    return mat ;
}


void   operator++ ( Matrix& mat )  	/// Add 1 to each element ++mat
{
    for ( int i = 0 ; i < mat.col * mat.row ; i++ )
    {
        mat.data[i]++ ;
    }
}


void   operator-- ( Matrix& mat )  	/// Sub 1 from each element --mat
{
    for ( int i = 0 ; i < mat.col * mat.row ; i++ )
    {
        mat.data[i]-- ;
    }
}

istream& operator>> ( istream& in , Matrix& mat ) /// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
{                                                 /// and return istream to allow cascading input
    int row=0 , col=0 ;
    in >> row >> col ;
    mat.col = col ;
    mat.row = row ;
    for ( int i = 0 ; i < row * col ; i++ )
    {
        in >> mat.data[i] ;

    }
    return in ;

}



ostream& operator<< ( ostream& out , Matrix mat )
{
    for (int i = 0 ; i < mat.col * mat.row ; i++ )
    {
        if ( i % mat.col == 0 )
            cout << endl ;
        out << mat.data[i] << " " ;
    }
    return out ;
}


int main()
{
    int data1[] = {1,2,3,4,5,6,7,8} ;
    int data2[] = {1,2,3,4,5,6,7,8} ;

    Matrix mat1 (4,2,data1);
    Matrix mat2 (4,2,data2);
    Matrix mat3 ;

    cout<<"The original mat1 : "<<endl;
    cout<<mat1<<endl;

    cout<<"The original mat2 : "<<endl;
    cout<<mat2<<endl;

    cout<<"Enter mat3 , please : " ;
    cin >> mat3 ;

    cout<<endl<<"The original mat3 : "<<endl;
    cout<<mat3<<endl;

    cout<<"mat1 + mat2 : "<<endl;
    cout<<(mat1+mat2)<<endl;

    cout<<"mat1 - mat2 : "<<endl;
    cout<<(mat1-mat2)<<endl;

    cout<<"mat1 + 2 : "<<endl;
    cout<<(mat1 + 2 )<<endl;

    cout<<"mat1 - 2 : "<<endl;
    cout<<(mat1 - 2 )<<endl;

    cout<<"mat1 += mat2 : "<<endl;
    mat1 += mat2 ;
    cout<<mat1<<endl;

    cout<<"mat1 -= mat2 : "<<endl;
    mat1 -= mat2 ;

    cout<<"mat1 += 2 : "<<endl;
    mat1+=2;
    cout<<mat1<<endl;

    cout<<"mat1 -= 2 : "<<endl;
    mat1-=2;
    cout<<mat1<<endl;




    return 0;
}
