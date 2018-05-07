#include <iostream>
#include<conio.h>
using namespace std;
class hugeinteger
{
private:
	int size;
	int huge[40];
public:
	hugeinteger();
	hugeinteger(char[]);
	void input();
	void output();
	hugeinteger add(const hugeinteger&,const hugeinteger&);
	hugeinteger sub(const hugeinteger&,const hugeinteger&);
	hugeinteger mul(const hugeinteger&,const hugeinteger&);
	bool isEqualTo(const hugeinteger&,const hugeinteger&);
	bool isNotEqualTo(const hugeinteger&,const hugeinteger&);
	bool isGreaterThan(const hugeinteger&,const hugeinteger&);
	bool isLessThan(const hugeinteger&,const hugeinteger&);
	bool isGreaterThanOrEqualTo(const hugeinteger&,const hugeinteger&);
	bool isLessThanOrEqualTo(const hugeinteger&,const hugeinteger&);
	bool isZero();
};
hugeinteger::hugeinteger()
{
	size=0;
	for (int i=0;i<40;i++)
		huge[i]=0;
}
hugeinteger::hugeinteger(char value[])
{
	int i=0,j=9;
	size=strlen(value);
	for (i=39,j=(size-1);j>=0;i--,j--)
		huge[i]=value[j]-48;
	for (j=i;j>=0;j--)
		huge[j]=0;
}
void hugeinteger::input()
{
	size=0;
	int i=0,j=0,temp;;
	char input;
	for (i=39;i>=0;i--)
	{
		input=getche();
		if(input=='-')
			break;
		size++;
		huge[i]=input-48;
	}
	if(input=='-')
		for (j=i;j>=0;j--)
			huge[j]=0;
	for (i=39-(size-1),j=39;i<j;i++,j--)
	{
		temp=huge[i];
		huge[i]=huge[j];
		huge[j]=temp;
	}
}
void hugeinteger::output()
{
	bool check=true;
	for (int i=0;i<40;i++)
	{
		if(check==true && huge[i]==0)
			continue;
		else
		{
			check=false;
			cout<<huge[i];
		}
	}
	if(check==true)
		cout<<"0";
	cout<<endl;
}
hugeinteger hugeinteger::add(const hugeinteger &h1,const hugeinteger &h2)
{
	hugeinteger h;
	int mod,div=0;
	for (int i=39;((i>=40-h1.size)||(i>=40-h2.size));i--)
	{
		h.huge[i]=h1.huge[i]+h2.huge[i]+div;
		h.size++;
		if(h.huge[i]>9)
		{
			mod=h.huge[i]%10;
			div=h.huge[i]/10;
			h.huge[i]=mod;
		}
		else
			div=0;
	}
	cout<<endl<<"Addition:";
	return h;
}
hugeinteger hugeinteger::sub(const hugeinteger &h1,const hugeinteger &h2)
{
hugeinteger h;
	int i=0,j=0,sub,decrement=0;
	bool check;
	check=isGreaterThanOrEqualTo(h1,h2);
	if(check==true)
	{
		for (i=39;i>=(40-h1.size);i--)
		{
			h.size++;
			if(i==(40-h1.size))
			{
				h.huge[i]=h1.huge[i]-h2.huge[i]-decrement;
				break;
			}
			if((h1.huge[i]-decrement)>=h2.huge[i])
			{
				h.huge[i]=h1.huge[i]-h2.huge[i]-decrement;
				decrement=0;
			}
			else
			{
				sub=(h1.huge[i]-decrement)+10;
				h.huge[i]=sub-h2.huge[i];
				decrement=1;
			}
		}
	}
	else
	{
		for (i=39;i>=(40-h2.size);i--)
		{
			h.size++;
			if(i==(40-h2.size))
			{
				h.huge[i]=h2.huge[i]-h1.huge[i]-decrement;
				break;
			}
			if((h2.huge[i]-decrement)>=h1.huge[i])
			{
				h.huge[i]=h2.huge[i]-h1.huge[i]-decrement;
				decrement=0;
			}
			else
			{
				sub=(h2.huge[i]-decrement)+10;
				h.huge[i]=sub-h1.huge[i];
				decrement=1;
			}
		}
		if(h.huge[40-h.size]!=0)
			h.huge[40-h.size]=-h.huge[40-h.size];
		else
			h.huge[(40-h.size)+1]=-h.huge[(40-h.size)+1];
		
	}
	cout<<endl<<"Subtraction:";
	return h;
}
hugeinteger hugeinteger::mul(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<"Multiplication: ";
	hugeinteger h;
	int add=0;
	for (int i=39;i>=(40-h2.size);i--)
	{
		add=0;
		for (int j=39,k=i;k>=0;j--,k--)
		{
			h.huge[k]=(h1.huge[j]*h2.huge[i])+h.huge[k]+add;
			add=h.huge[k]/10;
			h.huge[k]=h.huge[k]%10;
		}
	}
	return h;
}
bool hugeinteger::isEqualTo(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<endl<<"Is Equal to:";
	int i=0;
	for (i=0;i<40;i++)
		if(h1.huge[i]!=h2.huge[i])
			return false;
	return true;
}
bool hugeinteger::isNotEqualTo(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<endl<<"Is Not Equal to:";
	int i=0;
	for (i=0;i<40;i++)
		if(h1.huge[i]!=h2.huge[i])
			break;
	if(i<40)
		return true;
	return false;
}
bool hugeinteger::isGreaterThan(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<endl<<"Is Greater than:";
	int i=0;
	for (i=0;i<40;i++)
	{
		if(h1.huge[i]<h2.huge[i])
			return false;
		if(h1.huge[i]>h2.huge[i])
			return true;
	}
	return false;
}
bool hugeinteger::isLessThan(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<endl<<"Is Less than:";
	int i=0;
	for (i=0;i<40;i++)
	{
		if(h1.huge[i]<h2.huge[i])
			return true;
		if(h1.huge[i]>h2.huge[i])
			return false;
	}
	return false;
}
bool hugeinteger::isGreaterThanOrEqualTo(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<endl<<"Is Greater than or Equal to:";
	int i=0;
	for (i=0;i<40;i++)
	{
		if(h1.huge[i]<h2.huge[i])
			return false;
		if(h1.huge[i]>h2.huge[i])
			return true;
	}
	return true;
}
bool hugeinteger::isLessThanOrEqualTo(const hugeinteger &h1,const hugeinteger &h2)
{
	cout<<endl<<"Is Less than or Equal to:";
	int i=0;
	for (i=0;i<40;i++)
	{
		if(h1.huge[i]<h2.huge[i])
			return true;
		if(h1.huge[i]>h2.huge[i])
			return false;
	}
	return true;
}
bool hugeinteger::isZero()
{
	cout<<endl<<"Is Zero:";
	for (int i=(40-size);i<40;i++)
		if(huge[i]!=0)
			return false;
	return true;
}
int main()
{
	hugeinteger h,h1,h2,ha,hs,hm;
	h1.input();
	h1.output();
	h2.input();
	h2.output();
	ha=h.add(h1,h2);
	ha.output();
	hs=h.sub(h1,h2);
	hs.output();
	hm=h.mul(h1,h2);
	hm.output();
	cout<<h.isEqualTo(h1,h2)<<endl;
	cout<<h.isNotEqualTo(h1,h2)<<endl;
	cout<<h.isGreaterThan(h1,h2)<<endl;
	cout<<h.isLessThan(h1,h2)<<endl;
	cout<<h.isGreaterThanOrEqualTo(h1,h2)<<endl;
	cout<<h.isLessThanOrEqualTo(h1,h2)<<endl;
	cout<<h1.isZero()<<endl;
	cout<<h2.isZero()<<endl;
	system("pause");
	return 0;
}
