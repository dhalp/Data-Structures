#include "big_number.h"
#include <string>
//#include "doubly_linked_list.h"

using namespace std;

// default constructor, creates a 69
big_number::big_number()
{

    head_ptr=tail_ptr= new node;
    head_ptr->next=tail_ptr->prev=nullptr;
    add_node(head_ptr, tail_ptr, '6');   
    digits++;
    add_node(head_ptr, tail_ptr, '9');
    digits++;
    positive = true;
    base = 10;
}

// int constructor; create big_number from base 10 integer
big_number::big_number(int i)
{
   /* head_ptr=tail_ptr= new node;
    head_ptr->next=tail_ptr->prev=nullptr;
    digits = 0;
    positive = true;
    base = 10;
    if (i < 0)
    {
        positive = false;
        i = i* -1;
    }
    char c = '0';
    while (c>0)
    {
        c = i%10 + '0';
        add_node(head_ptr, tail_ptr, c);
        digits++;
    }
    */ //string x = to_string(i);
   /* cout << x << " &" << i << endl;
    int j = 0;
    if (x[0] == '-')
    {
        positive = false;
        j++;
    }
    else positive = true;

    while (j<x.length())
    {
        add_node(head_ptr, tail_ptr, x[j]);
        digits++;
        j++;
    }
    */
{
    base=10;
    if (i<0)
    {
        positive=false;
        i=abs(i);
    }
    else 
    positive=true;
    
    digits=0;
    int tmp;
    tmp=i;
    while (tmp !=0 && tmp >= 1) 
        {
            tmp /= 10; 
            digits++;
        }
        
    unsigned int datas;
    
    int tmptwo=i;
    int hdtrck=1;

    while (tmptwo!=0)
    {
        node* added_node = new node;
        
        datas=tmptwo%10;
        tmptwo=tmptwo/10;
        datas='0'+datas; 
        
        
        if (hdtrck==1)
        {
            head_ptr=tail_ptr = new node; 
            head_ptr->next=tail_ptr->prev=nullptr;          
            head_ptr->data=datas;
            hdtrck++;
        }
    
        else if (hdtrck!=1)
        {
            added_node->next = head_ptr;
            added_node->prev = nullptr;
            head_ptr->prev = added_node;
            head_ptr = added_node;
            added_node->data = datas;
        }
    }

    if (i==0) 
    {
        head_ptr=tail_ptr=nullptr;
        add_node(head_ptr,tail_ptr, '0');
    }
}

}

// copy constructor, creates a deep copy of m
big_number::big_number(const big_number& m)
{
    head_ptr=tail_ptr= new node;
    head_ptr->next=tail_ptr->prev=nullptr;

    copy_list(m.head_ptr, head_ptr, tail_ptr);
    
    positive = m.positive;

    base = m.base;

    digits = m.digits;
}

// create a big_number from a string
big_number::big_number(const string& s, unsigned int b)
{
    head_ptr=tail_ptr= new node;
    head_ptr->next=tail_ptr->prev=nullptr;

    string x = s;
    //cout << x << " and then s is: " << s << endl;   
    int j = 0;
    if (x[0] == '-')
    {
        positive = false;
        j++;
    }
    else positive = true;

    for (int k = j; k<x.length(); k++)
    {
        add_node(head_ptr, tail_ptr, x[k]);
        if (x[k] != '0') digits++;
    }
/*
    const node* cursora = head_ptr;
    while(cursora->data == '0' && cursora->next != nullptr)
    {
        cursora = cursora->next;
        digits--;
    }
 */
    base = b; 
   // cout << digits << endl;
}

// destructor
big_number::~big_number()
{
    clear_list(head_ptr, tail_ptr);

}

