# ifndef SeqList_H
# define SeqList_H
    const int MaxSize = 10;
    class SeqList{
        public:
            SeqList(){length=0;};
            SeqList(int a[],int n);
            ~SeqList(){};
            void Insert(int i,int x);
            int Delete(int i);
            int Locate(int x);
            void PrintList();
            int Length();
        private:
            int data[MaxSize];
            int length;
    };
# endif