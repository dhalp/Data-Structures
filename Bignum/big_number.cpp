#include "big_number.h"

using namespace std;
//Worked With Audrey Puls
// default constructor, creates a 0
big_number::big_number()
{
	head_ptr = new node;
	head_ptr->data = '0';
	head_ptr->next = head_ptr->prev = nullptr;
	tail_ptr = head_ptr;
	digits = 1;
	positive = true;
	base = 10;
}

// int constructor; create big_number from base 10 integer
big_number::big_number(int i)
{
	digits = 0;
	head_ptr = new node;
	tail_ptr = head_ptr;
	head_ptr->next = head_ptr->prev = nullptr;
	base = 10; // assume decimal
	positive = true;
	
	if (i == 0)
	{
		head_ptr->data = 0;
		digits = 1;
		return;
	}
	if (i < 0) 
	{
		positive = false;
		i *= -1;
	}
	
	head_ptr->data = i % 10 + '0';
	i /= 10;
	++digits;
	
	while (i > 0)
	{
		head_ptr->prev = new node;
		head_ptr->prev->data = (i % 10) + '0';
		head_ptr->prev->next = head_ptr;
		head_ptr = head_ptr->prev;
		head_ptr->prev = nullptr;
		++digits;
		i /= 10;
	}
}

// copy constructor, creates a deep copy of m
big_number::big_number(const big_number& m)
{
	head_ptr = nullptr;
	tail_ptr = nullptr;
	*this = m;
}

// conversion constructor; convert m to a different base
big_number::big_number(const big_number& m, unsigned int b)
{
	head_ptr = tail_ptr = nullptr;
	positive = m.positive;
	
	big_number zero;
	zero.base = b;
	*this = zero;
	unsigned int digit;
	
	big_number* values = new big_number[m.base + 1];
	
	big_number j = 0;
	j.base = b;
	
	for (unsigned int i = 0; i <= m.base; ++i)
	{
		values[i] = j;
		++j;
	}
	
	for (const node* cursor = m.head_ptr; cursor != nullptr;
		cursor = cursor->next)
	{
		if (isdigit(cursor->data))
			digit = cursor->data - '0';
		else
			digit = cursor->data - 'a' + 10;
		big_number intermed = values[m.base] * (*this);
		if (intermed > zero)
		{
			intermed.sum(values[digit]);
		}
		else 
		{
			big_number temp(intermed);
			intermed = values[digit];
			intermed += temp;
		}
		*this = intermed;
	}	
	delete [] values;
}

// create a big_number from a string
big_number::big_number(const string& s, unsigned int b)
{
	digits = 0;
	head_ptr = new node;
	head_ptr->next = head_ptr->prev = nullptr;
	tail_ptr = head_ptr;
	base = b;
	unsigned int index = 0;
	positive = true;
	if (s[0] == '+')
		++index;
	if (s[0] == '-') 
	{
		positive = false;
		++index;
	}
	head_ptr->data = s[index++];
	++digits;
	node* cursor = head_ptr;
	while (index < s.length())
	{
		cursor->next = new node;
		cursor->next->data = s[index++];
		cursor->next->next = nullptr;
		cursor->next->prev = cursor;
		cursor = cursor->next;
		++digits;
	}	
}

// destructor
big_number::~big_number()
{
	clear_list(head_ptr, tail_ptr);
}

// assignment operator
big_number& big_number::operator=(const big_number& m)
{
	if (this == &m) return *this;
	base = m.base;
	copy_list(m.head_ptr, head_ptr, tail_ptr);
	positive = m.positive;
	digits = m.digits;
	return *this;
}

// set value to original value + b; return answer in original number's base
big_number& big_number::operator+= (const big_number& b)
{
	if(positive==true && b.positive==true)
	{	
		big_number temp;
		if(*this>=b)
		{
			sum(b);//use sum for smaller of the two numbers, this+b
		}
		else
		{
			temp=*this;
			*this=b;
			sum(temp);
		}
	}
	
	else if (positive==false && b.positive==false)
	{
		big_number temp;
		if(*this<b)//change logic here because numbers are now negative so comparing is the opposite if you want just which abs value of the number is higher
		{
			sum(b);//use sum for smaller of the two numbers, this+b
		}
		else 
		{
			temp=*this;
			*this=b;
			sum(temp);
		}
	}

	else if (positive==true && b.positive==false)
	{
		big_number bb;
		bb=b;
		bb.positive=true;	
		big_number temp;
		if(*this>=bb)
		{
			diff(bb);
		}
		else
		{
			temp=*this;
			*this=bb;
			diff(temp);
			bb=*this;
			bb.positive=false;
			*this=bb;
		}	
	}
	else if(positive==false && b.positive==true)
	{
		big_number bb;
		bb=*this;
		bb.positive=true;	
		big_number temp;
		if(bb>=b)
		{
			*this = bb;
			diff(b);
			bb=*this;
			bb.positive=false;
			*this=bb;
		}
		else
		{
		bb=*this;
		bb.positive=true;
		*this=b;
		diff(bb);
		}
	}
return *this;

}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator*= (const big_number& b)
{
	*this=(*this)*b;
	return *this;
}

