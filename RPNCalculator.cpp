template<class T>
class RPNCalculator
{
    private:
        Stack<T> stack;
        std::ofstream logFile;

    public:
    RPNCalculator();
    ~RPNCalculator();

    //binary operators 
    void add();
    void subtract();
    void multiply();
    void divide();

    // squares the current value
    void square();

    // negates, i.e. 3 becomes -3
    void negate();

    // tests to see if there are elements on the stack
    bool isEmpty();

    // clears out the stack
    void clear();

    // returns the topmost value
    T value();

    // returns the topmost value and pops it off the top
    T pop();
};