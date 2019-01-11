#pragma once
template<class T>
class CMatrix
{
public:
    CMatrix(void)
	{
	mRow=0;
	mCol=0;
	mpElement=NULL;
	}

	CMatrix(int Row,int Col)
	{
	Create(Row,Col);
	}

	void Create(int Row,int Col)
	{
		mRow=Row;
		mCol=Col;
		mpElement=new T[mRow*mCol];
		for(int i=0;i<mRow*mCol;i++)
			mpElement[i]=1.0*(rand()/2);
	}

	CMatrix(CMatrix& Mat)
	{
		mRow=Mat.mRow;
		mCol=Mat.mCol;
		mpElement= new T[mRow*mCol];
		for(int i=0;i<mRow*mCol;i++)
		mpElement[i]=Mat.mpElement[i];
	}

	CMatrix& operator=(CMatrix& Mat)
	{
		mRow=Mat.mRow;
		mCol=Mat.mCol;
		mpElement= new T[mRow*mCol];
		for(int i=0; i<mRow*mCol; i++)
		mpElement[i] = Mat.mpElement[i];

		return *this;
	}

	CMatrix operator+(CMatrix& Mat)
	{
	CMatrix<T>AddMat(mRow,mCol);
		for(int i=0;i<mRow;i++)
			for(int j=0;j<mCol;j++)
				AddMat[i][j]=(*this)[i][j]+Mat[i][j];
	
	return AddMat; 
	}

	CMatrix operator-(CMatrix& Mat)
	{
	CMatrix<T>SubMat(mRow,mCol);
		for(int i=0;i<mRow;i++)
			for(int j=0;j<mCol;j++)
				SubMat[i][j]=(*this)[i][j]-Mat[i][j];
	
	return SubMat; 
	}
	
	CMatrix operator*(CMatrix& Mat)
	{
	    CMatrix<T>MulMat(mRow,mCol);
		MulMat.mRow = mRow;
		MulMat.mCol = Mat.mCol;
        int i, j, k;
	    for(int i=0;i<mRow;i++)
			for(int j=0;j<mCol;j++)
				MulMat[i][j]=0;
		if (mCol != Mat.mRow)
        {
			AfxMessageBox(_T( "ÎÞ·¨Ïà³Ë£¡"));
        return MulMat;
		}
		
		for (i = 0; i < MulMat.mRow; i++)
            for (j = 0; j < MulMat.mCol; j++)
                for (MulMat[i][j] = k = 0; k < mCol; k++)
                    MulMat[i][j] += (*this)[i][k] * Mat[k][j];

	    return MulMat; 
	}

	T *operator[](int i)
	{
	return &mpElement[i*mCol];
	
	}



	~CMatrix(void)
	{
	if(mpElement)
		delete []mpElement;
	}

	int mRow;
	int mCol;
	T* mpElement;
};

