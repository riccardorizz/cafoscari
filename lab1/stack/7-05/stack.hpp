/*header file che contiene le dichiarazioni

*/
class stack{
    public:
        stack();
        stack(const stack& s);
        ~stack(); //distruttore
        void push(int x);
        void pop();
        int top() const;
        bool isEmpty() const;

    private:
        struct Impl; //la definizione è dentro il file cpp che implementa le liste
        Impl* pimpl;
};