// set value to original value - b; return answer in original number's base
big_number& big_number::operator-= (const big_number& b)
{	
	big_number bb;
	bb=b;
	bb.positive=(!b.positive);
	*this+=bb;
	return *this;
}

// set value to original value / b; return answer in original number's base
big_number& big_number::operator/= (const big_number& b)
{
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator%= (const big_number& b)
{
	return *this;
}

// prefix increment
big_number& big_number::operator++()
{
	big_number one=1;
	if(*this==0)
	{
		*this=one;
	}
	
	else if(positive==false)
	{
		diff(one);
	}
	else
	{
	*this=sum(one);
	}
	return *this;
}
// prefix decrement
big_number& big_number::operator--()
{
		big_number one=1;
		if(*this==0)
		{
			one.positive=false;
			*this=one;
		}
		else if(positive==false)		
		{
			big_number bb;
			bb=*this;
			bb.positive=true;
			*this=bb;
			sum(one);
			bb=*this;
			bb.positive=false;
			*this=bb;
			
		}
		else if(positive==true)
		{
		*this=diff(one);
		}
		
		
		return *this;

}

// assume same base, |*this| > |b|
big_number& big_number::sum(const big_number& m)
{
	node* cursor = tail_ptr;
	const node* mcursor = m.tail_ptr;
	digits = 0;  // a little scary, but let's roll with it anyway
	unsigned int dig1, dig2, result;
	unsigned int carry = 0;
	while (cursor != nullptr && mcursor != nullptr)
	{
		// we added an alphabet string to the big_number.h
		dig1 = alpha.find(cursor->data);
		dig2 = alpha.find(mcursor->data);
		result = carry + dig1 + dig2;
		if (result >= base) // we have to carry
		{
			// this code is simpler, more correct and more elegant; 
			// thanks to Audi Li!
			cursor->data = alpha[result % base];
			carry = 1;
		}
		else // we don't have to carry
		{
			cursor->data = alpha[result];
			carry = 0;
		}
		cursor = cursor->prev;
		mcursor = mcursor->prev;
		++digits;
	}
	while (cursor != nullptr)
	{
		dig1 = alpha.find(cursor->data);
		result = carry + dig1;
		if (result >= base) // carry
		{
			cursor->data = alpha[result % base];
			carry = 1;
		}
		else // no carry
		{
			cursor->data = alpha[result];
			carry = 0;
		}
		cursor = cursor->prev;
		++digits;
	}
	
	if (carry > 0)
	{
		head_ptr->prev = new node;
		head_ptr->prev->prev = nullptr;
		head_ptr->prev->next = head_ptr;
		head_ptr->prev->data = '1';
		++digits;
		head_ptr = head_ptr->prev;
	}
	return *this;
}

// assume same base, |*this| > |b|
big_number& big_number::diff(const big_number& m)
{
	node* cursor = tail_ptr;
	const node* mcursor = m.tail_ptr;
	digits = 0;  // a little scary, but let's roll with it anyway
	unsigned int dig1, dig2, result;
	unsigned int borrow = 0;
	int newdig=0;
	while (cursor != nullptr && mcursor != nullptr)//this goes from behind b/c cursor is equal to the tail ptr
	{
		// we added an alphabet string to the big_number.h
		dig1 = alpha.find(cursor->data);
		dig2 = alpha.find(mcursor->data);	
		
		if (dig1<dig2) // if we need to borrow
		{
			newdig='0'+ base+(dig1-borrow);//if you need to borrow add 10, but be sure you're adding 10 to the number with the previous
			//borrowed value(ex. 354-69 needs to borrow twice)
			result=newdig-dig2;
			borrow=1;
			cursor->data=result;
			
		}
		else // if we don't need to borrow
		{
			result='0'+ dig1-borrow-dig2;
			borrow=0;
			cursor->data=result;
		}
		cursor = cursor->prev;
		mcursor = mcursor->prev;
		++digits;
	}
	
	while (cursor != nullptr)//now take care of the digits that extend past the smaller numbers, ex 324-24, eventually you've have to do 3-0
	{
		dig1 = alpha.find(cursor->data);
		result = '0'+ dig1-borrow;//subtracting from zero because there is no other digit below to subtract from
		cursor->data=result;
		borrow=0;
		cursor = cursor->prev;
		++digits;
	}
	trim();
	return *this;
}
	
// remove leading zeros
void big_number::trim()
{
	node* cursor = head_ptr;
	while (cursor->data == '0' && head_ptr != tail_ptr)
	{
		head_ptr = cursor->next;
		delete head_ptr->prev;
		head_ptr->prev = nullptr;
		--digits;
	}
}

// friend for comparing digits
int cmp(const big_number& a, const big_number& b)
{
	if (a.digits > b.digits) return 1;
	if (a.digits < b.digits) return -1;
	const node* a_cursor;
	const node* b_cursor;
	for (a_cursor = a.head_ptr, b_cursor = b.head_ptr; 
		b_cursor != nullptr && a_cursor->data == b_cursor->data; 
		b_cursor = b_cursor->next, a_cursor = a_cursor->next)
		;
	if (a_cursor == nullptr) return 0;
	if (a_cursor->data > b_cursor->data) return 1;
	return -1;
}

bool operator >(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return true;
	if (!a.positive && b.positive)
		return false;
	if (a.positive)
		return cmp(a, b) > 0;
	else
		return cmp(a, b) < 0;
	return false;
}

bool operator >=(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return true;
	if (!a.positive && b.positive)
		return false;
	if (a.positive)
		return cmp(a, b) >= 0;
	else
		return cmp(a, b) <= 0;
	return true;
}

bool operator <(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return false;
	if (!a.positive && b.positive)
		return true;
	if (a.positive)
		return cmp(a, b) < 0;
	else
		return cmp(a, b) > 0;
	return false;
}
			
bool operator <=(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return false;
	if (!a.positive && b.positive)
		return true;
	if (a.positive)
		return cmp(a, b) <= 0;
	else
		return cmp(a, b) >= 0;
	return true;
}
			
bool operator==(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive != b.positive) return false;
	
	return cmp(a, b) == 0;
}
	
