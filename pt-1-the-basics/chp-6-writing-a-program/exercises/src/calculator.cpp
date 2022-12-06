
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

#include "../headers/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{ // keyword class here indicates a user-defined type
public:
    // kind and value are members or type attributes
    char kind;        // what kind of token
    double value;     // for numbers: a value

    // Token type 1:
    Token(char ch)    // make a Token from a char e.g. + * / - ( )
        :kind(ch), value(0) { } // default value for those chars above is 0, which will have to be be ignored
      // OR type 2:
    Token(char ch, double val)    // make a Token from a char and a double
        :kind(ch), value(val) { } // default kind is arbitrary character e.g. '8',
                                  // and the value is the numeric literal entered
                                  // by user e.g 2, 0.3, 3.14, 42 ...
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin e.g. Token_stream ts
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback(). Cool, I get this.
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
// ===============
Token_stream::Token_stream()    // this is the member function called in Token_stream class. Note that it is outside the class.
    :full(false), buffer(0) { } // 1. no Token in buffer is default for each new instanciation of this class/type
                                // 2. :full(false), buffer(0) is an example of initialising member variables before the body of the constructor executes.
                                //    the : is not tied to the full(false) - :buffer(0), full(false) has the same effect as :full(false), buffer(0). The
                                //    : is how to start the initialisations
                                // 3. Here, this constructor has no body, note the { }.

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer"); // note that the member function has access to the class
                                                     // member 'full' although it is defined in the scope of
                                                     // Token_stream class. Note same in the get() member
                                                     // function

    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full. I get this too.
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case '=':    // for "print"
        case 'q':    // for "quit"
        case '{': case '}': case '(': case ')':
        case '+': case '-': case '*': case '/': case '!':
            return Token(ch);        // let each character represent itself.
                                     // return Token(ch) for all above character
                                     // input cases
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('n', val);   // let 'n' represent "a number"
            // no break necessary after return as code wouldn't reach that line
        }
        default:
            error("Bad token");
            break;
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() so that primary(), term() and expression() can call them

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression().
                        // function declaration giving another function access to call it.

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case '{':    // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
            return d;
    }
    case 'n':            // we use 'n' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
        break;
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    double val;

    cout << "+-------------------+\n";
    cout << "| Simple Calculator |\n";
    cout << "+-------------------+\n\n";
    cout << "Usage:\n";
    cout << "  - Available operations: + - * /\n";
    cout << "  - End each expression with =\n";
    cout << "  - Sample expressions: (4+5)*2=, 8-3=, (6.2/1.3)*(5+2)=\n";
    cout << "  - Press q to quit.\n\n";

    while (cin) {
        Token t = ts.get(); // inside get() is the cin>>variable

        if (t.kind == 'q') break; // 'q' for quit
        if (t.kind == '=')        // ';' for "print now"
            cout << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
