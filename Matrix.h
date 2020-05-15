#include <iostream>
template <class T>
class Matrix
{
	size_t size_column, size_string;
	T** data;
	void Resize(int n = size_string, int m = size_column);
public:
	Matrix();
	Matrix(const Matrix& m);
	Matrix(size_t s, size_t c);
	~Matrix();
	bool operator!=(const Matrix& m) const;
	bool operator==(const Matrix& m)const;
	Matrix& operator=(const Matrix m);
	Matrix operator+(const Matrix& m)const;
	Matrix operator- (const Matrix& m)const;
	Matrix operator*(const Matrix&)const;
	T* operator[](const int n);
	int GetSizeColumn()const;
	int GetSizeString()const;
	//T SetElement(int i, int j);
	template <class T>
	friend std::istream& operator>>(std::istream& in, Matrix<T>& c);
	template <class T>
	friend std::ostream& operator<<(std::ostream& out,const Matrix<T>& m);
};

	template<class T>
	inline Matrix<T>::Matrix()
	{
		data = new T*[1];
		data[0] = new T[1];
		size_column = 1;
		size_string = 1;
		data[0][0] = 0;
	}

	template<class T>
	inline Matrix<T>::Matrix(const Matrix<T>& m)
	{
		size_string = m.size_string;
		size_column = m.size_column;
		data = new T * [size_string];
		for (int i = 0; i < size_string; i++)
		{
			data[i] = new T[size_column];
		}
		for (int i = 0; i < size_string; i++)
			for (int j = 0; j < size_string; j++)
				data[i][j] = m.data[i][j];
	}

	template<class T>
	inline Matrix<T>::Matrix(size_t s, size_t c)
	{
		size_string =s;
		size_column = c;
		data = new T * [size_string];
		for (int i = 0; i < size_string; i++)
		{
			data[i] = new T[size_column];
		}
		for (int i = 0; i < size_string; i++)
			for (int j = 0; j < size_string; j++)
				data[i][j] = 0;
	}

	template<class T>
	inline Matrix<T>::~Matrix<T>()
	{
		if(data != nullptr)
			for (int i = 0; i < size_string; i++)
			{
				if(data[i] != nullptr)
				delete[] data[i];
			}
		delete[] data;
		size_string = 0;
		size_column = 0;
	}

	template<class T>
	inline bool Matrix<T>::operator!=(const Matrix<T>& m)const
	{
		int k = 0;
		if (size_string == m.size_string && size_column == m.size_column)
			for (int i = 0; i < size_string; i++)
				for (int j = 0; j < size_column; j++)
					if (data[i][j] != m.data[i][j])
						return false;
		return true;
	}

	template<class T>
	inline bool Matrix<T>::operator==(const Matrix<T>& m) const
	{
		if (*this != m)	return false;
		else return true;
	}
	
	template<class T>
	inline Matrix<T>& Matrix<T>::operator=(const Matrix<T> m)
	{
		if (*this != m)
		{
			delete[] data;
			data = new T* [m.size_string];
			for (int i = 0; i < m.size_string; i++)
				data[i] = new T[size_column];
			size_column = m.size_column;
			size_string = m.size_string;
			for (int i = 0; i < size_string; i++)
				for (int j = 0; j < size_column; j++)
					data[i][j] = m.data[i][j];
		}
		return *this;
	}

	template<class T>
	inline Matrix<T> Matrix<T>::operator+(const Matrix& m)const
	{
		Matrix<T> res(size_string, size_column);
		if (size_column == m.size_column && size_string == m.size_string)
		{
			for (int i = 0; i < size_string; i++)
				for (int j = 0; j < size_column; j++)
					res.data[i][j] = data[i][j] + m.data[i][j];
		}
		else throw "Wrong sizes of Matrix";
		return res;
	}

	template<class T>
	inline Matrix<T> Matrix<T>::operator-(const Matrix& m) const
	{
		Matrix<T> res(size_string, size_column);
		if (size_column == m.size_column && size_string == m.size_string)
		{
			for (int i = 0; i < size_string; i++)
				for (int j = 0; j < size_column; j++)
					res.data[i][j] = data[i][j] - m.data[i][j];
		}
		else throw "Wrong sizes of Matrix";
		return res;
	}

	template<class T>
	inline Matrix<T> Matrix<T>::operator*(const Matrix& m)const
	{
		Matrix<T> mult(size_string, m.size_column);
			if (size_column == m.size_string)
			{
				for (int i = 0; i < size_string; i++)
					for (int j = 0; j < m.size_column; j++)
						for (int k = 0; k < size_column; k++)
							mult.data[i][j] += data[i][k] * m.data[k][i];
			}
			else
			{
				throw "Wrong sizes of Matrix";
			}
		return mult;
	}

	template<class T>
	inline T* Matrix<T>::operator[](const int n)
	{
		return data[n];
	}

	template<class T>
	inline int Matrix<T>::GetSizeColumn()const
	{
		return size_column;
	}

	template<class T>
	inline int Matrix<T>::GetSizeString()const
	{
		return size_string;
	}
	/*template<class T>
	inline T Matrix<T>::SetElement(int i, int j)
	{
		return data[i][j];
	}*/
	template<class T>
	inline void Matrix<T>::Resize(int n, int m)
	{
		Matrix<T> copy(*this);
		if (n != size_string)
		{
			if(data != nullptr)
			delete[] data;
			data = new T*[n];
			for (int i = 0; i < n; i++)
				if (size_column == m)
					data[i] = new T[size_column];
				else
					data[i] = new T[m];
			size_string = n;
			size_column = m;
			for (int i = 0; i < (copy.size_string < n ? copy.size_string : n); i++)
			{
				for(int j = 0; j < (copy.size_column < n ? copy.size_column : n); j++)
				data[i][j] = copy[i][j];
			}
		}
	}
	template<class T>
	inline std::ostream& operator<<(std::ostream& out,const Matrix<T>& m)
	{
		for (int i = 0; i < m.size_string; i++)
		{
			for (int j = 0; j < m.size_column; j++)
				out << m.data[i][j] << " ";
			out << std::endl;
		}
		return out;
	}
	template<class T>
	inline std::istream& operator>>(std::istream& in, Matrix<T>& c)
	{
		std::cout << "Enter size string: ";
		int n = 0;
		std::cin >> n;
		std::cout << "Enter size column: ";
		int column = 0;
		std::cin >> column;
		c.Resize(n, column);
		for (int i = 0; i < c.GetSizeString(); i++)
			for (int j = 0; j < c.GetSizeColumn(); j++)
				in >> c.data[i][j];
		return in;
	}
