#include <iostream>
template <class T>
class vector
{
	int size;
	T* data;
	void quicksort(unsigned int left, unsigned int right);
public:
	vector();
	vector(const vector& v);
	vector(T* array, int arrsize);
	vector(unsigned int s);
	~vector();
	int length();
	T& operator[](const int numb);
	T operator[](const int numb)const;
	vector operator+ (const vector& v)const;
	vector operator- (const vector& v)const;
	vector operator*(const double a)const;
	T operator*(const vector& v)const;
	vector operator/(const double a) const;
	bool operator!=(const vector& v)const;
	vector& operator=(const vector<T>& Right);
	bool operator ==(const vector& right);
	bool operator !=(const vector& right);
	void BotleSort();
	void QuickSort();
	void InsertSort();
	void Resize(const int n);
	unsigned int Count(const T& c)const;
	vector<T*> find(const T& value)const;
	template <class T>
	friend std::istream& operator>>(std::istream& in, const vector<T>& c);
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, vector<T> m);
};
template <class T>
void vector<T>::quicksort(unsigned int left,unsigned int right)
{
	T comp = data[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while (data[i] < comp)
			i++;
		while (data[j] > comp)
			j--;
		if (i <= j)
		{
			if (data[i] > data[j])
			{
				T temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < right)
		quicksort(i, right);
	if (j > left)
		quicksort(left, j);
}

template<class T>
inline vector<T>::vector()
{
	data = nullptr;
	size = 1;
	data = new T[1];
	if (data == nullptr)
		throw "Memory generation error";
	data[0] = 1;
}

template<class T>
inline vector<T>::vector(const vector& v)
{
	size = v.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

template<class T>
inline vector<T>::~vector()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	size = 0;
}

template<class T>
inline vector<T>::vector(T* array, int arrsize)
{

	data = nullptr;
	data = new T[arrsize];
	if (data == nullptr)
		throw "Memory generation error";
	size = arrsize;
	for (int i = 0; i < arrsize; i++)
		data[i] = array[i];
}

template<class T>
inline vector<T>::vector(unsigned int s)
{
	size = s;
	data = nullptr;
	data = new T[size];
	if (data == nullptr)
		throw "Memory generation error";
	for (int i = 0; i < size; i++)
		data[i] = 0;

}

template<class T>
inline int vector<T>::length()
{
	return size;
}

template<class T>
inline T& vector<T>::operator[](const int numb)
{
	return data[numb];
}

template<class T>
inline T vector<T>::operator[](const int numb)const
{
	return data[numb];
}

template<class T>
inline vector<T> vector<T>::operator+(const vector& v) const
{
	vector<T> res(*this);
	if (size < v.size)
	{
		res.Resize(v.size);
		for (int i = 0; i < v.size; i++)
			res[i] = res[i] + v[i];
		
	}			
	else
	{
		for (int i = 0; i < v.size; i++)
			res[i] = res[i] + v[i];
	}
	return res;
}

template<class T>
inline vector<T> vector<T>::operator-(const vector& v) const
{
	vector<T> res(*this);
	if (size ==  v.size)
	{
		for (int i = 0; i < v.size; i++)
		res[i] = res[i] - v[i];
	}			
	else
	{
		res.Resize(v.size);
		for (int i = 0; i < v.size; i++)
		res[i] = res[i] - v[i];
	}
	return res;
}

template<class T>
inline vector<T> vector<T>::operator*(const double a)const
{
	vector<T> res(*this);
	for (int i = 0; i < size; i++)
	{
		res[i] = res[i] * a;
	}
	return res;
}

template<class T>
inline T vector<T>::operator*(const	vector& v)const
{
	T res;
	if (size > v.size)
	{
		res = 0;
		for (int i = 0; i < v.size; i++)
		{
			res += this->data[i] * v[i];
		}
	}
	else
	{
		res = 0;
		for (int i = 0; i < size; i++)
		{
			res += this->data[i] * v[i];
		}
	}
	return res;
}

template<class T>
inline vector<T> vector<T>::operator/(const double a)const
{
	vector res(*this);
	for (int i = 0; i < size; i++)
	{
		res[i] = data[i] / a;
	}
	return res;
}

template<class T>
inline bool vector<T>::operator!=(const vector& v) const
{
	if (size == v.size)
		for (int i = 0; i < size; i++)
			if (data[i] != v.data[i]) return false;
	return true;
}

template<class T>
inline vector<T>& vector<T>::operator=(const vector<T>& Right)
{
	if (*this != Right)
	{
		if(data != nullptr)
		delete[] data;
		unsigned int leng = Right.size;
		data = new T[leng];
		size = Right.size;
		for (int i = 0; i < size; i++)
			data[i] = Right.data[i];
	}
	return *this;
}

template<class T>
inline bool vector<T>::operator==(const vector& right)
{
	if (size != right.size) return false;
	for (int i = 0; i < size; i++)
		if (data[i] != right.data[i]) return false;
	return true;
}

template<class T>
inline bool vector<T>::operator!=(const vector& right)
{
	if(*this == right)	return false;
	return true;
}

template<class T>
inline void vector<T>::BotleSort()
{
	T copy;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1; j++)
			if (data[j] > data[j + 1])
			{
				copy = data[j];
				data[j] = data[j + 1];
				data[j + 1] = copy;
			}
}

template<typename T>
void vector<T>::QuickSort()
{
	if (size > 1)
		quicksort(0, size - 1);
}


template<class T>
inline void vector<T>::InsertSort()
{
	for (int i = 0; i < size - 1; i++)
	{
		T copy = data[i - 1];
		int j = i - 1;
		for (int k = i + 1; k > 0; k--)
			if (copy < data[k - 1])
			{
				data[k] = data[j - 1];
				j = k - 1;
			}
		data[j] = copy;
	}
}

template<class T>
inline void vector<T>::Resize(const int n)
{
	if (size != n)
	{
		int copysize = size;
		T* copy = data; // сохранение изначальных данных
		size = n;
		data = nullptr;
		data = new T[size];
		if (data == nullptr)
			throw "Memmory generation error";
		if (n >= copysize) //Случай, когда мы меняем размер памяти на больший
		{
			for (int i = 0; i < copysize; i++)
				data[i] = copy[i];
			for (int i= copysize; i < size; i++)
				data[i] = 0;
		}
		else //Случай, когда мы изменям размер на меньший
		{
			for (int i = 0; i < n; i++)
				data[i] = copy[i];
		}
		delete[] copy;
	}
	else
		std::cout << "Same size" << std::endl;
}

template<class T>
inline unsigned int vector<T>::Count(const T& c)const
{
	unsigned int res = 0;
	for (int i = 0; i < size; i++)
		if (data[i] == c)
			res++;
	return res;
}

template<class T>
inline vector<T*> vector<T>::find(const T& value)const
{
	vector<T*> res(Count(value));
	unsigned int k = 0;
	for (int i = 0; i < size; i++)
		if (value == data[i])
		{
			res[k] = data + i;
			k++;
		}
	return res;
}

template<class T>
inline std::istream& operator>>(std::istream& in, const vector<T>& c)
{
	for (int i = 0; i < c.size; i++)
		in >> c.data[i];
	return in;
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, vector<T> m)
{
	for (int j = 0; j < m.size; j++)
		out << m.data[j] << " ";
	out << std::endl;
	return out;
}
