#include <iostream>
#include <math.h> 
#include <vector>

using namespace std;

void FindOptimalPath_InTriangle();
void SumPath_InTriangle(vector<int>& Trg, vector<int>& Sum);

int main()
{
    setlocale(LC_ALL, "Ru");
    FindOptimalPath_InTriangle();
}




void FindOptimalPath_InTriangle()
{
    int height = 100, size = 0; // height - глубина дерева, n - ширина
    
    
    while (height > 30)
    {
        cout << "Введите высоту двоичного дерева, до 30\n";
        cin >> height;
    }

    vector <int> NumLeaves(height);
    for (int i = 0; i < height - 1; i++)
    {
        size = size * 2 + 2;
        NumLeaves[i + 1] = size;
    }
    for (int i = 0; i < height; i++)
        cout << "NumLeaves[i] = " << NumLeaves[i] << "\n";

    cout << "size " << size << endl;
    vector <int> Triangle(size);
    vector <int> SumPath(size);
    //======= Completion arrey ======= Заполнение
    for (int i = 0; i < size; i++)
        Triangle[i] = rand() % 10;

    cout << "Vector\n";
    for (int i = 0; i < size; i++)
        cout << Triangle[i] << " ";

    SumPath_InTriangle(Triangle, SumPath);



    cout << "Vector\n";
    for (int i = 0; i < size; i++)
        cout << Triangle[i] << " ";
    cout << "\n\nSum\n";
    for (int i = 0; i < size; i++)
        cout << Triangle[i] << " ";

    /*cout << "Triangle[min] = " << Triangle[0] << endl;
    cout << "Triangle[max] = " << Triangle[size-1];*/

}

void SumPath_InTriangle(vector<int>& Trg, vector<int>& Sum)
{
    int n = Trg.size(), count = 0;
    Sum[0] = Trg[0];
    for (int i = 1; i < n; i++)
    {
        cout << "in if i = " << i << endl;
        if (count % 2 == 0)
        {
            Sum[i] = Trg[i] + Trg[(i - 1) / 2];
        }
        else
        {
            Sum[i] = Trg[i] + Trg[(i - 2) / 2];
        }
        count++;
    }
}
