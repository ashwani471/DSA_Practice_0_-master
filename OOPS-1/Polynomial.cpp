class Polynomial{
   int *degCoff;
   int capacity;

   Polynomial(){
    degCoff = new int[2];
    capacity = 1;
   }

   Polynomial(Polynomial const &p){
    // this->degCoff = p.degCoff;   shallow copy
    // Deep copy
    int *newDegCoff = new int[capacity];
    for(int i = 0 ; i<p.capacity ; i++){
        newDegCoff[i] = p.degCoff[i];
    }
    degCoff = newDegCoff;
   }

   void setCoeffient(int deg , int coef){
    if(deg>capacity){
        int newCapacity = deg;
        int *newdeg = new int[newCapacity+1];
        
    }
   }
};