// assignment operator
big_number& big_number::operator=(const big_number& m)
{
	if(this == &m)
    {
        return *this;
    }
    copy_list(m.head_ptr, head_ptr, tail_ptr);
    digits = m.digits;
    positive = m.positive;
    base = m.base;

    
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

bool operator >(const big_number& a, const big_number& b)
{
    const node* cursora = a.head_ptr;
    const node* cursorb = b.head_ptr;
    if (a.positive == false && b.positive == true) return false;
    if (a.positive == true && b.positive == false) return true;
    if (a.digits != b.digits)
    {
        //cout<< "here" <<endl;   
        if (a.digits > b.digits) return true;
        else if (a.digits < b.digits) return false;
    } 
    if (a.positive == false && b.positive == false)
    {
        while (cursora != nullptr && cursorb != nullptr)
        {
            //cout<<"here2"<<endl;    
            if ((cursora->data) > (cursorb->data)) return false;
            if ((cursora->data) < (cursorb->data)) return true;
            if ((cursora->data) == (cursorb->data))
            {   
                cursora = cursora->next;
                cursorb = cursorb->next;
            }
        }
    }
    while (cursora != nullptr && cursorb != nullptr)
    {
        //cout<<"here2"<<endl;    
        if ((cursora->data) > (cursorb->data)) return true;
        if ((cursora->data) < (cursorb->data)) return false;
        if ((cursora->data) == (cursorb->data))
        {   
            cursora = cursora->next;
            cursorb = cursorb->next;
        }
    }
    return false;
	/*if (a.positive == false && b.positive == true) return false;
    else if(a.positive == true && b.positive == false) return true;
    const node* cursora = a.head_ptr;
    const node* cursorb = b.head_ptr;
    int adig = a.digits;
    int bdig = b.digits;
    while(cursora->data == '0' && cursora->next != nullptr)
    {
        cursora = cursora->next;
        adig--;
    
        cout<< "adig is: " << adig << endl;
    }
     while(cursorb->data == '0' && cursorb->next != nullptr)
    {
        cursorb = cursorb->next;
        bdig--;
        cout<< "bdig is: " << bdig << endl;
    }

/*
    if (adig != bdig)
    {
        if (adig > bdig) return true;
        
        else if (adig < bdig) return false;
    }
  */
   /* if (adig > bdig) return true;
    if (adig == 1)
    {
        //cout<<a.head_ptr->data <<"you got me" << endl;
        if ((a.head_ptr-> data) > (b.head_ptr-> data)) return true;
        else
        {
            cout << "this is 1"<< endl;
            return false;
        } //if (cursora->data < cursorb->data) return false;
    }
    while (cursora-> next != nullptr)
    { 
        if ((cursora-> data) > (cursorb-> data)) return true;
        else if ((cursora-> data) < (cursorb-> data))
        {
            cout<< "this is 2"<<endl;
            return false;
        } 
        cursora = cursora->next;
        cursorb = cursorb->next;
    }
    cout << "this is 3"<< endl;
    return false;
    */
    //cout << "we are here" << endl;

}

bool operator >=(const big_number& a, const big_number& b)
{
	if(a > b || a == b) return true;
    return false;
}

bool operator <(const big_number& a, const big_number& b)
{
    if(a > b || a == b) return false;

    return true;
}
			
bool operator <=(const big_number& a, const big_number& b)
{
    if(a < b || a == b) return true;
    return false;
}
			
bool operator==(const big_number& a, const big_number& b)
{
    const node* cursora = a.head_ptr;
    //cout << "a data: " << cursora->data << endl;
    const node* cursorb = b.head_ptr;
    if (a.positive != b.positive) return false;
    if (a.digits != b.digits)
    {
        return false;
    } 

    while (cursora != nullptr && cursorb != nullptr)
    {
        //cout<<"here2"<<endl;    
        if ((cursora->data) != (cursorb->data)) return false;
        cursora = cursora->next;
        cursorb = cursorb->next;

    }
	return true;
}
	
bool operator!=(const big_number& a, const big_number& b)
{
	if (a == b) return false;
    return true;
}

ostream& operator <<(ostream& out, const big_number& n)
{
    if(n.positive==false)
    {   
        out<< '-';
    }                        
    const node* cursor = n.head_ptr;
    while (cursor != nullptr)
    {
        out << cursor-> data;
        cursor = cursor->next;
    }
	return out;
}

istream& operator >>(istream& in, big_number& n)
{
	string s;
    in>>s;
    big_number temp(s,10);
    n=temp;

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

big_number operator/(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator%(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number factorial(const big_number& a)
{
	big_number answer;
	return answer;
}


