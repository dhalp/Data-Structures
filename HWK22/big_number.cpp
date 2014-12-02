#include "big_number.h"

using namespace std;

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
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator*= (const big_number& b)
{
	return *this;
}

// set value to original value - b; return answer in original number's base
big_number& big_number::operator-= (const big_number& b)
{
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
	return *this;
}

// prefix decrement
big_number& big_number::operator--()
{
	return *this;
}

// assume same base, |*this| > |b|
big_number& big_number::sum(const big_number& b)
{
	return *this;
}

// assume same base, |*this| > |b|
big_number& big_number::diff(const big_number& b)
{
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
	big_number answer;
	return answer;
}

big_number operator-(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator*(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number factorial(const big_number& a)
{
	big_number answer;
	return answer;
}



