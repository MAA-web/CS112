#include <iostream>
using namespace std;

class gDamWords {
public:
    char * theWords = new char[50]();
    int arr_size = 50;
    void setTheWords(char *a){theWords = a;}
    char* getTheWords() const {return theWords;}

    inline gDamWords() { // default
        theWords[0] = 'A'; theWords[1] = 'B';theWords[2] = 'C';theWords[3] = 'D';theWords[4] = 'E';theWords[5] = 'F'; // hard coding to avoid pointer pointing to a random string literal
    };
    explicit gDamWords(int len) { // length
        char * b = new char[len]();
        theWords = b;
        arr_size = len;
    }
    explicit gDamWords(char *a) { // string literal
        int lena = 0;
        for (int i = 0; a[i] != '\0'; ++i)lena++;
        theWords = a;
        arr_size = lena + 1;
    }
    inline ~gDamWords() {
        cout<<"\ndestructor called ==>> "<<theWords<<"\n";
        delete [] theWords;

    }


    [[nodiscard]]int length() const { // returns length of string
        int arr_length = 0;
        for (int i = 0; theWords[i] != '\0'; ++i)arr_length = i + 1;
        return arr_length;
    }
    [[nodiscard]] inline int size() const { // return slots occupied by string
        return arr_size;
    }
    inline char &operator[](int i) const { // [] operator, index operator
        return theWords[i];         // returns reference
    }
    gDamWords operator()(int a, int b) { // operator ()
        gDamWords c(arr_size);
        for (int i = a; i <= b; ++i) {
            c.theWords[i - a] = this->theWords[i];
        }
       return c;
    }
    gDamWords operator+ (const gDamWords& c) const{ // operator +
        char * temp = new char[this->length() + c.length()];
        for (int i = 0; i < this->length(); i++) {
            temp[i] = (*this)[i];
        }
        for (int i = 0; i < c.length(); i++) {
            temp[c.length() + i] = c[i];
        }
        temp[this->length() + c.length()] = '\0';
        gDamWords d(temp);
        return d;
    }

    gDamWords &operator= (const gDamWords& f) { // operator =
        if (this != &f) {
            char* newWords = new char[f.length() + 1];
            for (int i = 0; i < f.length(); i++) {
                newWords[i] = f.theWords[i];
            }
            newWords[f.length()] = '\0';
            theWords = newWords;
            arr_size = f.length() + 1;
        }
        return *this;
    }

    void operator+= (const gDamWords& f) { // operator +=
        char * temp = new char[this->length() + f.length() + 1]();
        for (int i = 0; i < this->length(); ++i) {
            temp[i] = this->theWords[i];
        }
        for (int i = 0; i < f.length(); i++) {
            temp[this->length() + i] = f.theWords[i];
        }
        temp[this->length() + f.length()] = '\0';
        this->arr_size = this->length() + f.length() + 1;
        this->theWords = temp;
    }

    inline bool operator==(const gDamWords& c) const { // operator ==
        return (this->theWords == c.theWords);
    }

    inline bool operator!= (const gDamWords& c) const { // operator !=
        return (this->theWords != c.theWords);
    }

    gDamWords operator<<(int cut) { // operator <<
        int length = this->length();
        gDamWords c(50);
        for (int i = 0; i < cut; ++i) { // copies over first half
            c[i] = this->theWords[i];
        }
        char * d = this->theWords;
        this->theWords = new char [arr_size]();
        for (int i = 0; i < length - cut; ++i) { // copies over the second half
            this->theWords[i] = d[i + cut];
        }
        return c;
    }

    gDamWords operator>>(int cut) { // operator >>
        int length = this->length();
        gDamWords c(50);
        for (int i = 0; i < cut; ++i) { // copies over first half
            c[i] = this->theWords[length - i - 1];
        }
        char * d = this->theWords;
        this->theWords = new char [arr_size]();
        for (int i = 0; i < length - cut; ++i) { // copies over second half
            this->theWords[i] = d[i];
        }
        return c;
    }

    bool operator>(const gDamWords &b) const { // operator >
        int length = this->length();
        int int_a{0},int_b{0};
        if(length>b.length())return true;
        else if(length<b.length())return false;
        else {
            if(this->theWords == b.theWords)return false;
            for (int i = 0; i < length; ++i)((int)this->theWords[i] > (int)b.theWords[i]) ? int_a++ : int_b++; // comparing ascii values lower is higher order alphabet
        }
        return (int_a < int_b);
    }

