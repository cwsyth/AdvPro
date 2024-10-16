/**
 * Profiler example
 * Scalar product (or dot product) of two vectors of real numbers
 *
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const unsigned N = 10000;
const unsigned REPE = 10000;

//typedef float VectC[N];
typedef vector<float> VectC;

float RandNumber(float max);
void FillVec(VectC &v, unsigned tam);
float DotProduct(VectC &v1, VectC &v2, unsigned tam);

int main(void)
{
    VectC v1(N),v2(N);
    float c;
    
    for(unsigned i = 0; i < REPE; i++)
    {
        FillVec(v1, N);
        FillVec(v2, N);
    
        c = DotProduct(v1, v2, N);
    }
    cout << "Scalar product of v1 and v2: " << c << endl;
    
    return 0;
}

float RandNumber(float max)
{
    return max*rand()/(RAND_MAX+1.0);
}

void FillVec(VectC &v, unsigned tam)
{
    for(unsigned i = 0; i < tam; i++)
    {
        v[i] = RandNumber(10);
    }
}

float DotProduct(VectC &v1, VectC &v2, unsigned tam)
{
    float c = 0;
    
    for(unsigned i = 0; i < tam; i++)
    {
        c = c + v1[i] * v2[i];
    }
    return c;
}

