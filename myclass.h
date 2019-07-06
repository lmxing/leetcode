#ifndef MYCLASS_H
#define MYCLASS_H

class Myclass {
    public:
        static Myclass* getInstance();

    private:
        Myclass(){}
        Myclass(Myclass const&){}
        Myclass& operator=(Myclass const&){}
        static Myclass* m_instance;
};

#endif // MYCLASS_H
