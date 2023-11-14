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

    return 0;
}

void FindOptimalPath_InTriangle()
{
    int height = 100, size = 0, j; 
    
    while (height > 30)
    {
        cout << "Введите высоту двоичного дерева, до 30\n";
        cin >> height;
    }

    // Листья!!!
    vector <int> NumLeaves(height);
    NumLeaves[0] = 1;
    for (int i = 0; i < height - 1; i++)
    {
        size = size * 2 + 2;
        NumLeaves[i + 1] = size + 1;
    }
    size++;

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

    // ---------------    Func    --------------------
    SumPath_InTriangle(Triangle, SumPath);

    // =========== Enter in console =============
    cout << "\nVector\n";
    j = 0;
    for (int i = 0; i < height; i++)
    {
        while (j < NumLeaves[i])
        {
            cout << Triangle[j] << " ";
            j++;
        }
        cout << endl;
    }

    cout << "\nSum\n";
    j = 0;
    for (int i = 0; i < height; i++)
    {
        while (j < NumLeaves[i])
        {
            cout << SumPath[j] << " ";
            j++;
        }
        cout << endl;
    }
}

void SumPath_InTriangle(vector<int>& Trg, vector<int>& Sum)
{
    int n = Trg.size(), count = 0;
    Sum[0] = Trg[0];
    for (int i = 1; i < n; i++)
    {
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
