#include<iostream>
using namespace std;

template <class T>
class Array
{
	private:

		T *p;
		int n;

	public:
		
		Array(T *arr,int size)
		{
			p = new T[size];
			n = size;
			for(int i = 0; i < n; i++ )
			{
				p[i] = arr[i];
			}
		}


		~Array()
		{
			delete[] p;
		}

		T operator[](int i)
		{
			if(i < n && i >= 0)
			{
				return p[i];
			}
			else
				throw 0;
		}

		T Sum()
		{
			static T sum = p[0];
			for(int i=1; i<n ; i++)
			{
				sum = sum + p[i];
			}
			return sum;
		}

		void visit(void (*pfn)(T &t))
		{
			for(int i=0; i< n; i++)
			{
				pfn(p[i]);
			}
		}

};

template <class T>
void _Write(T &t)
{
	cout<<t<<endl;
}

class Complex
{
	private:
	 	int real;
		int img;
	public:
		Complex():real(0),img(0)
		{
		}
		Complex(const int r,const int i):real(r),img(i)
		{

		}
	
		Complex operator+(Complex c)
		{
			Complex c1(0,0);
			c1.real = real+c.real;
			c1.img = img+c.img;
			return c1; 
		}
		
		friend ostream& operator<<(ostream &os,Complex c)
		{
			os<<c.real;
			os<<" ";
			os<<c.img;
			os<<"i ";
			return os;
		}

};


int main()
{
	int arr1[5] = {1,12,14,6,23};
	char arr2[5] = {'A','p','p','l','e'};
	Complex arr3[5] = {Complex(1,5),Complex(3,4),Complex(2,6),Complex(7,4),Complex(0,3)};

// Sum of array elements
	Array<int> a1(arr1,5);
	cout<<a1.Sum()<<endl;
	Array<char> a2(arr2,5);
	cout<<a2.Sum()<<endl;
	Array<Complex> a3(arr3,5);
	cout<<a3.Sum()<<endl;
//Print each element using function pointer
	cout<<"1st Array elements are: \n";
	void (*pfn)(int &i) = _Write;
	a1.visit(pfn);
	cout<<"2nd Array elements are: \n";
	void (*pfn2)(char &ch) = _Write;
	a2.visit(pfn2);
	cout<<"3rd Array elements are: \n";
	void (*pfn3)(Complex &cp) = &_Write;
	a3.visit(pfn3);
//Subscript operator
	try{
	cout<<"3rd Element of 1st array is  "<<a1[2]<<endl;
	cout<<"4th Element of 3rd array is  "<<a3[3]<<endl;
	cout<<"1st Element of 2nd array is  "<<a2[0]<<endl;
	}
	catch(int code)
	{
		cout<<"Exception code: "<<code<<endl;
		cout<<"Index out of bounds \n";
		throw;
	}
	
	return 0;
}
