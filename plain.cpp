#define <iostream>
#define size 100000;

class vector{
   private:
        int max_size=size;
        int arr[max_size];
        int ptr=-1;
    public:
         vector(){

         }
        void push_back();
        void pop_back();
        int top();
};

void vector::push_back(int x){
    arr[ptr+1]=x;
    ptr++;
}
void vector::pop_back(){
    ptr--;
}
int vector::top(){
    if(ptr==-1) return -1;
    return arr[ptr];
}