bool operator!=(const big_number& a, const big_number& b)
{
	return !(a == b);
}

ostream& operator <<(ostream& out, const big_number& n)
{
	if (!n.positive) out << '-';
	for (const node* cursor = n.head_ptr; cursor != nullptr; cursor = cursor->next)
			out << cursor->data;
	out << "(" << n.base << ")";
	return out;
}

istream& operator >>(istream& in, big_number& n)
{
	unsigned int base;
	cout << "Enter a base: ";
	cin >> base;
	cout << "Enter a number: ";
	string babin;
	in >> babin;
	
	big_number baboo(babin, base);
	n = baboo;
	return in;
}

big_number operator+(const big_number& a, const big_number& b)
{	
	big_number c(a);
	big_number d(b);
	c+=d;
	return c;	
}

big_number operator-(const big_number& a, const big_number& b)
{	
	big_number c=a;
	big_number d=b;
	c-=d;	
	return c;
}

big_number operator*(const big_number& a, const big_number& b)
{
	if(a < b)
	{
		return (b*a);
	}
	unsigned int dig1, dig2, result;
	unsigned int carry=0;
	//big_number result;
	unsigned int keeptrack=0;
	big_number product;
	int k=0;
	//big_number added_nodetemp;
	for(const node* b_cursor=b.tail_ptr; b_cursor!=nullptr; b_cursor=b_cursor->prev)
	{
	big_number int_result;
	
		for(const node* a_cursor=a.tail_ptr; a_cursor!=nullptr; a_cursor=a_cursor->prev)
		{
			dig1=a.alpha.find(a_cursor->data);
			dig2=b.alpha.find(b_cursor->data);
			result=dig1*dig2+carry;
			carry=result/a.base;
			
			if(keeptrack==0)
			{
				int_result.head_ptr->data=('0'+result%a.base);
				keeptrack++;
				int_result.digits++;
			}
			else
			{
				node* added_node=new node;
				added_node->next = int_result.head_ptr;
				added_node->prev = nullptr;
				int_result.head_ptr->prev = added_node;
				int_result.head_ptr = added_node;
				added_node->data = '0'+ result%a.base;
				int_result.digits++;
				keeptrack++;
			}
			if (a_cursor->prev == nullptr && (result - result%a.base != 0))
				{
					//cout << "fuck me" << endl;
					node* added_node=new node;
					added_node->next = int_result.head_ptr;
					added_node->prev = nullptr;
					int_result.head_ptr->prev = added_node;
					int_result.head_ptr = added_node;
					added_node->data = ('0'+ (result - result%a.base)/a.base);
					//cout << "result: " << ( result - result%a.base) <<endl;
					//cout << "prebullshit" << ('0'+ result%a.base) <<endl;	
					//cout << "bullshit" << ('0'+ result - result%a.base) <<endl;
					//cout << int_result << endl;
				}
			
		}
		
	for(int i=1;i<=k;i++)
	{
	node* cursor=int_result.tail_ptr;
	node* added_node=new node;
	
	int_result.tail_ptr = added_node;
	cursor->next = added_node;
	added_node->next = nullptr;
	added_node->prev = cursor;
	added_node->data='0';
	int_result.digits++;
	}
	k++;
	product+=int_result;	
	keeptrack=0;
}
if ((a.positive == true && b.positive == false) || (a.positive == false && b.positive == true))
{
	product.positive = false;
}

	return product;
	
}


big_number factorial(const big_number& a)
{
	big_number answer;
	return answer;
}