    bool operator<(const gDamWords &b) const { // operator <>>
        int length = this->length();
        int int_a{0},int_b{0};
        if(length<b.length())return true;
        else if(length>b.length())return false;
        else {
            if(this->theWords == b.theWords)return false;
            for (int i = 0; i < length; ++i)((int)this->theWords[i] > (int)b.theWords[i]) ? int_a++ : int_b++; // comparing ascii values lower is higher order alphabet
        }
        return !(int_a < int_b);
    }

    friend ostream &operator<< (ostream &o, gDamWords const &c){return o << c.theWords;} // stream insertion

    friend istream &operator>> (istream &i, gDamWords &c){ // stream insertion
        string temp;
        cout<<"Type the string literal: ";                 // user prompt
        i >> temp;
        for (int j = 0; temp[j] != '\0'; j++) {c.arr_size = j + 1;}
        c.theWords = new char[c.arr_size]();
        for (int j = 0; temp[j] != '\0'; j++) {

            c.theWords[j] = temp[j];
        }
        c.theWords[c.arr_size] = '\0'; // make the last bit null
        return i;                      // return istream object
    }
};

// [] + += = == != << >> cout<< cin>>
int main() {
    gDamWords a("ABCDEF");
    cout<<"a -> "<<a;
    cout<<"\n\tlength a: "<<a.length();
    cout<<"\n\tsize: "<<a.size();
    gDamWords bb;
    cout<<"\nbb -> "<<bb;
    cout<<"\n\tlength: "<<bb.length();
    cout<<"\n\tsize: "<<bb.size();
    gDamWords b(5);
    cout<<"\nb -> "<<b;
    cout<<"\n\tlength: "<<b.length();
    cout<<"\n\tsize: "<<b.size();
    gDamWords c("123456");
    cout<<"\nc ->"<<c;
    cout<<"\n\tlength: "<<c.length();
    cout<<"\n\tsize: "<<c.size()<<"\n";
    cout<<"<---------------------------->"<<endl;

    gDamWords d;// = a+c;
    d = a+c;
    cout<<"    d = a + c -> "<<d<<"\n";
    cout<<"\nd -> "<<d;
    cout<<"\n\tlength: "<<d.length();
    cout<<"\n\tsize: "<<d.size()<<"\n";
    cout<<"<---------------------------->"<<endl;

    cin>>d;
    cout<<"d -> "<<d;
    cout<<"\n\tlength: "<<d.length();
    cout<<"\n\tsize: "<<d.size()<<"\n";
    cout<<"<---------------------------->"<<endl;

    cout<<"c -> "<<c<<"\n";
    d += c;
    cout<<"    d += c -> "<<d;
    cout<<"\n<---------------------------->"<<endl;

    gDamWords e1("ABCDEF");
    gDamWords e2("ABCDEF");
    cout<<"\ne1 -> "<<e1;
    cout<<"\ne2 -> "<<e2;
    if (e1 == e2) {
        cout<<"\n    e1 and e2 are equal!\n";
    }
    else {
        cout<<"\n    e1 and e2 are not equal!\n";
    }
    cout<<"<---------------------------->"<<endl;

    c = e1 << 1;
    d = e2 >> 3;
    cout<<"     Left shift operator (c , e1): "<<c<<" , "<<e1<<"\n";
    cout<<"     right shift operator (d , e2): "<<d<<" , "<<e2<<"\n";
    cout<<"c -> "<<c;
    cout<<"\nd -> "<<d;
    cout<<"\n<---------------------------->"<<endl;

    c = e2(0, 3);
    cout<<"    sub-string operator (0, 3) c -> : "<<c<<"\n";
    cout<<"<---------------------------->"<<endl;

    c[1] = 'b';
    cout<<"e2 -> "<<e2;
    cout<<"\n    c[1] = 'b': "<<c;
    if (e2 > c)cout<<"\n    > e2 is greater than c\n";
    if (!(e2 < c))cout<<"    < c is smaller than e2\n";
    if (c != e2)cout<<"    != c and e2 are not equal";
    cout<<"\n<---------------------------->"<<endl;
    gDamWords L ("hello");
    gDamWords l ("hello");
    cout<<"\nL -> "<<L;
    cout<<"\nl -> "<<l;
    cout<<"\n    L > l : "<< (L > l) <<endl;
    return 0;
}
